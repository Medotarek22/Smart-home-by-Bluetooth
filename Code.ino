#include <SoftwareSerial.h>

const int bluetoothTx = 2;
const int bluetoothRx = 3;
const int relayLight = 6;
const int relayFan = 8;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
String voice;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(relayLight, OUTPUT);
  pinMode(relayFan, OUTPUT);
  digitalWrite(relayLight, HIGH);
  digitalWrite(relayFan, HIGH);
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();

    if (command == '1') {
      digitalWrite(relayLight, LOW);
      bluetooth.println("Light ON");
    } else if (command == '2') {
      digitalWrite(relayLight, HIGH);
      bluetooth.println("Light OFF");
    } else if (command == '3') {
      digitalWrite(relayFan, LOW);
      bluetooth.println("Fan ON");
    } else if (command == '4') {
      digitalWrite(relayFan, HIGH);
      bluetooth.println("Fan OFF");
    } else if (command == '5') {
      digitalWrite(relayFan, LOW);
      bluetooth.println("Fan ON");
      digitalWrite(relayLight, LOW);
      bluetooth.println("Light ON");
    } else if (command == '6') {
      digitalWrite(relayFan, HIGH);
      bluetooth.println("Fan OFF");
      digitalWrite(relayLight, HIGH);
      bluetooth.println("Light OFF");
    }
  }

  while (Serial.available()) {
    char c = Serial.read();
    if (c == '#') {
      break;
    }
    voice += c;
  }

  if (voice.length() > 0) {
    if (voice == "*turn on light") {
      digitalWrite(relayLight, LOW);
      bluetooth.println("Light ON");
    } else if (voice == "*turn off light") {
      digitalWrite(relayLight, HIGH);
      bluetooth.println("Light OFF");
    } else if (voice == "*turn on fan") {
      digitalWrite(relayFan, LOW);
      bluetooth.println("Fan ON");
    } else if (voice == "*turn off fan") {
      digitalWrite(relayFan, HIGH);
      bluetooth.println("Fan OFF");
    } else if (voice == "*turn on all") {
      digitalWrite(relayFan, LOW);
      digitalWrite(relayLight, LOW);
      bluetooth.println("Fan ON and Light ON");
    } else if (voice == "*turn off all") {
      digitalWrite(relayFan, HIGH);
      digitalWrite(relayLight, HIGH);
      bluetooth.println("Fan OFF and Light OFF");
    }
    voice = "";
  }
}
