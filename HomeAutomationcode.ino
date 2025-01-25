// Pin Definitions
const int tempSensorPin = A0;   // TMP36 sensor pin
const int motorPin = 9;         // Fan (Motor) control pin
const int ledPin = 13;          // LED control pin
const int pirPin = 7;           // PIR sensor pin
const int switchPin = 4;        // Manual Switch pin

// Variables
int tempValue = 0;
float temperature = 0;
int pirState = 0;
int switchState = 0;
String command = "";  // Stores IoT command from Serial Monitor

void setup() {
  pinMode(motorPin, OUTPUT);    // Motor as output
  pinMode(ledPin, OUTPUT);      // LED as output
  pinMode(pirPin, INPUT);       // PIR sensor as input
  pinMode(switchPin, INPUT_PULLUP); // Internal Pull-up for switch

  Serial.begin(9600);  // Serial communication for IoT simulation
  Serial.println("IoT Home Automation System Initialized");
}

void loop() {
  // Read temperature sensor
  tempValue = analogRead(tempSensorPin);
  float voltage = tempValue * (5.0 / 1023.0);  // Convert analog value to voltage
  temperature = (voltage - 0.5) * 100.0;       // Corrected formula for TMP36

  // Read PIR sensor state
  pirState = digitalRead(pirPin);

  // Read switch state (0 when pressed, 1 when not pressed due to INPUT_PULLUP)
  switchState = digitalRead(switchPin);

  // **Send data to IoT Dashboard (Serial Monitor)**
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C | Motion: ");
  Serial.print(pirState == HIGH ? "Detected" : "None");
  Serial.print(" | Switch: ");
  Serial.println(switchState == LOW ? "ON" : "OFF");

  // **Fan Control (Automatic by Temperature)**
  if (temperature > 25) {  
    analogWrite(motorPin, 255);  // Turn fan ON
    Serial.println("Fan ON (Temp High)");
  } else {
    analogWrite(motorPin, 0);    // Turn fan OFF
    Serial.println("Fan OFF");
  }

  // **Light Control (Automatic by PIR)**
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn LED ON if motion detected
    Serial.println("Light ON (Motion Detected)");
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED OFF if no motion
    Serial.println("Light OFF");
  }

  // **Manual Override (Switch)**
  if (switchState == LOW) {  
    analogWrite(motorPin, 255);  // Turn fan ON manually
    digitalWrite(ledPin, HIGH);  // Turn light ON manually
    Serial.println("Fan & Light ON (Switch Pressed)");
  }

  // **IoT Control (Receive Commands from Serial Monitor)**
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');  // Read command from Serial Monitor
    command.trim();  // Remove whitespace

    if (command == "FAN ON") {
      analogWrite(motorPin, 255);
      Serial.println("Fan Turned ON via IoT");
    }
    else if (command == "FAN OFF") {
      analogWrite(motorPin, 0);
      Serial.println("Fan Turned OFF via IoT");
    }
    else if (command == "LIGHT ON") {
      digitalWrite(ledPin, HIGH);
      Serial.println("Light Turned ON via IoT");
    }
    else if (command == "LIGHT OFF") {
      digitalWrite(ledPin, LOW);
      Serial.println("Light Turned OFF via IoT");
    }
  }

  delay(1000);  // Wait 1 sec before reading again
}
