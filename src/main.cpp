#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int buttonPin = 2;
const int relayPin = 4;
const int potPin = A0;

int buttonState = 0;
int relayState = LOW;
int voltagePercent = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
Serial.begin(9600);
lcd.init();
lcd.backlight();
pinMode(buttonPin, INPUT);
pinMode(relayPin, OUTPUT);

// set up the initial relay state depend on your setting
digitalWrite(relayPin, relayState);

// read the voltage from the potentiometer and calculate the percentage
voltagePercent = map(analogRead(potPin), 0, 1023, 0, 100);

// print initial message to LCD
lcd.setCursor(0, 0);
lcd.print("Relay: OFF");

}

void loop(){
  char message = char(Serial.read());
  if(message == '1')
  {
    digitalWrite(relayPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Relay ON");
  }

  if(message == '2')
  {
    digitalWrite(relayPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Relay OFF");
  }

if (message == '3')
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage : ");
    lcd.print(voltagePercent);
    lcd.print("%");
  }
}

// const int buttonPin = 2;
// const int relayPin = 4;
// const int potPin = A0;

// int buttonState = 0;
// int relayState = LOW;
// int voltagePercent = 0;

// void setup() {
//   // initialize the LCD
//   lcd.init();
//   lcd.backlight();

//   // set up the button and relay pins
//   pinMode(buttonPin, INPUT);
//   pinMode(relayPin, OUTPUT);

//   // set up the initial relay state
//   digitalWrite(relayPin, relayState);

//   // print initial message to LCD
//   lcd.setCursor(0, 0);
//   lcd.print("Relay: OFF");
// }

// void loop() {
//   // read the button state
//   buttonState = digitalRead(buttonPin);

//   // check if the button is pressed
//   if (buttonState == HIGH) {
//     // toggle the relay state
//     relayState = !relayState;
//     digitalWrite(relayPin, relayState);

//     // update the LCD message
//     lcd.setCursor(0, 0);
//     lcd.print("Relay : ");
//     lcd.print(relayState == HIGH ? "ON " : "OFF");

//     // wait a moment before reading the potentiometer
//     delay(100);

//     // read the voltage from the potentiometer and calculate the percentage
//     voltagePercent = map(analogRead(potPin), 0, 1023, 0, 100);

//     // update the LCD message with the voltage percentage
//     lcd.setCursor(0, 1);
//     lcd.print("Voltage : ");
//     lcd.print(voltagePercent);
//     lcd.print("%");
//   }
// }