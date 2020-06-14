int button = 3;
 
boolean current = LOW;
boolean last = LOW;
boolean toggle = false;
 
void setup() {

  pinMode(button, INPUT);
 
  Serial.begin(9600);
 
}
 
void loop() {
 
  current = digitalRead(button);
  if (current == HIGH && last == LOW) { 
 
    toggle = !toggle;
    if (toggle == true) {
      Serial.println("Toggle on");
    } else {
      Serial.println("Toggle off");
    }
    Serial.println("Pressed");
    delay(1);
  } else if (current == LOW && last == HIGH) {
 
    Serial.println("Released");
    delay(1);
  }
  last = current;
}
