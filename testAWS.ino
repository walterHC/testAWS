#include "secrets.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include <NTPClient.h>
#include "WiFi.h"

#define MQ_PIN 34
const int LED_BUILTIN = 2;
#define LED_PIN 5
#define LED_CHANNEL 0

const int frequency = 5000;
const int resolution = 8;
const int timer = 60000;  // 1 min
unsigned long lastMessageTime = 0;

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC "esp32/movil"
#define AWS_IOT_SUBSCRIBE_TOPIC "movil/esp32"

WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(256);

void connectAWS() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("w");
  }

  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.begin(AWS_IOT_ENDPOINT, 8883, net);

  // Create a message handler
  client.onMessage(messageHandler);

  Serial.println("Connecting to AWS IoT");

  while (!client.connect(THINGNAME)) {
    Serial.print("a");
    delay(100);
  }

  if (!client.connected()) {
    Serial.println("AWS IoT Timeout!");
    return;
  }

  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

  Serial.println("AWS IoT Connected!");
}

void publishMessageMovile() {
  int sensorValue = analogRead(MQ_PIN);

  [1] Get current time
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Error getting current time");
    return;
  }

  [1.1] Format current time
  char timestamp[20];
  snprintf(timestamp, sizeof(timestamp), "%04d-%02d-%02d %02d:%02d:%02d",
           timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday,
           timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);

  // [2] Send JSON data
  StaticJsonDocument<400> doc;
  JsonArray sensorsArray = doc.createNestedArray("Sensors");
  JsonObject dataObj = sensorsArray.createNestedObject();
  dataObj["timestamp"] = String(timestamp);
  dataObj["value"] = sensorValue;
  dataObj["unit"] = "ppm";
  dataObj["notes"] = "Valor normal";

  char jsonBuffer[512];  // Ajusta el tamaño del búfer si es necesario
  serializeJson(doc, jsonBuffer);

  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void messageHandler(String &topic, String &payload) {

  Serial.print("Incoming: [");
  Serial.print(topic);
  Serial.println("]");

  // Parse the JSON payload
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  int action = doc["action"];  //se espera recibir cadena
  int value = atoi(doc["value"]);  //se espera recibir un valor numerico


  value = value % 10000;

  // Escalar intensity de [0, 10000] a [0, 100]
  int scaledValue = map(intensity, 0, 10000, 0, 100);

  if (strcmp(action, "prender") == 0) {
    int pwmValue = map(scaledValue, 0, 100, 0, 255);
    ledcWrite(LED_CHANNEL, pwmValue);

  } else {
    ledcWrite(LED_CHANNEL, 0);

  }
}

void setup() {
  Serial.begin(115200);

  // Configure NTP server
  configTime(0, 0, "pool.ntp.org");

  setupLed();

  connectAWS();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // [2] PUBLISH MESSAGE
  unsigned long currentMillis = millis();
  if (currentMillis - lastMessageTime >= 60000) {  // 30000 milisegundos = 30 segundos
    publishMessageMovile();
    lastMessageTime = currentMillis;
  }

  client.loop();
  delay(1000);
}

// Setup Led
void setupLed() {
  pinMode(LED_PIN, OUTPUT);
  ledcSetup(LED_CHANNEL, frequency, resolution);
  ledcAttachPin(LED_PIN, LED_CHANNEL);
}