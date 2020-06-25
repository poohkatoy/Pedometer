#include <TM1637.h>

const int DIO = 3;
const int CLK = 2;

#define trigPin1 4
#define echoPin1 5
#define trigPin2 7
#define echoPin2 6

TM1637 sevenSegment(CLK, DIO);

int counter = 0;
int currentState1 = 0;
int previousState1 = 0;
int currentState2 = 0;
int previousState2 = 0;
int buzzer = 8;
int ledPin = 13;
int button = 12;

boolean currentButton = LOW;
boolean lastButton = LOW;
boolean toggle = false;

void setup() {
  sevenSegment.init();
  Serial.begin (9600);
  pinMode(DIO, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
    sevenSegment.display(counter);
    int duration1, distance1;
    digitalWrite(trigPin1, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = (duration1/2) / 29.1;

    int duration2, distance2;
    digitalWrite(trigPin2, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;

    if (distance1 <= 30){
    currentState1 = 1;
    }
    else {
    currentState1 = 0;
    }
    delay(100);
    if(currentState1 != previousState1){
        while(currentState1 == 1) {
            int duration2, distance2;
            digitalWrite(trigPin2, LOW); 
            delayMicroseconds(2); 
            digitalWrite(trigPin2, HIGH);
            delayMicroseconds(10); 
            digitalWrite(trigPin2, LOW);
            duration2 = pulseIn(echoPin2, HIGH);
            distance2 = (duration2/2) / 29.1;
            if (distance2 <= 30){
            currentState2 = 1;
            }
            else {
            currentState2 = 0;
            }
            delay(100);
            if(currentState2 != previousState2){
                if(currentState2 == 1) {
                counter = counter+1;
                sevenSegment.display(counter);
                delay(1000); 
                }
            return;
            }
        }
    }
    if (distance2 <= 10){
    currentState2 = 1;
    }
    else {
    currentState2 = 0;
    }
    delay(100);
    if(currentState2 != previousState2){
        while (currentState2 == 1) {
            int duration2, distance2;
            digitalWrite(trigPin2, LOW); 
            delayMicroseconds(2); 
            digitalWrite(trigPin2, HIGH);
            delayMicroseconds(10); 
            digitalWrite(trigPin2, LOW);
            duration2 = pulseIn(echoPin2, HIGH);
            distance2 = (duration2/2) / 29.1;
            if (distance2 <= 30){
            currentState2 = 1;
            }
            else {
            currentState2 = 0;
            }
            delay(100);
            if(currentState2 != previousState2){
                if(currentState2 == 1) {
                counter = counter-1; 
                sevenSegment.display(counter);
                delay(1000); 
                }
            return;
            }
        }
    }
    if (counter < 0){
        counter = 0;
    }
    if (counter < 21){
        digitalWrite(ledPin, LOW);
    }
    if (counter >= 21) {
        tone(buzzer, 400, 2000);
        sevenSegment.display(counter);
        digitalWrite(ledPin, HIGH);
    }
    currentButton = digitalRead(button);
    if(currentButton == HIGH && lastButton == LOW){
        toggle = !toggle;
        if(toggle == true){
            counter = 0;
            toggle = false;
        }
        lastButton = currentButton;
    }
    if(currentButton == LOW && lastButton == HIGH){
            counter = 0;
    }
        lastButton = currentButton;
 }