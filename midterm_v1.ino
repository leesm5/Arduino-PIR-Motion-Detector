int ledPinRed = 13; //set pins for leds
int ledPinGreen = 12;
int ledPinYellow = 11;
int pirPin = 7; //set pin for pir motion detector
//int pirValue;
int i = 0;
int buzzerPinA = 3; //set pins for buzzers
int buzzerPinB = 5;
int frequencyA = 2400; //set frequency of buzzers
int frequencyB = 8000;

//210 = 1 second
int thr1 = 300; //define thresholds to change states
int thr2 = 600;
int thr3 = 900;
int thr4 = 1200;
int thr5 = 1500;
int thr6 = 9000;



void setup() {
  Serial.begin(9600); //initilaize serial output

  pinMode(ledPinRed, OUTPUT); //initialize led pins as outputs
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(buzzerPinA, OUTPUT); //initialize buzzer pins as outputs
  pinMode(buzzerPinB, OUTPUT);
  pinMode(pirPin, INPUT); // initialize pir pin as input

  digitalWrite(ledPinRed, LOW); //set all led pins to low
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinYellow, LOW);

}

void loop() {

  //if pir sensor detects motion
  if (digitalRead(pirPin) == 1) {
    //while motion continuosly detected
    while (digitalRead(pirPin) == 1) {
      i++;
      Serial.print(i);
      Serial.print("\n");
      //if below first threshold
      if (i < thr1) {
        digitalWrite(ledPinRed, 0);
        digitalWrite(ledPinGreen, 1);
        digitalWrite(ledPinYellow, 1);
        noTone(buzzerPinA);
        noTone(buzzerPinB);
      }
      //if above first threshold and below second threshold
      else if (i > thr1 && i < thr2) {
        digitalWrite(ledPinRed, 0);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 1);
        noTone(buzzerPinA);
        noTone(buzzerPinB);
      }
      //if above second threshold and below third threshold
      else if (i > thr2 && i < thr3) {
        digitalWrite(ledPinRed, 1);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 1);
        noTone(buzzerPinA);
        noTone(buzzerPinB);
      }
      //if above third threshold and below fourth threshold
      else if (i > thr3 && i < thr4) {
        digitalWrite(ledPinRed, 1);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 0);
        noTone(buzzerPinA);
        noTone(buzzerPinB);
      }
      //if above fourth
      else if (i > thr4) {
        digitalWrite(ledPinRed, 1);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 0);
        tone(buzzerPinA, frequencyA);
        tone(buzzerPinB, frequencyB);
      }
    }

  }
  //if no motion detected
  else if (digitalRead(pirPin) == 0) {
    //Serial.print("low\n");
    i = 0;
    digitalWrite(ledPinGreen, 1);
    digitalWrite(ledPinRed, 0);
    digitalWrite(ledPinYellow, 0);
    noTone(buzzerPinA);
    noTone(buzzerPinB);
    //Serial.print(digitalRead(pirPin));
  }

}



