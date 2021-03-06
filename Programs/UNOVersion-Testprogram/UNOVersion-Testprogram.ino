/*
   http://www.arduino.cc/en/Tutorial/Button
   Debounce Example public domain http://www.arduino.cc/en/Tutorial/Debounce
   DS3231 library https://tronixstuff.com/2014/12/01/tutorial-using-ds1307-and-ds3231-real-time-clock-modules-with-arduino/
   Used over the Wire library. This enables me to use it with the Arduino Nano every and MKR 1010.
*/

// ToDo Known-Bug RS485Serial break signal has an end and start. Somehow this seems to be required?

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

// Clock variables
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

void setup() {
  // Initialize ds3231 and serial
  Wire.begin();
  RS485Serial.begin(19200);
  pinMode(RS485Control, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}



void loop() {
  Serial.println("Listening to Input");
  Serial.println("1 for Time, 2 for Adress, 3 for type, 3 move addr 40");
  for (;;) {
    switch (Serial.read()) {
      case '0': checkFAI(); break;
      case '1': timeConfig(); break;
      case '2': findAddress(); break;
      case '3': findType(); break;
      case '4': sendPosition(); break;
      case '5': setDateAndTime(); break;
      case '6': return;
      default: continue;  // includes the case 'no input'
    }
  }
}

void checkFAI() {
  findType();
  delay(2000);
  int addr = findAddress();
  delay(2000);
  for (int i = 0; i < 10; i++) {
    writePosition(addr, i);
  }
}

void timeConfig() {
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
  Serial.println("");
  Serial.print(hour);
  Serial.print(":");
  Serial.println(minute);
}

int findAddress() {
  Serial.println("Please wait ...");
  for (int i = 0; i < 256; i++) {
    CMD_R_ADR[2] = i;
    gen_break();
    RS485Serial.write(CMD_R_ADR, 3);
    int counter = 0;
    //Receive
    digitalWrite(RS485Control, RS485Receive);
    // Works with the delay wait to receive something
    delay(100);
    if (RS485Serial.available()) {
      Serial.print("Address Found ");
      Serial.print(i);
      return i;
    }
  }
  Serial.println("No Device found");
  return -1;
}

void findType() {
  Serial.println("Please wait ...");
  for (int i = 0; i < 256; i++) {
    CMD_R_TYPE[2] = i;
    gen_break();
    RS485Serial.write(CMD_R_TYPE, 3);
    int counter = 0;
    // Works with the delay wait to receive something
    delay(100);
    if (RS485Serial.available()) {
      int value = Serial.read();
      if (value == 10) {
        Serial.print("Hour / Alphanumeric");
        return;
      } else if (value == 20) {
        Serial.print("Minute");
        return;
      }
    }
  }
  Serial.println("No Type or Device found");
}

void sendPosition() {
  Serial.println("Send Position");
  for (int i = 0; i < 10; i++) {
      writePosition(40, i);
      delay(1000);
  }
}

void setDateAndTime(){
  Serial.println("Set Time");
  // set the initial time here (we don't have a display anymore so have to set it once at the beginning)
  // DS3231 seconds, minutes, hours, day, date, month, year
  setDS3231time(00, 13, 14, 6, 29, 1, 20);
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
