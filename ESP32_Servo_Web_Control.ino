#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "ESP32-Servo";
const char* password = "12345678";

WebServer server(80);
Servo myServo;

const int servoPin = 18;
const int greenLED = 25;
const int redLED = 26;

String createPage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP32 Servo Control</title>
</head>

<body style="text-align:center;font-family:Arial;">
  <h1>ESP32 Servo Control</h1>

  <p>
    <a href="/open">
      <button style="font-size:25px;padding:15px 40px;">
        OPEN
      </button>
    </a>
  </p>

  <p>
    <a href="/close">
      <button style="font-size:25px;padding:15px 40px;">
        CLOSE
      </button>
    </a>
  </p>

</body>
</html>
)rawliteral";

  return page;
}

void handleRoot() {
  server.send(200, "text/html", createPage());
}

void handleOpen() {
  myServo.write(90);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);

  Serial.println("OPEN: Servo = 90 degrees");

  server.send(200, "text/html", createPage());
}

void handleClose() {
  myServo.write(0);

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);

  Serial.println("CLOSE: Servo = 0 degrees");

  server.send(200, "text/html", createPage());
}

void setup() {
  Serial.begin(115200);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  myServo.attach(servoPin);

  // Initial state: CLOSED
  myServo.write(0);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);

  // Start WiFi Access Point
  WiFi.softAP(ssid, password);

  Serial.println("WiFi Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Web server routes
  server.on("/", handleRoot);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {
  server.handleClient();
}
