#include "Wire.h"
#include <ArduinoRS485.h>
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
const int buttonPinMinute = 2;     // the number of the pushbutton pin
const int buttonPinHour = 3;     // the number of the pushbutton pin
const int buttonPinSpecial = 4;     // the number of the pushbutton pin

// variables will change:
int lastButtonStateMinute = 1;   // variable to memorize the last state to recognize if a state change happend
int lastButtonStateHour = 1;        // variable to memorize the last state to recognize if a state change happend
int lastButtonStateSpecial = 1;        // variable to memorize the last state to recognize if a state change happend

// shorten the interrupt
int incrementMinute = LOW;
int incrementHour = LOW;
int incrementSpecial = LOW;

// Clock variables
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

void setup() {
  // initialize the pushbutton pin as an interrupt:
  pinMode(buttonPinMinute, INPUT);
  pinMode(buttonPinHour, INPUT);
  pinMode(buttonPinSpecial, INPUT);

  // Initialize ds3231 and RS485
  Wire.begin();
  RS485.begin(19200);
  delay(1000);
}

void loop() {
  // Show clock Time at 05 Seconds of the minute//
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
  if (second == 5) {
    writeMinute(minute);
    writeHour(hour);
    delay(1100);
  }

  //Mainloop check for Button pressed
  //Increment Minute
  int pinReadMinute = digitalRead(buttonPinMinute);
  if(pinReadMinute == 0 && incrementMinute == LOW){
    incrementDS3231MinuteOrHour(minute++,hour);
    incrementMinute = HIGH;
  } else if(pinReadMinute == 1 && incrementMinute == HIGH){
    incrementMinute = LOW;
  }

  //Increment Hour
  int pinReadHour = digitalRead(buttonPinHour);
  if(pinReadHour == 0 && incrementHour == LOW){
    incrementHour = HIGH;
    incrementDS3231MinuteOrHour(minute,hour++);
  } else if(pinReadHour == 1 && incrementHour == HIGH){
    incrementHour = LOW;
  }

    //Increment Special
  int pinReadSpecial = digitalRead(buttonPinSpecial);
  if(pinReadSpecial == 0 && incrementHour == LOW){
    incrementSpecial = HIGH;
    writeMinute(minute-1);
    writeHour(hour-1);
    delay(500);
    writeMinute(minute);
    writeHour(hour);
  } else if(pinReadSpecial == 1 && incrementSpecial == HIGH){
    incrementSpecial = LOW;
  }
}

/** Helper for RS485 **/
void writeMinute(byte minute) {
  gen_break();
  RS485.beginTransmission();
  CMD_SET_POS_MINUTE[3] =((minute+30) % 61);
  RS485.write(CMD_SET_POS_MINUTE, 4);
  delay(50);
  RS485.endTransmission();
}

void writeHour(byte hour) {
  gen_break();
  RS485.beginTransmission();
  CMD_SET_POS_HOUR[3] = hour;
  RS485.write(CMD_SET_POS_HOUR, 4);
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
void incrementDS3231MinuteOrHour(byte minute, byte hour) {
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
  minute = (minute % 60);
  hour = (hour % 24);
  setDS3231time(0, minute , hour, dayOfWeek,  dayOfMonth,  month,  year);
  writeMinute(minute);
  writeHour(hour);
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
