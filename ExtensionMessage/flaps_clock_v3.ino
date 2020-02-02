//********************************
//***** F L A P S  C L O C K *****
//********************************

//****************
//***** Menu *****
//****************
// 00 MENU
// 01 HORLOGE
// 02 MISE A L'HEURE
// 03 CALIBRATION
// 04 PAS A PAS

int backlightMode = 0;
int menuMode = 0;
int smenuMode = 0;

//*************************
//***** Affichage LCD *****
//*************************
#include <LiquidCrystal.h>    //Pour gestion du LCD1602

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int backLight = 10;    // pin 10 will control the backlight
//*******************
//***** Clavier *****
//*******************
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int lcd_key = 0;
int adc_key_in = 0;
int keyboard_key = 0;
int i_key = 0;
int itmp = 0;

//*******************
//***** Horloge *****
//*******************
// format  XHMSSXHMMSSXHHMMSSX
// nb.pos. 4464444444444444444
// Adresse 0000000000111111111
// Adresse 0123456789012345678
#include <Wire.h>             //Pour gestion di C 3231

#define CLOCK_ADDRESS 0x68
bool Century = true;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
byte yy, mo, hh, mm, ss, ss1, ss2, dow, dow1, dow2, dt, cinq;
bool ADy, A12h, Apm;
int led = 13;
String ss01 = "";
String mm1 = "";
String hh1 = "";
String mo1 = "";
String dt1 = "";
String timeSetup = "";
String timeSetupD = "";
String timeSetupF = "";
String timeSetupX = "";
byte oldMinute;

int posTimeSetup = 0;
int iitmp;

byte Year;
byte Month;
byte Date;
byte Day;
byte DoW;
byte Hour;
byte Minute;
byte Second;

//*****************
//***** RS485 *****
//*****************
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 13); // RX, TX
#define RS485_control 2  //Pin 2 RS485 direction control
#define RS485Transmit    HIGH
#define RS485Receive     LOW

long messageDelay = 3000;
long positionDelay = 500;

//********************
//Fixed Table
//*******************
#include "messageTable.h"

//*********************
//***** Protocole *****
//*********************
byte CMD_break[] = {
        0x00
};
byte header[] = {
        0xFF, 0xC0, 0x00
};
char readbuffer[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
byte CMD_r_adr[] = {
        0xFF, 0x9E, 0x7B
};
byte CMD_w_adr[] = {
        0xFF, 0x8E, 0x00, 0x7B
};
byte CMD_r_typ[] = {
        0xFF, 0x9D, 0x8C
};
byte CMD_w_typ[] = {
        0xFF, 0x8D, 0x00, 0x01
};
byte CMD_w_step[] = {
        0xFF, 0x86, 0x7B, 0x00
};
byte CMD_w_puls[] = {
        0xFF, 0x87, 0x7B, 0x00
};
byte CMD_w_rotation[] = {
        0xFF, 0x8A, 0x01
};
byte CMD_w_cal[] = {
        0xFF, 0x8B, 0xAD, 0x00
};

byte CMD_w_step_all[] = {
        0xFF, 0xA6, 0x00, 0x00
};

int readchar;
int incomingByte = 0;
int adrFlap = -1;
int adrFlapnew = -1;
int cen = -1;
int diz = -1;
int uni = -1;
int typFlap = -1;
int typFlaptmp = -1;
int curpos = -1;
int posFlap = -1;
int nbPuls = -1;

int cnt_step = -1;
int cnt_step1 = -1;

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXX   START APPLICATION   XXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void setup() {
    backlightMode = 0;     // Flag LCD backlight off
    menuMode = 1;     // Flag Menu HORLOGE
    smenuMode = 0;     // Flag sousMenu

    pinMode(RS485_control, OUTPUT);
    Serial.begin(19200);
    mySerial.begin(19200);

    lcd.begin(16, 2);              // start the library
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HORLOGE");      // print a simple message
    pinMode(backLight, OUTPUT);    // LCD backlight off
    digitalWrite(backLight, LOW);
    // Start the I2C interface
    Wire.begin();
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXX   void loop   XXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void loop() {
    /////////////////////////////////////////////////////////// Lecture Clavier /////////////////////////////////
    keyboard_key = read_keyboard();

    /////////////////////////////////////////////////////////// LCD Backlight ON /////////////////////////////////
    if (backlightMode == 0) {
        if (keyboard_key == btnSELECT) {
            digitalWrite(backLight, HIGH);
            backlightMode = 1;
            keyboard_key = btnNONE;
        }
    } else //if (backlightMode == 0)
    {
        /////////////////////////////////////////////////////////// MENU /////////////////////////////////
        if (menuMode == 0)  //Menu
        {
            if (keyboard_key == btnSELECT) {
                menuMode = smenuMode;
                smenuMode = 0;
                keyboard_key == btnNONE;
            }

            lcd.noCursor();
            //      lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("MENU            ");

            if (keyboard_key == btnDOWN) {
                smenuMode = smenuMode + 1;
                if (smenuMode > 4) smenuMode = 1;
            }
            if (keyboard_key == btnUP) {
                smenuMode = smenuMode - 1;
                if (smenuMode == 0) smenuMode = 4;
            }
            lcd.setCursor(0, 1);
            if (smenuMode == 1) lcd.print("Horloge ?       ");
            if (smenuMode == 2) lcd.print("Mise a l'heure ?");
            if (smenuMode == 3) lcd.print("Calibration ?   ");
            if (smenuMode == 4) lcd.print("Pas a pas ?     ");

            keyboard_key = btnNONE;
        }

        /////////////////////////////////////////////////////////// MISE A L'HEURE ///////////////////////////
        if (menuMode == 2)  //Mode MISE A L'HEURE
        {
            if (smenuMode == 0) {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("MISE A L'HEURE  ");
                lcd.cursor();
                lcd.setCursor(0, 1);
                lcd.print(timeSetup);
                posTimeSetup = 8;
                lcd.setCursor(posTimeSetup, 1);

                smenuMode = 1;
            }
            if (smenuMode == 1) {
                switch (keyboard_key)               // depending on which button was pushed, we perform an action
                {
                    case btnRIGHT: {
                        if (posTimeSetup < 12) posTimeSetup++;
                        lcd.setCursor(posTimeSetup, 1);
                        break;
                    }
                    case btnLEFT: {
                        if (posTimeSetup > 0) posTimeSetup--;
                        lcd.setCursor(posTimeSetup, 1);
                        break;
                    }
                    case btnUP: {
                        lcd.setCursor(posTimeSetup, 1);

                        timeSetupD = timeSetup.substring(0, posTimeSetup);
                        timeSetupF = timeSetup.substring(posTimeSetup + 1);
                        timeSetupX = timeSetup.substring(posTimeSetup, posTimeSetup + 1);

                        itmp = timeSetupX.toInt();
                        if (itmp < 9) itmp++;
                        else itmp = 0;

                        timeSetupX = String(itmp);
                        timeSetup = timeSetupD + timeSetupX + timeSetupF;
                        lcd.setCursor(0, 1);
                        lcd.print(timeSetup);
                        lcd.setCursor(posTimeSetup, 1);
                        break;
                    }
                    case btnDOWN: {
                        lcd.setCursor(posTimeSetup, 1);

                        timeSetupD = timeSetup.substring(0, posTimeSetup);
                        timeSetupF = timeSetup.substring(posTimeSetup + 1);
                        timeSetupX = timeSetup.substring(posTimeSetup, posTimeSetup + 1);

                        itmp = timeSetupX.toInt();
                        if (itmp > 0) itmp--;
                        else itmp = 9;

                        timeSetupX = String(itmp);
                        timeSetup = timeSetupD + timeSetupX + timeSetupF;
                        lcd.setCursor(0, 1);
                        lcd.print(timeSetup);
                        lcd.setCursor(posTimeSetup, 1);
                        break;
                    }
                    case btnSELECT: {
                        GetDateStuff();
                        setYear(Year);
                        setMonth(Month);
                        setDate(Day);
                        setDoW(DoW);
                        setHour(Hour);
                        setMinute(Minute);
                        setSecond(Second);
                        menuMode = 1;
                        smenuMode = 0;
                        delay(10);
                        keyboard_key = btnNONE;

                        break;
                    }
                }  //end switch

            }
        }

        /////////////////////////////////////////////////////////// CALIBRATION ///////////////////////////
        if (menuMode == 3)  //Mode Calibration
        {
            if (smenuMode == 0)  //Mettre les cables
            {

                lcd.clear();
                lcd.print("CALIBRATION");
                lcd.setCursor(0, 1);
                lcd.print("Connect Flap ?  ");
                smenuMode = 1;
            }
            if (smenuMode == 1)  //Mettre les cables
            {

                if (keyboard_key == btnSELECT) {
                    smenuMode = 2;
                    keyboard_key == btnNONE;
                }

            }

            if (smenuMode == 2)  //Cherche adresse
            {
                lcd.setCursor(0, 1);
                lcd.print("Cherche adresse?");

                for (int i = 0; i < 256; i++) {
                    lcd.setCursor(0, 1);
                    lcd.print("                ");
                    lcd.setCursor(0, 1);
                    lcd.print("Cherche adr: ");
                    lcd.print(i);

                    mySerial.read();
                    mySerial.read();

                    CMD_r_adr[2] = i;
                    digitalWrite(RS485_control, RS485Transmit);
                    itmp = gen_break();
                    mySerial.write(CMD_r_adr, 3);
                    digitalWrite(RS485_control, RS485Receive);
                    delay(10);

                    if (mySerial.available() > 0) {
                        //            mySerial.read();
                        readchar = mySerial.read();
                        mySerial.read();
                        incomingByte = readchar;
                        if (incomingByte != -1) i = 256;
                        delay(10);


                    }


                }

                adrFlap = incomingByte;
                lcd.setCursor(0, 1);
                lcd.print("                ");
                lcd.setCursor(0, 1);
                lcd.print("adr=");
                lcd.print(adrFlap);

                if (adrFlap == -1) {
                    lcd.setCursor(0, 1);
                    lcd.print("adr = NOT FOUND ");
                    smenuMode = 0;
                    delay(2000);
                } else {
                    smenuMode = 3;
                    delay(1000);
                }

            }

            if (smenuMode == 3)  //Cherche Type
            {
                lcd.setCursor(0, 1);
                lcd.print("Cherche type    ");
                delay(1000);
                //        i_key = wait_select();

                mySerial.read();
                mySerial.read();

                CMD_r_typ[2] = adrFlap;
                digitalWrite(RS485_control, RS485Transmit);
                itmp = gen_break();
                mySerial.write(CMD_r_typ, 3);
                digitalWrite(RS485_control, RS485Receive);
                delay(5);
                if (mySerial.available() > 0) {
                    //          mySerial.read();
                    readchar = mySerial.read();
                    mySerial.read();
                    incomingByte = readchar;
                    delay(5);
                }

                typFlap = incomingByte;
                lcd.setCursor(0, 1);
                lcd.print("                ");
                lcd.setCursor(0, 1);
                lcd.print("adr=");
                lcd.print(adrFlap);
                lcd.setCursor(8, 1);
                lcd.print("type=");
                lcd.print(typFlap);

                delay(1000);

                lcd.setCursor(0, 1);
                lcd.print("Rotation        ");
                //        i_key = wait_select();
                CMD_w_rotation[2] = adrFlap;
                digitalWrite(RS485_control, RS485Transmit);
                itmp = gen_break();
                mySerial.write(CMD_w_rotation, 3);
                delay(5000);
                smenuMode = 4;
            }

            if (smenuMode == 4)  //Modification et écriture adresse et type
            {
                // Edit ad=123;ty=1
                // 0123456789012345
                itmp = adr_to_cdu();
                lcd.setCursor(0, 1);
                lcd.print("Edit ad=");
                lcd.print(cen);
                lcd.print(diz);
                lcd.print(uni);

                lcd.setCursor(11, 1);
                lcd.print(",ty=");

                typFlaptmp = typFlap;
                if (typFlap == 65) typFlaptmp = 4;
                if (typFlap == 66) typFlaptmp = 6;
                if (typFlap == 67) typFlaptmp = 8;

                lcd.print(typFlaptmp);

                lcd.cursor();
                curpos = 8;
                lcd.setCursor(curpos, 1);

                itmp = edit();

                typFlap = typFlaptmp;
                if (typFlaptmp == 4) typFlap = 65;
                if (typFlaptmp == 6) typFlap = 66;
                if (typFlaptmp == 8) typFlap = 67;

                adrFlapnew = (cen * 100) + (diz * 10) + (uni);

                CMD_w_adr[2] = adrFlap;
                CMD_w_adr[3] = adrFlapnew;
                digitalWrite(RS485_control, RS485Transmit);
                itmp = gen_break();
                mySerial.write(CMD_w_adr, 4);
                adrFlap = adrFlapnew;

                CMD_w_typ[2] = adrFlap;
                CMD_w_typ[3] = typFlap;
                digitalWrite(RS485_control, RS485Transmit);
                itmp = gen_break();
                mySerial.write(CMD_w_typ, 4);

                smenuMode = 5;
                delay(1000);

            }

            if (smenuMode == 5)  //Calibration
            {
                // Position = 00   /
                // 0123456789012345/

                // RI=Step; DO=Puls/

                lcd.setCursor(0, 1);
                lcd.print("RI=Step; DO=Puls");
                diz = 0;
                uni = 0,

                        itmp = editpos();

                smenuMode = 6;
                delay(1000);

            }
            if (smenuMode == 6)  //Test le nombre de puls
            {
                // Tst Puls 8-12 0 /
                // 0123456789012345/
                lcd.setCursor(0, 1);

                if (typFlap == 0) lcd.print("Presser SELECT  ");
                if (typFlap == 1) lcd.print("Tst Puls 8-12 0 ");
                if (typFlap == 65) lcd.print("Tst Puls 8-12 0 ");
                if (typFlap == 2) lcd.print("Tst Puls 7-11 0 ");
                if (typFlap == 66) lcd.print("Tst Puls 7-11 0 ");
                if (typFlap == 3) lcd.print("Tst Puls 6-10 0 ");
                if (typFlap == 67) lcd.print("Tst Puls 6-10 0 ");

                nbPuls = 0;
                keyboard_key = btnNONE;
                while (keyboard_key != btnSELECT) {
                    if (keyboard_key == btnDOWN) {
                        nbPuls = nbPuls + 1;
                        if (nbPuls > 16) {
                            nbPuls = 0;
                            lcd.setCursor(14, 1);
                            lcd.print("0 ");
                        }

                        lcd.setCursor(14, 1);
                        lcd.print(nbPuls);
                        Serial.println("PULS");
                        CMD_w_puls[2] = adrFlap;
                        digitalWrite(RS485_control, RS485Transmit);
                        itmp = gen_break();
                        mySerial.write(CMD_w_puls, 4);
                    }
                    keyboard_key = read_keyboard();
                    delay(2);
                }
                delay(1000);
                lcd.setCursor(0, 1);
                lcd.print("FIN CALIBRATION ");
                menuMode = 0;
                smenuMode = 1;
                delay(2000);
            }
        }
        /////////////////////////////////////////////////////////// PAS A PAS ///////////////////////////
        if (menuMode == 4)  //Mode Calibration
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("PAS A PAS       ");

            cnt_step = 10;
            cnt_step1 = 10;

            keyboard_key = btnNONE;

            while (keyboard_key != btnSELECT) {

                if (keyboard_key == btnUP) {
                    cnt_step = cnt_step + 1;
                    if (cnt_step > 50) cnt_step = 50;
                }
                if (keyboard_key == btnDOWN) {
                    cnt_step = cnt_step - 1;
                    if (cnt_step < 1) cnt_step = 1;
                }

                cnt_step1 = cnt_step1 - 1;

                if (cnt_step1 == 0) {
                    digitalWrite(RS485_control, RS485Transmit);
                    itmp = gen_break();
                    mySerial.write(CMD_w_step_all, 4);
                    cnt_step1 = cnt_step;
                    lcd.setCursor(0, 1);
                    lcd.print("                ");
                    lcd.setCursor(0, 1);
                    lcd.print(cnt_step * 100);
                }

                delay(100);
                keyboard_key = read_keyboard();

            } //end while
            menuMode = 0;
            smenuMode = 0;

        }
        delay(200);
        //}

    } // end if (backlightMode == 0)


    /////////////////////////////////////////////////////////// HORLOGE ///////////////////////////////
    if (menuMode == 1)  //Mode Horloge
    {
        if (keyboard_key == btnSELECT) {
            menuMode = 0;
            smenuMode = 1;
        } else {
            lcd.noCursor();
            lcd.setCursor(0, 0);
            lcd.print("HORLOGE         ");

            lcd.setCursor(0, 1);
            yy = getYear();
            lcd.print(yy);
            timeSetup = String(yy);

            mo = getMonth(Century);
            mo1 = String(mo);
            if (mo <= 9) {
                mo1 = "0";
                mo1 += mo;
            }
            lcd.print(mo1);
            timeSetup += mo1;

            dt = getDate();
            dt1 = String(dt);
            if (dt <= 9) {
                dt1 = "0";
                dt1 += dt;
            }
            lcd.print(dt1);
            timeSetup += dt1;

            lcd.print(dow);
            timeSetup += String(dow);

            hh = getHour(h12, PM);
            hh1 = String(hh);
            if (hh <= 9) {
                hh1 = "0";
                hh1 += hh;
            }
            lcd.print(hh1);
            timeSetup += hh1;

            mm = getMinute();
            mm1 = String(mm);
            if (mm <= 9) {
                mm1 = "0";
                mm1 += mm;
            }
            lcd.print(mm1);
            timeSetup += mm1;

            ss = getSecond();
            ss01 = String(ss);
            if (ss <= 9) {
                ss01 = "0";
                ss01 += ss;
            }
            lcd.print(ss01);
            timeSetup += ss01;

            if (mm == 30 || mm == 0 || hh == 12 || (hh == 10 && 20 < mm < 30)) {
                Serial.println(oldMinute);
                Serial.print(hh1);
                Serial.print(":");
                Serial.println(mm1);
                setPositionHour(hh);
                setPositionMinute(mm);
                oldMinute = mm;

                //Random Select entry
                int randMessage = random(15);
                int pointer = 0;
                if (hh == 12) {
                    randMessage = 15;
                } else if (hh == 10 && 20 < mm < 30) {
                    randMessage = 16;
                }

                //Geburtstage ab dem Moment an den Datum anzeigen
                if (hh == 7 || hh == 12 || hh = 19)
                    if (dt == 21 && mo = 5) {
                        randMessage = 20;
                    } else if (dt == 19 && mo = 9) {
                        randMessage = 19;
                    } else if (dt == 11 && mo = 8) {
                        randMessage = 18;
                    } else if (dt == 10 && mo = 9) {
                        randMessage = 17;
                    }

                while (pointer < 33) {
                    for (int j = 2; j < 13; ++j) {
                        setPosition((byte) j, table[randMessage][pointer]);
                        pointer++;
                    }
                    delay(messageDelay);
                }
            }
        }
    }
    delay(1000);

}

void setPosition(byte address, byte value) {
    digitalWrite(RS485_control, RS485Transmit);
    itmp = gen_break();
    header[2] = address;
    mySerial.write(header, 3);
    mySerial.write(value);
    delay(positionDelay);
}

void setPositionMinute(byte value) {
    //Position 31 is empty -> jump by one
    if (value > 30) {
        value++;
    }
    setPosition(0x01, value);
}

void setPositionHour(byte value) {
    // From 0-7 Empty -> jump to 8
    value += 8;
    setPosition(0x00, value);
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXX
// FONCTION read the keyboard
//XXXXXXXXXXXXXXXXXXXXXXXXXXX
int read_keyboard() {

    adc_key_in = analogRead(0);

//    lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print(adc_key_in);
//  delay (100);

    if (adc_key_in > 1000) i_key = btnNONE;
    if ((adc_key_in < 1000) && (adc_key_in > 500)) i_key = btnSELECT;
    if ((adc_key_in < 500) && (adc_key_in > 320)) i_key = btnLEFT;
    if ((adc_key_in < 320) && (adc_key_in > 200)) i_key = btnDOWN;
    if ((adc_key_in < 200) && (adc_key_in > 50)) i_key = btnUP;
    if ((adc_key_in < 70) && (adc_key_in >= 0)) i_key = btnRIGHT;

    if (i_key != btnNONE) {
        while (analogRead(0) < 1000) delay(2);
    }
    return i_key;
}

//XXXXXXXXXXXXXXXXXXXXX
// FONCTION wait_select
//XXXXXXXXXXXXXXXXXXXXX
int wait_select() {
    keyboard_key = btnNONE;

    while (keyboard_key != btnSELECT) {
        keyboard_key = read_keyboard();
        delay(2);
    }
    return keyboard_key;
}

//XXXXXXXXXXXXXXXXXXXX
// FONCTION adr_to_cdu
//XXXXXXXXXXXXXXXXXXXX
int adr_to_cdu() {
    cen = 2;
    if (adrFlap < 200) cen = 1;
    if (adrFlap < 100) cen = 0;
    int adrFlaptmp = adrFlap - (cen * 100);

    diz = 9;
    if (adrFlaptmp < 90) diz = 8;
    if (adrFlaptmp < 80) diz = 7;
    if (adrFlaptmp < 70) diz = 6;
    if (adrFlaptmp < 60) diz = 5;
    if (adrFlaptmp < 50) diz = 4;
    if (adrFlaptmp < 40) diz = 3;
    if (adrFlaptmp < 30) diz = 2;
    if (adrFlaptmp < 20) diz = 1;
    if (adrFlaptmp < 10) diz = 0;
    uni = adrFlaptmp - (diz * 10);

    return 1;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXX
// FONCTION edit (Fonctions autorisées pour sortir SELECT ou RESET)
//XXXXXXXXXXXXXXXXXXXXXXXXXXX
int edit() {
    keyboard_key = btnNONE;

    while (keyboard_key != btnSELECT) {
        if (keyboard_key == btnUP) {
            if (curpos == 8) {
                cen = cen + 1;
                if (cen > 2) cen = 0;
            }
            if (curpos == 9) {
                diz = diz + 1;
                if (diz > 9) diz = 0;
            }
            if (curpos == 10) {
                uni = uni + 1;
                if (uni > 9) uni = 0;
            }
            if (curpos == 15) {
                typFlaptmp = typFlaptmp + 1;
                if (typFlaptmp == 5) typFlaptmp = 6; // 0=lamp;1=40;2=62;3=80;4=40L;6=60L; 8=80L
                if (typFlaptmp == 7) typFlaptmp = 8;
                if (typFlaptmp > 8) typFlaptmp = 0;
            }

            if (curpos == 8) lcd.print(cen);
            if (curpos == 9) lcd.print(diz);
            if (curpos == 10) lcd.print(uni);
            if (curpos == 15) lcd.print(typFlaptmp);
        } // fin UP
        if (keyboard_key == btnRIGHT) {
            if (curpos == 15) curpos = 8;
            else if (curpos == 8) curpos = 9;
            else if (curpos == 9) curpos = 10;
            else if (curpos == 10) curpos = 15;
        }

        lcd.setCursor(curpos, 1);

        keyboard_key = read_keyboard();
        delay(2);

    }
    return 1;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXX
// FONCTION editpos (Fonctions autorisées  RIGHT=Step; DOWN=Puls / SELECT ou RESET)
//XXXXXXXXXXXXXXXXXXXXXXXXXXX
int editpos() {

    if (mySerial.available() > 0) {
        mySerial.read();
        readchar = mySerial.read();
        mySerial.read();
        delay(10);
    }


    keyboard_key = btnNONE;

    while (keyboard_key != btnSELECT) {
        if (keyboard_key == btnRIGHT)   //Step
        {
            Serial.println("STEP");
            CMD_w_step[2] = adrFlap;
            digitalWrite(RS485_control, RS485Transmit);
            itmp = gen_break();
            mySerial.write(CMD_w_step, 4);
        } // fin btnRIGHT

        if (keyboard_key == btnDOWN)   //Puls
        {
            Serial.println("PULS");
            CMD_w_puls[2] = adrFlap;
            digitalWrite(RS485_control, RS485Transmit);
            itmp = gen_break();
            mySerial.write(CMD_w_puls, 4);
        } // fin btnDOWN

        keyboard_key = read_keyboard();
        delay(2);
    } //end while

    // Position = 00   /
    // 0123456789012345/
    lcd.setCursor(0, 1);
    lcd.print("Position = 00   ");
    curpos = 11;
    diz = 0;
    uni = 0;
    keyboard_key = btnNONE;
    lcd.cursor();
    lcd.setCursor(curpos, 1);


    while (keyboard_key != btnSELECT) {
        if (keyboard_key == btnUP) {
            if (curpos == 11) {
                diz = diz + 1;
                if (typFlap == 0) {
                    if (diz > 2) diz = 0;
                }
                if (typFlap == 1) {
                    if (diz > 4) diz = 0;
                }
                if (typFlap == 2) {
                    if (diz > 6) diz = 0;
                }
                if (typFlap == 3) {
                    if (diz > 8) diz = 0;
                }
            }

            if (curpos == 12) {
                uni = uni + 1;
                if (uni > 9) uni = 0;
            }

            if (curpos == 11) lcd.print(diz);
            if (curpos == 12) lcd.print(uni);
        } // fin UP

        if (keyboard_key == btnRIGHT) {
            if (curpos == 12) curpos = 11;
            else if (curpos == 11) curpos = 12;
        }

        lcd.setCursor(curpos, 1);           // move cursor to second line "1" and 9 spaces over
        keyboard_key = read_keyboard();
        delay(2);

    } //end while
    posFlap = (10 * diz) + uni;
    CMD_w_cal[2] = adrFlap;
    CMD_w_cal[3] = posFlap;
    digitalWrite(RS485_control, RS485Transmit);
    itmp = gen_break();
    mySerial.write(CMD_w_cal, 4);
    digitalWrite(RS485_control, RS485Receive);
    delay(10);

    if (mySerial.available() > 0) {
        mySerial.read();
        readchar = mySerial.read();
        mySerial.read();
        delay(10);
    }

    return 1;
}

///////////////////////////////////////////////////////////FONCTIONS HORLOGE ///////////////////////////////
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// FONCTIONS RTC DS3231
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
byte getYear() {
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x06);
    Wire.endTransmission();

    Wire.requestFrom(CLOCK_ADDRESS, 1);
    return bcdToDec(Wire.read());
}

/*****************************************/
byte getMonth(bool &Century) {
    byte temp_buffer;
    byte hour;
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x05);
    Wire.endTransmission();

    Wire.requestFrom(CLOCK_ADDRESS, 1);
    temp_buffer = Wire.read();
    Century = temp_buffer & 0b10000000;
    return (bcdToDec(temp_buffer & 0b01111111));
}

/*****************************************/
byte getDate() {
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x04);
    Wire.endTransmission();

    Wire.requestFrom(CLOCK_ADDRESS, 1);
    return bcdToDec(Wire.read());
}

/*****************************************/
byte getDoW() {
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x03);
    Wire.endTransmission();

    Wire.requestFrom(CLOCK_ADDRESS, 1);
    return bcdToDec(Wire.read());
}

/*****************************************/
byte getHour(bool &h12, bool &PM) {
    byte temp_buffer;
    byte hour;
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x02);
    Wire.endTransmission();

    Wire.requestFrom(CLOCK_ADDRESS, 1);
    temp_buffer = Wire.read();
    h12 = temp_buffer & 0b01000000;
    if (h12) {
        PM = temp_buffer & 0b00100000;
        hour = bcdToDec(temp_buffer & 0b00011111);
    } else {
        hour = bcdToDec(temp_buffer & 0b00111111);
    }
    return hour;
}

/*****************************************/
byte getMinute() {
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x01);
    Wire.endTransmission();

    Wire.requestFrom(CLOCK_ADDRESS, 1);
    return bcdToDec(Wire.read());
}

/*****************************************/
byte getSecond() {
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.requestFrom(CLOCK_ADDRESS, 1);
    return bcdToDec(Wire.read());
}

/*****************************************/
/*****************************************/
byte bcdToDec(byte val) {
    // Convert binary coded decimal to normal decimal numbers
    return ((val / 16 * 10) + (val % 16));
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// FONCTIONS Set RTC DS3231
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
/*****************************************
 *   Functions
 *****************************************/
void setYear(byte Year) {
    // Sets the year
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x06);
    Wire.write(decToBcd(Year));
    Wire.endTransmission();
}

/*****************************************/
void setMonth(byte Month) {
    // Sets the month
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x05);
    Wire.write(decToBcd(Month));
    Wire.endTransmission();
}

/*****************************************/
void setDate(byte Date) {
    // Sets the Date
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x04);
    Wire.write(decToBcd(Date));
    Wire.endTransmission();
}

/*****************************************/
void setDoW(byte DoW) {
    // Sets the Day of Week
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x03);
    Wire.write(decToBcd(DoW));
    Wire.endTransmission();
}

/*****************************************/
void setHour(byte Hour) {
    // Sets the hour, without changing 12/24h mode.
    // The hour must be in 24h format.

    bool h12;

    // Start by figuring out what the 12/24 mode is
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x02);
    Wire.endTransmission();
    Wire.requestFrom(CLOCK_ADDRESS, 1);
    h12 = (Wire.read() & 0b01000000);
    // if h12 is true, it's 12h mode; false is 24h.

    if (h12) {
        // 12 hour
        if (Hour > 12) {
            Hour = decToBcd(Hour - 12) | 0b01100000;
        } else {
            Hour = decToBcd(Hour) & 0b11011111;
        }
    } else {
        // 24 hour
        Hour = decToBcd(Hour) & 0b10111111;
    }

    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x02);
    Wire.write(Hour);
    Wire.endTransmission();
}

/*****************************************/
void setMinute(byte Minute) {
    // Sets the minutes
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x01);
    Wire.write(decToBcd(Minute));
    Wire.endTransmission();
}

/*****************************************/
void setSecond(byte Second) {
    // Sets the seconds
    // This function also resets the Oscillator Stop Flag, which is set
    // whenever power is interrupted.
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x00);
    Wire.write(decToBcd(Second));
    Wire.endTransmission();
    // Clear OSF flag
    byte temp_buffer = readControlByte(1);
    writeControlByte((temp_buffer & 0b01111111), 1);
}

/*****************************************/
void setClockMode(bool h12) {
    // sets the mode to 12-hour (true) or 24-hour (false).
    // One thing that bothers me about how I've written this is that
    // if the read and right happen at the right hourly millisecnd,
    // the clock will be set back an hour. Not sure how to do it better,
    // though, and as long as one doesn't set the mode frequently it's
    // a very minimal risk.
    // It's zero risk if you call this BEFORE setting the hour, since
    // the setHour() function doesn't change this mode.

    byte temp_buffer;

    // Start by reading byte 0x02.
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x02);
    Wire.endTransmission();
    Wire.requestFrom(CLOCK_ADDRESS, 1);
    temp_buffer = Wire.read();

    // Set the flag to the requested value:
    if (h12) {
        temp_buffer = temp_buffer | 0b01000000;
    } else {
        temp_buffer = temp_buffer & 0b10111111;
    }

    // Write the byte
    Wire.beginTransmission(CLOCK_ADDRESS);
    Wire.write(0x02);
    Wire.write(temp_buffer);
    Wire.endTransmission();
}

/*****************************************/
/*****************************************/

byte decToBcd(byte val) {
    // Convert normal decimal numbers to binary coded decimal
    return ((val / 10 * 16) + (val % 10));
}

/*****************************************/
byte readControlByte(bool which) {
    // Read selected control byte
    // first byte (0) is 0x0e, second (1) is 0x0f
    Wire.beginTransmission(CLOCK_ADDRESS);
    if (which) {
        // second control byte
        Wire.write(0x0f);
    } else {
        // first control byte
        Wire.write(0x0e);
    }
    Wire.endTransmission();
    Wire.requestFrom(CLOCK_ADDRESS, 1);
    return Wire.read();
}

/*****************************************/
void writeControlByte(byte control, bool which) {
    // Write the selected control byte.
    // which=false -> 0x0e, true->0x0f.
    Wire.beginTransmission(CLOCK_ADDRESS);
    if (which) {
        Wire.write(0x0f);
    } else {
        Wire.write(0x0e);
    }
    Wire.write(control);
    Wire.endTransmission();
}

//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
void GetDateStuff() {
    // the order YYMMDDwHHMMSS, with an 'x' at the end.

    byte Temp1, Temp2;
    char InString[20];
    byte j = 0;
    int i = 0;
    int itmp1;
    String stmp;

    timeSetup.toCharArray(InString, 19);

    Serial.println(InString);
    // Read Year first
    Temp1 = (byte) InString[0] - 48;
    Temp2 = (byte) InString[1] - 48;
    Year = Temp1 * 10 + Temp2;
    // now month
    Temp1 = (byte) InString[2] - 48;
    Temp2 = (byte) InString[3] - 48;
    Month = Temp1 * 10 + Temp2;
    // now date
    Temp1 = (byte) InString[4] - 48;
    Temp2 = (byte) InString[5] - 48;
    Day = Temp1 * 10 + Temp2;
    // now Day of Week
    DoW = (byte) InString[6] - 48;
    // now Hour
    Temp1 = (byte) InString[7] - 48;
    Temp2 = (byte) InString[8] - 48;
    Hour = Temp1 * 10 + Temp2;
    // now Minute
    Temp1 = (byte) InString[9] - 48;
    Temp2 = (byte) InString[10] - 48;
    Minute = Temp1 * 10 + Temp2;
    // now Second
    Temp1 = (byte) InString[11] - 48;
    Temp2 = (byte) InString[12] - 48;
    Second = Temp1 * 10 + Temp2;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXX
// FONCTION gen_break
//XXXXXXXXXXXXXXXXXXX
int gen_break() {
    mySerial.begin(300);
    mySerial.write(CMD_break, 1);
    delay(10);               // wait
    mySerial.begin(19200);
    delay(2);               // wait

    return 1;
}