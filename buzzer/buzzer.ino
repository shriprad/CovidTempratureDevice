
static const int buzzerPin = 6;    // set the variable "buzzerPin" to pin 12
void setup(void) {
  pinMode(buzzerPin, OUTPUT);       // set the buzzerPin as output
}

void loop() {
  beep();                           // execute the "beep" function
  delay(400);                      // pause 5s
}

void beep() {
  tone(buzzerPin, 4000,200);        // give a tone on the buzzerPin, at 196hz for, 200ms  
}
