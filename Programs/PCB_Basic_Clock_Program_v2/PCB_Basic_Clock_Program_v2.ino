/*
  Second Version of the PCB Basic Clock Program.
  Debounce logic https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
   DS3231 library https://tronixstuff.com/2014/12/01/tutorial-using-ds1307-and-ds3231-real-time-clock-modules-with-arduino/
   Used over the Wire library. This enables me to use it with the Arduino Nano every and MKR 1010 for development.
*/

// Move the position to the default positions for the FIA

#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68

//*****************
//***** RS485Serial *****
//*****************
#include <SoftwareSerial.h>
SoftwareSerial RS485Serial(2, 3); // RX, TX
#define RS485Control 4  //Pin 6 RS485Serial direction control
#define RS485Transmit    HIGH
#define RS485Receive     LOW

//*****************
//***** Flap Commands *****
//*****************
byte CMD_break[] = {
  0x00
};
byte CMD_SET_POS_CHAR[] = {
  0xFF, 0xC0, 0x00, 0x00 // 255 192 Position Value
};
byte CMD_R_ADR[] = {
  0xFF, 0xDE, 0x28 // 255 222 Value
};
byte CMD_R_TYPE[] = {
  0xFF, 0xDD, 0x7B // 255 221  Value
};

//*************************
// Variables and constants
//*************************
const int PinMinute = 5;    // the number of the pushbutton pin
const int PinHour = 6;    // the number of the pushbutton pin
const int PinSpecial = 7;    // the number of the pushbutton pin

int minuteState;             // the current reading from the input pin
int lastMinuteState = HIGH;   // the previous reading from the input pin
int hourState;             // the current reading from the input pin
int lastHourState = HIGH;   // the previous reading from the input pin
int specialState;             // the current reading from the input pin
int lastSpecialState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceMinute = 0;  // the last time the output pin was toggled
unsigned long lastDebounceHour = 0;  // the last time the output pin was toggled
unsigned long lastDebounceSpecial = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int lastSecondPrint = 0;

// Clock variables
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

void setup() {
  // Initialize ds3231 and serial
  Wire.begin();
  RS485Serial.begin(19200);
  pinMode(RS485Control, OUTPUT);
  pinMode(PinMinute, INPUT);
  pinMode(PinHour, INPUT);
  pinMode(PinSpecial, INPUT);
  Serial.begin(9600);
  delay(1000);

// Initialize clock at start
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
    writeHour(hour);
    writeMinute(minute);
}

void loop() {
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);

  if (lastSecondPrint != second) {
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
    lastSecondPrint = second;
  }

  if (second == 5) {
    writeHour(hour);
    writeMinute(minute);
    delay(1000);
  }

  // Debounce logic for Minute
  int reading = digitalRead(PinMinute);
  if (reading != lastMinuteState) {
    lastDebounceMinute = millis();
  }

  if ((millis() - lastDebounceMinute) > debounceDelay) {

    if (reading != minuteState) {
      minuteState = reading;
        Serial.println("Last debounce diff Minute");
        Serial.println(millis() - lastDebounceMinute);

      if (minuteState == LOW) {
        minute = (minute + 1) % 60;
        setDS3231time(0, minute, hour, dayOfWeek, dayOfMonth, month, year);
        writeMinute(minute);
      }
    }
  }
  lastMinuteState = reading;

  // Debounce logic for Hour
  reading = digitalRead(PinHour);
  if (reading != lastHourState) {
    lastDebounceHour = millis();
  }
  if ((millis() - lastDebounceHour) > debounceDelay) {
    if (reading != hourState) {
      hourState = reading;

      if (hourState == LOW) {
        hour = (hour + 1) % 24;
        setDS3231time(0, minute, hour, dayOfWeek, dayOfMonth, month, year);
        writeHour(hour);
      }
    }
  }
  lastHourState = reading;

  // Debounce logic for Special
  reading = digitalRead(PinSpecial);
  if (reading != lastSpecialState) {
    lastDebounceSpecial = millis();
  }
  if ((millis() - lastDebounceSpecial) > debounceDelay) {
    if (reading != specialState) {
      specialState = reading;

      // Make the Split Flap turn!
      if (specialState == LOW) {
        minute = (minute - 1);
        if (minute < 0) {
          minute = 59;
        }
        hour = (hour - 1);
        if (hour < 0) {
          hour = 23;
        }
        writeHour(hour);
        writeMinute(minute);
        delay(2000);
        readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
        writeHour(hour);
        writeMinute(minute);
      }
    }
  }
  lastSpecialState = reading;
}

void writeMinute(byte value) {
        writePosition(2, ((value+30) % 61));
}

void writeHour(byte value) {
        writePosition(1, hour % 24);
}

/** Helper for RS485Serial **/
void writePosition(byte addr, byte value) {
  gen_break();
  CMD_SET_POS_CHAR[2] = addr;
  CMD_SET_POS_CHAR[3] = value;
  RS485Serial.write(CMD_SET_POS_CHAR, 4);
  digitalWrite(RS485Control, RS485Receive);
}

int gen_break()
{
  RS485Serial.begin(300);
  digitalWrite(RS485Control, RS485Transmit);
  RS485Serial.write(CMD_break, 1);
  delay(10);               // wait
  RS485Serial.begin(19200);
  delay(2);
}

/** Helper methods **/
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

/** DS3231 Helper**/
void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte
                   dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}

void readDS3231time(byte *second,
                    byte *minute,
                    byte *hour,
                    byte *dayOfWeek,
                    byte *dayOfMonth,
                    byte *month,
                    byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}
