#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);  // RX, TX pins for Bluetooth communication
const int flexPin = A0;           // Analog pin for flex sensor

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  int flexValue = analogRead(flexPin);

  // Map the flex sensor value to a desired range (adjust these values based on your sensor)
  int mappedValue = map(flexValue, 200, 800, 0, 100);

  // Print the flex sensor value to the Serial Monitor
  Serial.print("Flex Sensor Value: ");
  Serial.println(mappedValue);

  // Recognize different words based on the mapped values
  switch(mappedValue) {
    case 0 ... 10:
      bluetooth.println("Word: UP");
      break;
    case 11 ... 20:
      bluetooth.println("Word: DOWN");
      break;
    case 21 ... 30:
      bluetooth.println("Word: LEFT");
      break;
    case 31 ... 40:
      bluetooth.println("Word: RIGHT");
      break;
    case 41 ... 50:
      bluetooth.println("Word: YES");
      break;
    case 51 ... 60:
      bluetooth.println("Word: NO");
      break;
    case 61 ... 70:
      bluetooth.println("Word: HELLO");
      break;
    case 71 ... 80:
      bluetooth.println("Word: GOODBYE");
      break;
    case 81 ... 90:
      bluetooth.println("Word: THANK YOU");
      break;
    case 91 ... 100:
      bluetooth.println("Word: SORRY");
      break;
    default:
      bluetooth.println("Word: UNKNOWN");
      break;
  }

  delay(1000);  // Adjust the delay based on your application's requirements
}
