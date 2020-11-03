EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Basic_Clock"
Date "2020-09-13"
Rev "v0"
Comp ""
Comment1 "Olivier Wolf"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR0101
U 1 1 5F5E1691
P 3350 5550
F 0 "#PWR0101" H 3350 5300 50  0001 C CNN
F 1 "GND" H 3355 5377 50  0000 C CNN
F 2 "" H 3350 5550 50  0001 C CNN
F 3 "" H 3350 5550 50  0001 C CNN
	1    3350 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 5550 3350 5300
$Comp
L Regulator_Linear:LM317_TO-220 U1
U 1 1 5F5E354F
P 1600 1400
F 0 "U1" H 1600 1642 50  0000 C CNN
F 1 "LM317_TO-220" H 1600 1551 50  0000 C CNN
F 2 "TO SOT THT:TO-220-3_Vertical" H 1600 1650 50  0001 C CIN
F 3 "https://www.distrelec.ch/Web/Downloads/a_/en/tnSTM-LM317_data_en.pdf" H 1600 1400 50  0001 C CNN
	1    1600 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5F5E425D
P 4700 3150
F 0 "Y1" V 4654 3281 50  0000 L CNN
F 1 "16Mhz" V 4745 3281 50  0000 L CNN
F 2 "Quartz:Crystal_HC49-4H_Vertical" H 4700 3150 50  0000 C CNN
F 3 "https://www.distrelec.ch/Web/Downloads/_t/ds/hc49-4h_eng_tds.pdf" H 4700 3150 50  0001 C CNN
	1    4700 3150
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5F5E55F3
P 5150 2950
F 0 "C1" V 4898 2950 50  0000 C CNN
F 1 "22pf" V 4989 2950 50  0000 C CNN
F 2 "Capacitor THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 5188 2800 50  0001 C CNN
F 3 "https://www.distrelec.ch/en/ceramic-capacitor-22pf-200v-kemet-c317c220j2g5ta/p/30110844?q=22pF&pos=1&origPos=1&origPageSize=10&track=true" H 5150 2950 50  0001 C CNN
	1    5150 2950
	0    1    1    0   
$EndComp
$Comp
L Device:C C2
U 1 1 5F5E5F2D
P 5150 3400
F 0 "C2" V 4898 3400 50  0000 C CNN
F 1 "22pf" V 4989 3400 50  0000 C CNN
F 2 "Capacitor THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 5188 3250 50  0001 C CNN
F 3 "https://www.distrelec.ch/en/ceramic-capacitor-22pf-200v-kemet-c317c220j2g5ta/p/30110844?q=22pF&pos=1&origPos=1&origPageSize=10&track=true" H 5150 3400 50  0001 C CNN
	1    5150 3400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5F5E62D2
P 5600 3150
F 0 "#PWR0102" H 5600 2900 50  0001 C CNN
F 1 "GND" H 5605 2977 50  0000 C CNN
F 2 "" H 5600 3150 50  0001 C CNN
F 3 "" H 5600 3150 50  0001 C CNN
	1    5600 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 3150 5300 3150
Wire Wire Line
	5300 3150 5300 2950
Wire Wire Line
	5300 3150 5300 3400
Connection ~ 5300 3150
Wire Wire Line
	5000 3400 4700 3400
Wire Wire Line
	4700 3400 4700 3300
Wire Wire Line
	4700 3000 4700 2950
Wire Wire Line
	4700 2950 5000 2950
Wire Wire Line
	4700 2950 4400 2950
Wire Wire Line
	4400 2950 4400 3200
Wire Wire Line
	4400 3200 3950 3200
Connection ~ 4700 2950
Wire Wire Line
	4700 3400 4400 3400
Wire Wire Line
	4400 3400 4400 3300
Wire Wire Line
	4400 3300 3950 3300
Connection ~ 4700 3400
$Comp
L Switch:SW_Push SW1
U 1 1 5F5E7C31
P 5450 4100
F 0 "SW1" H 5450 4385 50  0000 C CNN
F 1 "SW_Push_Reset" H 5450 4294 50  0000 C CNN
F 2 "Button THT:SW_PUSH_6mm_H5mm" H 5450 4300 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/printtaster-schliesser-45n-6mm-rnd-components-rnd-210-00193/p/30090649?queryFromSuggest=true" H 5450 4300 50  0001 C CNN
	1    5450 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5F5E848E
P 3800 1450
F 0 "C7" H 3915 1496 50  0000 L CNN
F 1 "100nF" H 3915 1405 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 3838 1300 50  0001 C CNN
F 3 "https://www.distrelec.ch/en/ceramic-capacitor-100nf-50v-10-kemet-c322c104k5r5ta7301/p/16571681" H 3800 1450 50  0001 C CNN
	1    3800 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5F5E8CE5
P 3500 1450
F 0 "C6" H 3615 1496 50  0000 L CNN
F 1 "100nF" H 3615 1405 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 3538 1300 50  0001 C CNN
F 3 "https://www.distrelec.ch/en/ceramic-capacitor-100nf-50v-10-kemet-c322c104k5r5ta7301/p/16571681" H 3500 1450 50  0001 C CNN
	1    3500 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1600 3800 1600
Connection ~ 3800 1600
Wire Wire Line
	3800 1300 3500 1300
Connection ~ 3800 1300
$Comp
L power:GND #PWR0103
U 1 1 5F5EA692
P 3800 1600
F 0 "#PWR0103" H 3800 1350 50  0001 C CNN
F 1 "GND" H 3805 1427 50  0000 C CNN
F 2 "" H 3800 1600 50  0001 C CNN
F 3 "" H 3800 1600 50  0001 C CNN
	1    3800 1600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5F5EAC85
P 3350 2250
F 0 "#PWR0104" H 3350 2100 50  0001 C CNN
F 1 "+5V" H 3365 2423 50  0000 C CNN
F 2 "" H 3350 2250 50  0001 C CNN
F 3 "" H 3350 2250 50  0001 C CNN
	1    3350 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5F5EB5B0
P 3800 1300
F 0 "#PWR0105" H 3800 1150 50  0001 C CNN
F 1 "+5V" H 3815 1473 50  0000 C CNN
F 2 "" H 3800 1300 50  0001 C CNN
F 3 "" H 3800 1300 50  0001 C CNN
	1    3800 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5F5EF4FA
P 5650 4100
F 0 "#PWR0106" H 5650 3850 50  0001 C CNN
F 1 "GND" H 5655 3927 50  0000 C CNN
F 2 "" H 5650 4100 50  0001 C CNN
F 3 "" H 5650 4100 50  0001 C CNN
	1    5650 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5F5EFD99
P 1000 1550
F 0 "C3" H 1115 1596 50  0000 L CNN
F 1 "100nF" H 1115 1505 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 1038 1400 50  0001 C CNN
F 3 "https://www.distrelec.ch/en/ceramic-capacitor-100nf-50v-10-kemet-c322c104k5r5ta7301/p/16571681" H 1000 1550 50  0001 C CNN
	1    1000 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5F5F0629
P 2000 1550
F 0 "R1" H 2070 1596 50  0000 L CNN
F 1 "240" H 2070 1505 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 1930 1550 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/widerstand-600mw-240ohm-vishay-mbb02070c2400fct00/p/16059199?q=240ohm&pos=1&origPos=1&origPageSize=10&track=true" H 2000 1550 50  0001 C CNN
	1    2000 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F5F10C3
P 1600 1950
F 0 "R2" H 1670 1996 50  0000 L CNN
F 1 "720" H 1670 1905 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 1530 1950 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metallschicht-festwiderstand-fuer-durchsteckmontage-732ohm-600mw-rnd-components-rnd-155m207f732rtkrtb5k0/p/30155447?q=*&pos=1&origPos=974&origPageSize=10&track=true" H 1600 1950 50  0001 C CNN
	1    1600 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:D D2
U 1 1 5F5F1652
P 1600 1000
F 0 "D2" H 1600 1217 50  0000 C CNN
F 1 "D" H 1600 1126 50  0000 C CNN
F 2 "Diode THT:D_T-1_P10.16mm_Horizontal" H 1600 1000 50  0001 C CNN
F 3 "https://www.distrelec.ch/Web/Downloads/_t/ds/1n400x_eng_tds.pdf" H 1600 1000 50  0001 C CNN
	1    1600 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C4
U 1 1 5F5F1EDA
P 2250 1550
F 0 "C4" H 2368 1596 50  0000 L CNN
F 1 "1uF" H 2368 1505 50  0000 L CNN
F 2 "Capacitor THT:CP_Radial_D5.0mm_P2.00mm" H 2288 1400 50  0001 C CNN
F 3 "https://www.distrelec.ch/en/radial-electrolytic-capacitor-1uf-25vdc-20-rnd-components-rnd-150ehr010m25b/p/30091992?q=1uF&pos=3&origPos=3&origPageSize=10&track=true" H 2250 1550 50  0001 C CNN
	1    2250 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1400 1300 1400
Wire Wire Line
	1900 1400 2000 1400
Wire Wire Line
	2000 1400 2250 1400
Connection ~ 2000 1400
Wire Wire Line
	2000 1700 1600 1700
Wire Wire Line
	1000 2150 1000 1700
Wire Wire Line
	2000 1400 2000 1000
Wire Wire Line
	2000 1000 1750 1000
Wire Wire Line
	1450 1000 1000 1000
Wire Wire Line
	1000 1000 1000 1400
Connection ~ 1000 1400
$Comp
L power:+28V #PWR0107
U 1 1 5F5F7051
P 800 1330
F 0 "#PWR0107" H 800 1180 50  0001 C CNN
F 1 "+28V" H 815 1503 50  0000 C CNN
F 2 "" H 1050 1380 50  0001 C CNN
F 3 "" H 1050 1380 50  0001 C CNN
	1    800  1330
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1400 800  1400
$Comp
L power:+5V #PWR0109
U 1 1 5F5FB9F2
P 2250 1400
F 0 "#PWR0109" H 2250 1250 50  0001 C CNN
F 1 "+5V" H 2265 1573 50  0000 C CNN
F 2 "" H 2250 1400 50  0001 C CNN
F 3 "" H 2250 1400 50  0001 C CNN
	1    2250 1400
	1    0    0    -1  
$EndComp
Connection ~ 2250 1400
Wire Wire Line
	1000 2150 1600 2150
Wire Wire Line
	1600 1800 1600 1700
Connection ~ 1600 1700
Wire Wire Line
	1600 2100 1600 2150
$Comp
L Device:LED D1
U 1 1 5F602C4A
P 1450 3450
F 0 "D1" V 1489 3332 50  0000 R CNN
F 1 "Power LED" V 1398 3332 50  0000 R CNN
F 2 "LED:LED_D5.0mm_Clear" H 1450 3450 50  0001 C CNN
F 3 "https://www.distrelec.ch/Web/Downloads/ta/_e/shL-7113SRD-D_data_e.pdf" H 1450 3450 50  0001 C CNN
	1    1450 3450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5F603077
P 1450 3000
F 0 "R3" H 1520 3046 50  0000 L CNN
F 1 "1K" H 1520 2955 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 1380 3000 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metalloxidschicht-widerstand-250mw-1kohm-rnd-components-rnd-155mor0w4j0102a50/p/30088532?q=1kohm&pos=2&origPos=1&origPageSize=10&track=true" H 1450 3000 50  0001 C CNN
	1    1450 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5F603A4F
P 1450 3750
F 0 "#PWR0110" H 1450 3500 50  0001 C CNN
F 1 "GND" H 1455 3577 50  0000 C CNN
F 2 "" H 1450 3750 50  0001 C CNN
F 3 "" H 1450 3750 50  0001 C CNN
	1    1450 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0111
U 1 1 5F6054E5
P 1450 2700
F 0 "#PWR0111" H 1450 2550 50  0001 C CNN
F 1 "+5V" H 1465 2873 50  0000 C CNN
F 2 "" H 1450 2700 50  0001 C CNN
F 3 "" H 1450 2700 50  0001 C CNN
	1    1450 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 2700 1450 2850
Wire Wire Line
	1450 3150 1450 3300
Wire Wire Line
	1450 3600 1450 3750
Text Notes 3650 1050 0    50   ~ 0
Decoupling capacitor
Wire Wire Line
	3950 4300 4350 4300
Wire Wire Line
	3950 4400 4350 4400
Text Label 4350 4300 0    50   ~ 0
RX
Text Label 4350 4400 0    50   ~ 0
TX
Wire Wire Line
	3950 4000 4350 4000
Wire Wire Line
	3950 3900 4350 3900
Text Label 4350 3900 0    50   ~ 0
SDA
Text Label 4350 4000 0    50   Italic 0
SCL
Wire Wire Line
	3950 4500 4350 4500
Wire Wire Line
	3950 4600 4350 4600
Wire Wire Line
	3950 4700 4350 4700
Text Label 4350 4500 0    50   Italic 0
PIN2
Text Label 4350 4600 0    50   Italic 0
PIN3
Text Label 4350 4700 0    50   Italic 0
PIN4
$Comp
L Switch:SW_Push SW2
U 1 1 5F612078
P 7850 1500
F 0 "SW2" H 7850 1785 50  0000 C CNN
F 1 "SW_Push" H 7850 1694 50  0000 C CNN
F 2 "Button THT:SW_PUSH_6mm_H5mm" H 7850 1700 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/printtaster-schliesser-45n-6mm-rnd-components-rnd-210-00193/p/30090649?queryFromSuggest=true" H 7850 1700 50  0001 C CNN
	1    7850 1500
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5F6127D5
P 8450 1500
F 0 "SW3" H 8450 1785 50  0000 C CNN
F 1 "SW_Push" H 8450 1694 50  0000 C CNN
F 2 "Button THT:SW_PUSH_6mm_H5mm" H 8450 1700 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/printtaster-schliesser-45n-6mm-rnd-components-rnd-210-00193/p/30090649?queryFromSuggest=true" H 8450 1700 50  0001 C CNN
	1    8450 1500
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5F612A9B
P 9050 1500
F 0 "SW4" H 9050 1785 50  0000 C CNN
F 1 "SW_Push" H 9050 1694 50  0000 C CNN
F 2 "Button THT:SW_PUSH_6mm_H5mm" H 9050 1700 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/printtaster-schliesser-45n-6mm-rnd-components-rnd-210-00193/p/30090649?queryFromSuggest=true" H 9050 1700 50  0001 C CNN
	1    9050 1500
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 5F61325A
P 7850 1050
F 0 "R4" H 7920 1096 50  0000 L CNN
F 1 "10k" H 7920 1005 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 7780 1050 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metalloxidschicht-widerstand-250mw-10kohm-rnd-components-rnd-155mor0w4j0103a50/p/30088533?q=&pos=1&origPos=1&origPageSize=10&track=true" H 7850 1050 50  0001 C CNN
	1    7850 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5F6138CF
P 8450 1050
F 0 "R5" H 8520 1096 50  0000 L CNN
F 1 "10k" H 8520 1005 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8380 1050 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metalloxidschicht-widerstand-250mw-10kohm-rnd-components-rnd-155mor0w4j0103a50/p/30088533?q=&pos=1&origPos=1&origPageSize=10&track=true" H 8450 1050 50  0001 C CNN
	1    8450 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5F613B78
P 9050 1050
F 0 "R6" H 9120 1096 50  0000 L CNN
F 1 "10k" H 9120 1005 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8980 1050 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metalloxidschicht-widerstand-250mw-10kohm-rnd-components-rnd-155mor0w4j0103a50/p/30088533?q=&pos=1&origPos=1&origPageSize=10&track=true" H 9050 1050 50  0001 C CNN
	1    9050 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 1300 7850 1245
Wire Wire Line
	8450 1300 8450 1245
Wire Wire Line
	9050 1300 9050 1250
$Comp
L power:GND #PWR0112
U 1 1 5F617289
P 8450 1900
F 0 "#PWR0112" H 8450 1650 50  0001 C CNN
F 1 "GND" H 8455 1727 50  0000 C CNN
F 2 "" H 8450 1900 50  0001 C CNN
F 3 "" H 8450 1900 50  0001 C CNN
	1    8450 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1900 8450 1700
Wire Wire Line
	8450 1700 7850 1700
Connection ~ 8450 1700
Wire Wire Line
	8450 1700 9050 1700
$Comp
L power:GND #PWR0113
U 1 1 5F642351
P 4725 5000
F 0 "#PWR0113" H 4725 4750 50  0001 C CNN
F 1 "GND" H 4730 4827 50  0000 C CNN
F 2 "" H 4725 5000 50  0001 C CNN
F 3 "" H 4725 5000 50  0001 C CNN
	1    4725 5000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0114
U 1 1 5F642D8B
P 5020 4900
F 0 "#PWR0114" H 5020 4750 50  0001 C CNN
F 1 "+5V" H 5035 5073 50  0000 C CNN
F 2 "" H 5020 4900 50  0001 C CNN
F 3 "" H 5020 4900 50  0001 C CNN
	1    5020 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 5100 4950 5100
Wire Wire Line
	5100 5200 4950 5200
Text Label 4950 5100 2    50   Italic 0
SCL
Text Label 4950 5200 2    50   Italic 0
SDA
Text Label 6975 3385 0    50   Italic 0
TX
Text Label 6975 3485 0    50   Italic 0
RX
Wire Wire Line
	7850 800  8452 800 
Wire Wire Line
	8452 800  8452 900 
Wire Wire Line
	8452 900  8450 900 
Wire Wire Line
	7850 800  7850 900 
Wire Wire Line
	8452 800  9050 800 
Wire Wire Line
	9050 800  9050 900 
Connection ~ 8452 800 
$Comp
L power:+5V #PWR0117
U 1 1 5F60FAE7
P 8450 690
F 0 "#PWR0117" H 8450 540 50  0001 C CNN
F 1 "+5V" H 8465 863 50  0000 C CNN
F 2 "" H 8450 690 50  0001 C CNN
F 3 "" H 8450 690 50  0001 C CNN
	1    8450 690 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 690  8450 800 
Wire Wire Line
	8450 800  8452 800 
Wire Wire Line
	8452 800  8455 800 
Wire Wire Line
	7850 1245 7745 1245
Connection ~ 7850 1245
Wire Wire Line
	7850 1245 7850 1200
Wire Wire Line
	8450 1245 8340 1245
Connection ~ 8450 1245
Wire Wire Line
	8450 1245 8450 1200
Wire Wire Line
	9050 1250 8970 1250
Connection ~ 9050 1250
Wire Wire Line
	9050 1250 9050 1200
Text Label 7745 1245 2    50   ~ 0
PIN2
Text Label 8340 1245 2    50   ~ 0
PIN3
Text Label 8970 1250 2    50   ~ 0
PIN4
$Comp
L power:+5V #PWR0118
U 1 1 5F627DE7
P 4950 3800
F 0 "#PWR0118" H 4950 3650 50  0001 C CNN
F 1 "+5V" H 4965 3973 50  0000 C CNN
F 2 "" H 4950 3800 50  0001 C CNN
F 3 "" H 4950 3800 50  0001 C CNN
	1    4950 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3345 2295 3345 2300
$Comp
L power:GND #PWR0121
U 1 1 5F6416EC
P 3950 5000
F 0 "#PWR0121" H 3950 4750 50  0001 C CNN
F 1 "GND" H 3955 4827 50  0000 C CNN
F 2 "" H 3950 5000 50  0001 C CNN
F 3 "" H 3950 5000 50  0001 C CNN
	1    3950 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3600 3950 3500
$Comp
L power:GND #PWR0122
U 1 1 5F6540A9
P 4100 2600
F 0 "#PWR0122" H 4100 2350 50  0001 C CNN
F 1 "GND" H 4105 2427 50  0000 C CNN
F 2 "" H 4100 2600 50  0001 C CNN
F 3 "" H 4100 2600 50  0001 C CNN
	1    4100 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5F654E06
P 4110 3500
F 0 "#PWR0123" H 4110 3250 50  0001 C CNN
F 1 "GND" H 4115 3327 50  0000 C CNN
F 2 "" H 4110 3500 50  0001 C CNN
F 3 "" H 4110 3500 50  0001 C CNN
	1    4110 3500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5F6EA64E
P 850 650
F 0 "H1" H 950 696 50  0000 L CNN
F 1 "MountingHole" H 950 605 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 850 650 50  0001 C CNN
F 3 "~" H 850 650 50  0001 C CNN
	1    850  650 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5F6EAE6E
P 950 5950
F 0 "H2" H 1050 5996 50  0000 L CNN
F 1 "MountingHole" H 1050 5905 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 950 5950 50  0001 C CNN
F 3 "~" H 950 5950 50  0001 C CNN
	1    950  5950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5F6EB2F5
P 7400 5750
F 0 "H4" H 7500 5796 50  0000 L CNN
F 1 "MountingHole" H 7500 5705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 7400 5750 50  0001 C CNN
F 3 "~" H 7400 5750 50  0001 C CNN
	1    7400 5750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5F6EB618
P 7400 800
F 0 "H3" H 7500 846 50  0000 L CNN
F 1 "MountingHole" H 7500 755 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 7400 800 50  0001 C CNN
F 3 "~" H 7400 800 50  0001 C CNN
	1    7400 800 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5F6F79AD
P 1705 5490
F 0 "J4" H 1785 5482 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 1785 5391 50  0000 L CNN
F 2 "TerminalBlock_RND:TerminalBlock_RND_205-00232_1x02_P5.08mm_Horizontal" H 1705 5490 50  0001 C CNN
F 3 "~" H 1705 5490 50  0001 C CNN
	1    1705 5490
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5F6F929F
P 2025 5500
F 0 "#PWR0120" H 2025 5250 50  0001 C CNN
F 1 "GND" H 2030 5327 50  0000 C CNN
F 2 "" H 2025 5500 50  0001 C CNN
F 3 "" H 2025 5500 50  0001 C CNN
	1    2025 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4100 4950 4100
$Comp
L Device:R R7
U 1 1 5F71577A
P 4950 3950
F 0 "R7" H 5020 3996 50  0000 L CNN
F 1 "10k" H 5020 3905 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4880 3950 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metalloxidschicht-widerstand-250mw-10kohm-rnd-components-rnd-155mor0w4j0103a50/p/30088533?q=&pos=1&origPos=1&origPageSize=10&track=true" H 4950 3950 50  0001 C CNN
	1    4950 3950
	1    0    0    -1  
$EndComp
Connection ~ 4950 4100
Wire Wire Line
	4950 4100 3950 4100
$Comp
L power:GND #PWR0108
U 1 1 5F5F7878
P 2250 2150
F 0 "#PWR0108" H 2250 1900 50  0001 C CNN
F 1 "GND" H 2255 1977 50  0000 C CNN
F 2 "" H 2250 2150 50  0001 C CNN
F 3 "" H 2250 2150 50  0001 C CNN
	1    2250 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2150 2250 2150
Connection ~ 1600 2150
Wire Wire Line
	2250 2150 2250 1700
Connection ~ 2250 2150
Wire Wire Line
	2250 2150 2750 2150
Wire Wire Line
	2750 2150 2750 1650
$Comp
L Device:C C5
U 1 1 5F627055
P 2750 1500
F 0 "C5" H 2865 1546 50  0000 L CNN
F 1 "100nF" H 2865 1455 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 2788 1350 50  0001 C CNN
F 3 "https://www.distrelec.ch/en/ceramic-capacitor-100nf-50v-10-kemet-c322c104k5r5ta7301/p/16571681" H 2750 1500 50  0001 C CNN
	1    2750 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1350 2500 1350
Wire Wire Line
	2500 1350 2500 1400
Wire Wire Line
	2500 1400 2250 1400
Wire Wire Line
	3950 4900 3950 5000
Wire Wire Line
	3950 3000 3950 3100
Connection ~ 3950 2600
Connection ~ 3950 2700
Wire Wire Line
	3950 2700 3950 2600
Connection ~ 3950 2800
Wire Wire Line
	3950 2800 3950 2700
Wire Wire Line
	3950 2900 3950 2800
Connection ~ 3950 3500
Connection ~ 3950 5000
Wire Wire Line
	2750 2300 2750 2600
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U2
U 1 1 5F5DEB52
P 3350 3800
F 0 "U2" H 2706 3846 50  0000 R CNN
F 1 "ATmega328P-PU" H 2706 3755 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm_Socket" H 3350 3800 50  0001 C CIN
F 3 "https://www.distrelec.ch/Web/Downloads/_t/ds/ATMEGA328-AU_eng_tds.pdf" H 3350 3800 50  0001 C CNN
	1    3350 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 2250 3350 2300
Connection ~ 3350 2300
Wire Wire Line
	3350 2300 2750 2300
Wire Wire Line
	3450 2300 3350 2300
Wire Wire Line
	3950 3000 3950 2900
Connection ~ 3950 3000
Connection ~ 3950 2900
Wire Wire Line
	3950 4800 3950 4900
Connection ~ 3950 4900
Wire Wire Line
	3950 2600 4100 2600
Wire Wire Line
	800  1330 800  1400
$Comp
L power:+28V #PWR0119
U 1 1 5F94A5A7
P 2030 5390
F 0 "#PWR0119" H 2030 5240 50  0001 C CNN
F 1 "+28V" H 2045 5563 50  0000 C CNN
F 2 "" H 2280 5440 50  0001 C CNN
F 3 "" H 2280 5440 50  0001 C CNN
	1    2030 5390
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5F97FF1B
P 6985 3685
F 0 "#PWR0115" H 6985 3435 50  0001 C CNN
F 1 "GND" H 6990 3512 50  0000 C CNN
F 2 "" H 6985 3685 50  0001 C CNN
F 3 "" H 6985 3685 50  0001 C CNN
	1    6985 3685
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0116
U 1 1 5F9804D8
P 7135 3590
F 0 "#PWR0116" H 7135 3440 50  0001 C CNN
F 1 "+5V" H 7150 3763 50  0000 C CNN
F 2 "" H 7135 3590 50  0001 C CNN
F 3 "" H 7135 3590 50  0001 C CNN
	1    7135 3590
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5F64B0DB
P 6700 3485
F 0 "J2" V 6638 3197 50  0000 R CNN
F 1 "Conn_01x04_Female" V 6547 3197 50  0000 R CNN
F 2 "Connector THT:PinSocket_1x04_P2.54mm_Vertical" H 6700 3485 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/gerade-buchse-leiterplattenbuchse-durchsteckmontage-reihen-kontakte-54mm-raster-rnd-connect-rnd-205-00644/p/30093664?q=*&pos=1&origPos=37&origPageSize=10&track=true" H 6700 3485 50  0001 C CNN
	1    6700 3485
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3950 3800 3950 3700
Wire Wire Line
	3950 3500 4110 3500
Wire Wire Line
	3950 3600 3950 3700
Connection ~ 3950 3600
Connection ~ 3950 3700
Wire Wire Line
	4725 5000 5100 5000
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5F6411E1
P 5300 5000
F 0 "J1" H 5328 4976 50  0000 L CNN
F 1 "Conn_01x04_Female" H 5328 4885 50  0000 L CNN
F 2 "Connector THT:PinSocket_1x04_P2.54mm_Vertical" H 5300 5000 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/gerade-buchse-leiterplattenbuchse-durchsteckmontage-reihen-kontakte-54mm-raster-rnd-connect-rnd-205-00644/p/30093664?q=*&pos=1&origPos=37&origPageSize=10&track=true" H 5300 5000 50  0001 C CNN
	1    5300 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4900 5020 4900
Wire Wire Line
	1905 5390 2030 5390
Wire Wire Line
	1905 5490 2025 5490
Wire Wire Line
	2025 5490 2025 5500
Wire Wire Line
	6975 3385 6900 3385
Wire Wire Line
	6900 3485 6975 3485
Wire Wire Line
	6900 3585 7135 3585
Wire Wire Line
	7135 3585 7135 3590
Wire Wire Line
	6985 3685 6900 3685
$Comp
L Connector:Conn_01x02_Female J_POWER1
U 1 1 5F941665
P 9700 4250
F 0 "J_POWER1" H 9728 4226 50  0000 L CNN
F 1 "Conn_01x02_Female" H 9728 4135 50  0000 L CNN
F 2 "Connector THT:PinSocket_1x02_P2.54mm_Vertical" H 9700 4250 50  0001 C CNN
F 3 "~" H 9700 4250 50  0001 C CNN
	1    9700 4250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J_UART1
U 1 1 5F941F8B
P 9700 4650
F 0 "J_UART1" H 9728 4626 50  0000 L CNN
F 1 "Conn_01x02_Female" H 9728 4535 50  0000 L CNN
F 2 "Connector THT:PinSocket_1x02_P2.54mm_Vertical" H 9700 4650 50  0001 C CNN
F 3 "~" H 9700 4650 50  0001 C CNN
	1    9700 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J_I2C1
U 1 1 5F942322
P 9700 5000
F 0 "J_I2C1" H 9728 4976 50  0000 L CNN
F 1 "Conn_01x02_Female" H 9728 4885 50  0000 L CNN
F 2 "Connector THT:PinSocket_1x02_P2.54mm_Vertical" H 9700 5000 50  0001 C CNN
F 3 "~" H 9700 5000 50  0001 C CNN
	1    9700 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5F942A97
P 9350 4350
F 0 "#PWR0124" H 9350 4100 50  0001 C CNN
F 1 "GND" H 9355 4177 50  0000 C CNN
F 2 "" H 9350 4350 50  0001 C CNN
F 3 "" H 9350 4350 50  0001 C CNN
	1    9350 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0125
U 1 1 5F942D77
P 9350 4250
F 0 "#PWR0125" H 9350 4100 50  0001 C CNN
F 1 "+5V" H 9365 4423 50  0000 C CNN
F 2 "" H 9350 4250 50  0001 C CNN
F 3 "" H 9350 4250 50  0001 C CNN
	1    9350 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 4250 9350 4250
Wire Wire Line
	9350 4350 9500 4350
Wire Wire Line
	9500 4650 9300 4650
Wire Wire Line
	9500 4750 9300 4750
Text Label 9300 4650 0    50   ~ 0
RX
Text Label 9300 4750 0    50   ~ 0
TX
Wire Wire Line
	9500 5000 9300 5000
Wire Wire Line
	9500 5100 9300 5100
Text Label 9300 5000 0    50   ~ 0
SDA
Text Label 9300 5100 0    50   ~ 0
SCL
$EndSCHEMATC
