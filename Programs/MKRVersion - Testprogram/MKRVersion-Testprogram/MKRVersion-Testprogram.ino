/*
   http://www.arduino.cc/en/Tutorial/Button
   Debounce Example public domain http://www.arduino.cc/en/Tutorial/Debounce
   DS3231 library https://tronixstuff.com/2014/12/01/tutorial-using-ds1307-and-ds3231-real-time-clock-modules-with-arduino/
   Used over the Wire library. This enables me to use it with the Arduino Nano every and MKR 1010.
*/

// ToDo Known-Bug RS485 break signal has an end and start. Somehow this seems to be required?

#include "Wire.h"
#include <ArduinoRS485.h>
#define DS3231_I2C_ADDRESS 0x68

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
byte CMD_W_ROTATION[] = {
  0xFF, 0x8A, 0x01
};

// Clock variables
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

void setup() {
  // Initialize ds3231 and serial
  Wire.begin();
  RS485.begin(19200);
  Serial.begin(57600);

  // set the initial time here (we don't have a display anymore so have to set it once at the beginning)
  // DS3231 seconds, minutes, hours, day, date, month, year
  setDS3231time(00, 13, 14, 6, 29, 1, 20);
  delay(1000);
}

void loop() {
  Serial.println("Listening to Input");
  Serial.println("1 for Time, 2 for Adress, 3 for type, 4 move addr 40");
  for (;;) {
    switch (Serial.read()) {
      case '0': checkFAI(); break;
      case '1': timeConfig(); break;
      case '2': findAddress(); break;
      case '3': findType(); break;
      case '4': sendPosition(); break;
      case '5': calibration(); break;
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
      for (int i = 0; i< 10;i++) {
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
    RS485.beginTransmission();
    RS485.write(CMD_R_ADR, 3);
    RS485.endTransmission();
    RS485.receive();
    int counter = 0;
    // Works with the delay wait to receive something
    delay(100);
    if (RS485.available()) {
      Serial.print("Address Found ");
      Serial.print(i);
      return i;
    }
  }
  Serial.println("No Device found");
  return -1;
}

int findType() {
  Serial.println("Please wait ...");
  for (int i = 0; i < 256; i++) {
    CMD_R_TYPE[2] = i;
    gen_break();
    RS485.beginTransmission();
    RS485.write(CMD_R_TYPE, 3);
    RS485.endTransmission();
    RS485.receive();
    int counter = 0;
    // Works with the delay wait to receive something
    delay(100);
    if (RS485.available()) {
      int value = Serial.read();
      if(value == 10){
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

void sendPosition(){
  for (int i = 0; i< 10;i++) {
  writePosition(40, i);
  }
}

void calibration() {
  Serial.println("Confirm only connect one Split-Flap to avoid any compromising elements. Enter: k to continue");
  int cnt = 0;
  int address = -1;
  int faiType = -1;
  
  while (!Serial.available()) {
    if(cnt= < 1000){
      cnt++;
      delay(100);  
    }
    }
  while(Serial.available()){
    char enter = Serial.read();
    if(enter == 'k'){
      int address = findAddress();
      int faiType = findType();
      // Only continue if we found an Split-Flap
      if(address >= 0){
        Serial.println("Begin configuration: Rotating to ")
                //        i_key = wait_select();
        CMD_w_rotation[2] = adrFlap;
        digitalWrite(RS485_control, RS485Transmit);
        itmp = gen_break();
        mySerial.write(CMD_w_rotation, 3);
      }
  }


}
  
}

/** Helper for RS485 **/
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

int gen_break()
{
  RS485.begin(300);
  RS485.beginTransmission();
  RS485.write(CMD_break, 1);
  delay(10);               // wait
  RS485.endTransmission();
  RS485.begin(19200);
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
