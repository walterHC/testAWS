#ifndef SECRETS_H
#define SECRETS_H

#define SECRET
#define THINGNAME "ESP32"

const char WIFI_SSID[] = "Matrix545";
const char WIFI_PASSWORD[] = "#Clavesegura1732";
const char AWS_IOT_ENDPOINT[] = "ahee5r1ym27qz-ats.iot.sa-east-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUDLTdqDw/ZvHLrAxna0RcYwdLeeswDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDcwMzAyNTU1
MloXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALU/2SIKCyyWz+R6QYQj
jxaXbiNuFGcFBmVdKdBIrWdcBBbsF9yDrCMktbuUVkhhd6JNUcz4+7Zj9pkiXVXl
0diIeF4J8tXkCKU5+zdByrCwjE2n3XCiYGCDnq3htlip8+c8AYxlQrISMlCwR1PB
6EEZo51cr+W8I6H0oMfOQ2Z2BEqtHSGBng9B3GHyMfYCe6tyB16niySWopBqyX7d
SkvK1yBirRKBjqaZghHjT9yTpFbWdQZ8DJfq1iIeDxxpbe//f7Q5MBWH5MPgqs+j
Tr7ugIH75vGsboV9NOACU/7ZYtyQawP1BOM9Q6ZqX+IAwxInWXV4Bm+6nu0TvRdb
IgkCAwEAAaNgMF4wHwYDVR0jBBgwFoAUd0SeFSnHklgKOEAdypnlu/yj1OcwHQYD
VR0OBBYEFJjZrm+sVVnvVMUzs7NSOTp0QxEBMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBIF6OAwn9J35X/l39uQnXdQ2dm
FK2waqC7N8+oiCOXcMz0r92vbKjHiXq06cEas6yWMVeNlqiY8b18fBsI0SBEO4Cn
U+0ggGWAKxRY8qPiHxwx2KLJ/sm7jpadfSoW+jAwDsuojMyr1GDPmEUpDhwvIDIq
T+ODCvvXq8ukeLu7F2la7xnExzyv8w045BjHmzZE1dgPV3vXXbiGf6T6GUXZmB1M
hs0BcOVCcFxmbrFnfYTdYscAd1E0EXPQhr3zQtcMVUypmDOmoI4EW5g+w3wG+edu
c+bzOBwzi2KI6lMGpzi3aUMAgn4hdHyJCcrEUtUOrw5P7StD71Iko41uUyvv
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAtT/ZIgoLLJbP5HpBhCOPFpduI24UZwUGZV0p0EitZ1wEFuwX
3IOsIyS1u5RWSGF3ok1RzPj7tmP2mSJdVeXR2Ih4Xgny1eQIpTn7N0HKsLCMTafd
cKJgYIOereG2WKnz5zwBjGVCshIyULBHU8HoQRmjnVyv5bwjofSgx85DZnYESq0d
IYGeD0HcYfIx9gJ7q3IHXqeLJJaikGrJft1KS8rXIGKtEoGOppmCEeNP3JOkVtZ1
BnwMl+rWIh4PHGlt7/9/tDkwFYfkw+Cqz6NOvu6Agfvm8axuhX004AJT/tli3JBr
A/UE4z1Dpmpf4gDDEidZdXgGb7qe7RO9F1siCQIDAQABAoIBABGdN9vQABAARAnf
O7i8v+4hH0oAK6lrWpjFOggM2BVAYwFbRmJexX7Q1Xx6SPxVxIuYWgfCdqveARwW
s91iLUeO06vH6bqRo6ly/g/7q9gKAEiXtLR6g0U95VDeq5roQVTKhxf+y0GE9TDU
QMpKAOk6taTYWhvIceoOXQWt7OzrBzJN2bKyiqwD2tDQKkjdyKggW4khwnR4MtNj
bXRyHoO4jSaY9NH6BlD1TBKaqw/P/FeDDzZ31rvXfpBh6zZ7ZeIWqQqn19a0KBCw
IkqyUgHp5THC4lW/T3Irh24tlDktbuRPTWyRGCPbCfqojuGaePze85H7vtUpEORr
n+B4g4UCgYEA6iRCXeY6eeAJ3d2nW8umWkSl0X90mw73BYHrFDED5JyiOfEysBnc
/BiunjpXwzMLc8BzMmHjchGPFXBJho+JQ/D4y2w47QA7oLw1hxLOX/i67e6lAcpk
3AX0muJYkVPD+ZLd4ykkwsx0fEn0Q8HVU3TFqaDWALYS4smJLl+ap6MCgYEAxiuF
Ew5ADV8mWwSif02wMl4I4LhHVUkWLQz2Fn/9Nlde7BSdTQqyTqqNPDGhwBeVSXz3
85lW6ti/lHxFfys32qwpv68QmfZO2PUheT0RhJxSju5/cp0GKu/1i5Kf0PJ7tDib
WVrQEagKbF9fvWukHezjnlk49fkBkWRvVW+/WmMCgYEA22IKBS1ZESTIWef7jdkt
D1tO+xKvUTIeZjyq5QpgGW5h2mSTF8nD8zm1M3B7FtzXGCf0R/rMP+8P4AiL+9a1
yMEafI/0bqxPMnXmuZ73W5kUnSeD2D+pbTbvT8hRMCoKb+gam2PLm/IyGtq4Ulxl
44KASkX2/kebPn+TV64gnH0CgYBHGSwYZx9x7LZdJ2+JjvztRTGYNmVZYuxy41iT
P/4/9d7XgpnhHzpT4PrlIsVunsdv40cufdBiV7t8cY2Zj47thKFB5XRmWKl3S5Nj
5RYY5uDz6PuOymmBFDCbj9KI68aYJUsPJvbJrul2ck1uL2VlWy1bDZXTIjB+0nLj
S0FzEwKBgQDmhashkXQotbN+FOSpovlJ09uT4O7jd5BAz+tjPRL3PD1pWZCCgTbE
trnwKdAXx9r348rjlqp+qnGR/mCCF2Qt4v3g4ugsya3Fq6JD0frof5gHB1FHd3PF
iLAeM7chY4YUhg9BPYF5ssdyyWaRyQjPgOCZoUJ+gffQdMpMoN86IA==
-----END RSA PRIVATE KEY-----
)KEY";

#endif