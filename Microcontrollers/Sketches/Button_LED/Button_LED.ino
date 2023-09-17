// pabloqpacin
// 2023.09.17
// based on Elegoo: Lesson_5-Digital_Inputs


int ledPin = 9;
int buttonPin = 5;
byte ledState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(200);
  }
}
