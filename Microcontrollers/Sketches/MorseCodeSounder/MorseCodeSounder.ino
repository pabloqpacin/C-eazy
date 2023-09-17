// http://www.multiwingspan.co.uk/arduino.php?page=buzzer1

// WIP

int buzzerPin = 9;
int buttonPin = 7;
int ledPin = 6;
const int toneFreq = 523;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  if (buttonState==LOW)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, toneFreq);
  } 
  else
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}
