/*
   http://www.arduino.cc/en/Tutorial/Button
   Debounce Example public domain http://www.arduino.cc/en/Tutorial/Debounce
   DS3231 library https://tronixstuff.com/2014/12/01/tutorial-using-ds1307-and-ds3231-real-time-clock-modules-with-arduino/
   Used over the Wire library. This enables me to use it with the Arduino Nano every and MKR 1010.
*/

// ToDo Known-Bug RS485 break signal has an end and start. Somehow this seems to be required?

#include "Wire.h"
#include <ArduinoRS485.h>
#include "mappingTable.h"
#define DS3231_I2C_ADDRESS 0x68

byte CMD_break[] = {
  0x00
};
//Minute at position 1
byte CMD_SET_POS_MINUTE[] = {
  0xFF, 0xC0, 0x01, 0x00  //Addr 0x01 for Tonis FAI
};
byte CMD_SET_POS_HOUR[] = {
  0xFF, 0xC0, 0x00, 0x00 //Addr 0x00 for Tonis FAI
};
byte CMD_SET_POS_CHAR[] = {
  0xFF, 0xC0, 0x00, 0x00
};

// constants won't change. They're used here to set pin numbers:
const int buttonPinMinute = 0;     // the number of the pushbutton pin
const int buttonPinHour = 1;     // the number of the pushbutton pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTimeMinute = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTimeHour = 0;  // the last time the output pin was toggled

// variables will change:
int lastButtonStateMinute = 1;   // variable to memorize the last state to recognize if a state change happend
int lastButtonStateHour = 1;        // variable to memorize the last state to recognize if a state change happend
int displayTextMemory = HIGH;

// shorten the interrupt
int incrementMinute = LOW;
int incrementHour = LOW;

// Clock variables
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

void setup() {
  // initialize the pushbutton pin as an interrupt:
  attachInterrupt(digitalPinToInterrupt(buttonPinMinute), interruptDebounceMinute, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPinHour), interruptDebounceHour, CHANGE);

  // Initialize ds3231 and serial
  Wire.begin();
  Serial.begin(9600);
  RS485.begin(19200);

  // set the initial time here (we don't have a display anymore so have to set it once at the beginning)
  // DS3231 seconds, minutes, hours, day, date, month, year
  // setDS3231time(00, 12, 12, 6, 29, 1, 20);
  delay(1000);
}

void loop() {
  // Show clock Time at 05 Seconds of the minute//
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
  if (second == 5 && displayTextMemory == HIGH) {
    displayTextMemory = LOW;
    writeMinute(minute);
    writeHour(hour);
    displayTime();
    //If it was shown once then it is enough
  } else if (second != 5 && displayTextMemory == LOW) {
    displayTextMemory = HIGH;
  }

  //Mainloop validates if an interrupt occured and an increment should be done
  //Increment Minute
  if (incrementMinute == HIGH) {
    incrementDS3231Minute();
    Serial.println("Minute");
    incrementMinute = LOW;
  }
  //Increment Hour
  if (incrementHour == HIGH) {
    incrementDS3231Hour();
    Serial.println("Hour");
    incrementHour = LOW;
  }
}

/** Helper for deactivating Message **/
void interruptDebounceMinute() {
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - lastDebounceTimeMinute > 200)
  {
    incrementMinute = HIGH;
  }
  lastDebounceTimeMinute = interrupt_time;
}

/** Helper for deactivating Message **/
void interruptDebounceHour() {
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - lastDebounceTimeHour > 200)
  {
    incrementHour = HIGH;
  }
  lastDebounceTimeHour = interrupt_time;
}

/** Helper for RS485 **/
void writeMinute(byte minute) {
  gen_break();
  RS485.beginTransmission();
  if (minute < 31) {
    CMD_SET_POS_MINUTE[3] = minute;
  } else {
    CMD_SET_POS_MINUTE[3] = minute + 1;
  }
  RS485.write(CMD_SET_POS_MINUTE, 4);
  delay(50);
  RS485.endTransmission();
}

void writeHour(byte hour) {
  gen_break();
  RS485.beginTransmission();
  CMD_SET_POS_HOUR[3] = hour + 8;
  RS485.write(CMD_SET_POS_HOUR, 4);
  delay(50);
  RS485.endTransmission();
}

void writePosition(byte addr, byte value) {
  gen_break();
  RS485.beginTransmission();
  CMD_SET_POS_CHAR[2] = addr;
  CMD_SET_POS_CHAR[3] = value;
  RS485.write(CMD_SET_POS_CHAR, 4);
  delay(50);
  RS485.endTransmission();
  delay(500);
}

void writeChar(byte addr, char c) {
  gen_break();
  RS485.beginTransmission();
  CMD_SET_POS_CHAR[2] = addr;
  CMD_SET_POS_CHAR[3] = letters.indexOf(c);
  RS485.write(CMD_SET_POS_CHAR, 4);
  delay(50);
  RS485.endTransmission();
}

int gen_break()
{
  RS485.begin(300);
  RS485.beginTransmission();
  RS485.write(CMD_break, 1);
  delay(10);               // wait
  RS485.endTransmission();
  RS485.begin(19200);
}


/** Helper for time Incrementals **/
void incrementDS3231Minute() {
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
  minute = ((minute + 1) % 60);
  setDS3231time(0, minute , hour, dayOfWeek,  dayOfMonth,  month,  year);
  displayTime();
  writeMinute(minute);
  writeHour(hour);
}

void incrementDS3231Hour() {
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  hour = ((hour + 1) % 24);
  setDS3231time(0, minute, hour, dayOfWeek,  dayOfMonth,  month,  year);
  displayTime();
  writeMinute(minute);
  writeHour(hour);
}

/** Display the time **/
void displayTime()
{
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
  // send it to the serial monitor
  Serial.println("");
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute < 10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second < 10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);

  Serial.print(", ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
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
