//Scott Lee - Miami University - 8 March 2017

const int ledPinRed = 13; //set pins for leds
const int ledPinGreen = 12;
const int ledPinYellow = 11;
const int pirPin = 7; //set pin for pir motion detector
int i = 0;
const int buzzerPin = 3; //set pin for buzzer
const int frequency = 2400; //set frequency of buzzers

const int s = 210; //210 steps = 1 second
const int m = 60 * s; //60 seconds - 1 minute

//define thresholds to change states
const int thr1 = 0 * m + 3 * s;
const int thr2 = 0 * m + 5 * s;
const int thr3 = 0 * m + 8 * s;
const int thr4 = 0 * m + 11 * s;



void setup() {
  Serial.begin(9600); //initilaize serial output

  pinMode(ledPinRed, OUTPUT); //initialize led pins as outputs
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(buzzerPin, OUTPUT); //initialize buzzer pin as output
  pinMode(pirPin, INPUT); // initialize pir pin as input

  digitalWrite(ledPinRed, LOW); //set all led pins to low
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinYellow, LOW);

}

void loop() {

  //if pir detects no motion
  if (digitalRead(pirPin) == 0) {
    i = 0;
    digitalWrite(ledPinGreen, 1);
    digitalWrite(ledPinRed, 0);
    digitalWrite(ledPinYellow, 0);
    noTone(buzzerPin);
  }

  //if pir sensor detects motion
  else if (digitalRead(pirPin) == 1) {

    //while motion continuosly detected
    while (digitalRead(pirPin) == 1) {
      i++;
      Serial.print(i);
      Serial.print("\n");

      //if below first threshold
      if (i < thr1) {
        //turn on green and yellow leds
        digitalWrite(ledPinRed, 0);
        digitalWrite(ledPinGreen, 1);
        digitalWrite(ledPinYellow, 1);
        noTone(buzzerPin);
      }
      //if above first threshold and below second threshold
      else if (i > thr1 && i < thr2) {
        //turn on yellow led
        digitalWrite(ledPinRed, 0);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 1);
        noTone(buzzerPin);
      }
      //if above second threshold and below third threshold
      else if (i > thr2 && i < thr3) {
        //turn on yellow and red leds
        digitalWrite(ledPinRed, 1);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 1);
        noTone(buzzerPin);
      }
      //if above third threshold and below fourth threshold
      else if (i > thr3 && i < thr4) {
        digitalWrite(ledPinRed, 1);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 0);
        noTone(buzzerPin);
      }
      //if above fourth threshold
      else if (i > thr4) {
        //turn on red led and buzzer
        digitalWrite(ledPinRed, 1);
        digitalWrite(ledPinGreen, 0);
        digitalWrite(ledPinYellow, 0);
        tone(buzzerPin, frequency);
      }
    }
  }

}
