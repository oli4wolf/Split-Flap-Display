EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Basic_Clock"
Date "2020-11-01"
Rev "v0.5"
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
L Device:LED D1
U 1 1 5F602C4A
P 1450 3300
F 0 "D1" V 1489 3182 50  0000 R CNN
F 1 "Power LED" V 1398 3182 50  0000 R CNN
F 2 "LED:LED_D5.0mm_Clear" H 1450 3300 50  0001 C CNN
F 3 "https://www.distrelec.ch/Web/Downloads/ta/_e/shL-7113SRD-D_data_e.pdf" H 1450 3300 50  0001 C CNN
	1    1450 3300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5F603077
P 1450 2850
F 0 "R3" H 1520 2896 50  0000 L CNN
F 1 "1K" H 1520 2805 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 1380 2850 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metalloxidschicht-widerstand-250mw-1kohm-rnd-components-rnd-155mor0w4j0102a50/p/30088532?q=1kohm&pos=2&origPos=1&origPageSize=10&track=true" H 1450 2850 50  0001 C CNN
	1    1450 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5F603A4F
P 1450 3600
F 0 "#PWR0110" H 1450 3350 50  0001 C CNN
F 1 "GND" H 1455 3427 50  0000 C CNN
F 2 "" H 1450 3600 50  0001 C CNN
F 3 "" H 1450 3600 50  0001 C CNN
	1    1450 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 2550 1450 2700
Wire Wire Line
	1450 3000 1450 3150
Wire Wire Line
	1450 3450 1450 3600
Text Notes 3650 1050 0    50   ~ 0
Decoupling capacitor
Wire Wire Line
	3950 4500 4350 4500
Wire Wire Line
	3950 4600 4350 4600
Text Label 4350 4500 0    50   ~ 0
RS485RX
Text Label 4350 4600 0    50   ~ 0
RS485TX
Wire Wire Line
	3950 4000 4350 4000
Wire Wire Line
	3950 3900 4350 3900
Text Label 4350 3900 0    50   ~ 0
SDA
Text Label 4350 4000 0    50   Italic 0
SCL
Text Label 4350 4800 0    50   Italic 0
PIN11
Text Label 4350 4900 0    50   Italic 0
PIN12
Text Label 4350 5000 0    50   Italic 0
PIN13
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
P 4975 6600
F 0 "#PWR0113" H 4975 6350 50  0001 C CNN
F 1 "GND" H 4980 6427 50  0000 C CNN
F 2 "" H 4975 6600 50  0001 C CNN
F 3 "" H 4975 6600 50  0001 C CNN
	1    4975 6600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0114
U 1 1 5F642D8B
P 5270 6500
F 0 "#PWR0114" H 5270 6350 50  0001 C CNN
F 1 "+5V" H 5285 6673 50  0000 C CNN
F 2 "" H 5270 6500 50  0001 C CNN
F 3 "" H 5270 6500 50  0001 C CNN
	1    5270 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 6700 5200 6700
Wire Wire Line
	5350 6800 5200 6800
Text Label 5200 6700 2    50   Italic 0
SCL
Text Label 5200 6800 2    50   Italic 0
SDA
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
PIN11
Text Label 8340 1245 2    50   ~ 0
PIN12
Text Label 8970 1250 2    50   ~ 0
PIN13
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
Wire Wire Line
	4950 4100 3950 4100
Connection ~ 3950 2600
Connection ~ 3950 2700
Wire Wire Line
	3950 2700 3950 2600
Wire Wire Line
	3950 2800 3950 2700
Connection ~ 3950 3500
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
	3950 2600 4100 2600
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
Wire Wire Line
	3950 3800 3950 3700
Wire Wire Line
	3950 3500 4110 3500
Wire Wire Line
	3950 3600 3950 3700
Connection ~ 3950 3600
Connection ~ 3950 3700
Wire Wire Line
	4975 6600 5350 6600
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5F6411E1
P 5550 6600
F 0 "J1" H 5578 6576 50  0000 L CNN
F 1 "Conn_01x04_Female" H 5578 6485 50  0000 L CNN
F 2 "Connector THT:PinSocket_1x04_P2.54mm_Vertical" H 5550 6600 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/gerade-buchse-leiterplattenbuchse-durchsteckmontage-reihen-kontakte-54mm-raster-rnd-connect-rnd-205-00644/p/30093664?q=*&pos=1&origPos=37&origPageSize=10&track=true" H 5550 6600 50  0001 C CNN
	1    5550 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 6500 5270 6500
Wire Wire Line
	1905 5390 2030 5390
Wire Wire Line
	1905 5490 2025 5490
Wire Wire Line
	2025 5490 2025 5500
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
	8200 4950 8000 4950
Wire Wire Line
	8200 5150 8000 5150
Text Label 8000 4950 0    50   ~ 0
RS485RX
Text Label 8000 5150 0    50   ~ 0
RS485TX
Wire Wire Line
	9500 5000 9300 5000
Wire Wire Line
	9500 5100 9300 5100
Text Label 9300 5000 0    50   ~ 0
SDA
Text Label 9300 5100 0    50   ~ 0
SCL
$Comp
L Interface_UART:MAX485E U3
U 1 1 5F9A0695
P 8685 2775
F 0 "U3" H 8685 3456 50  0000 C CNN
F 1 "MAX485E" H 8685 3365 50  0000 C CNN
F 2 "MAX485:DIP794W47P254L991H457Q8" H 8685 2075 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 8685 2825 50  0001 C CNN
	1    8685 2775
	1    0    0    -1  
$EndComp
Wire Wire Line
	8285 2675 8100 2675
Wire Wire Line
	8285 2775 8095 2775
Wire Wire Line
	8285 2875 8285 2775
Connection ~ 8285 2775
Wire Wire Line
	8285 2975 8100 2975
Text Label 8100 2675 0    50   ~ 0
RS485RX
Text Label 8100 2975 0    50   ~ 0
RS485TX
Wire Wire Line
	3950 4700 4055 4700
Text Label 4055 4700 0    50   ~ 0
TXDE
Text Label 8095 2775 0    50   ~ 0
TXDE
$Comp
L power:+5V #PWR01
U 1 1 5F9BA403
P 8685 2275
F 0 "#PWR01" H 8685 2125 50  0001 C CNN
F 1 "+5V" H 8700 2448 50  0000 C CNN
F 2 "" H 8685 2275 50  0001 C CNN
F 3 "" H 8685 2275 50  0001 C CNN
	1    8685 2275
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5F9BAF72
P 8685 3375
F 0 "#PWR02" H 8685 3125 50  0001 C CNN
F 1 "GND" H 8690 3202 50  0000 C CNN
F 2 "" H 8685 3375 50  0001 C CNN
F 3 "" H 8685 3375 50  0001 C CNN
	1    8685 3375
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5F9BB951
P 9615 2775
F 0 "J3" H 9695 2767 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9695 2676 50  0000 L CNN
F 2 "TerminalBlock_RND:TerminalBlock_RND_205-00232_1x02_P5.08mm_Horizontal" H 9615 2775 50  0001 C CNN
F 3 "~" H 9615 2775 50  0001 C CNN
	1    9615 2775
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5F9BCC74
P 9085 2825
F 0 "R8" H 9155 2871 50  0000 L CNN
F 1 "120" H 9155 2780 50  0000 L CNN
F 2 "Resistor:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 9015 2825 50  0001 C CNN
F 3 "https://www.distrelec.ch/de/metalloxidschicht-widerstand-250mw-10kohm-rnd-components-rnd-155mor0w4j0103a50/p/30088533?q=&pos=1&origPos=1&origPageSize=10&track=true" H 9085 2825 50  0001 C CNN
	1    9085 2825
	1    0    0    -1  
$EndComp
Wire Wire Line
	9085 2675 9415 2675
Wire Wire Line
	9415 2675 9415 2775
Connection ~ 9085 2675
Wire Wire Line
	9415 2875 9415 2975
Wire Wire Line
	9415 2975 9085 2975
Connection ~ 9085 2975
Wire Wire Line
	3950 5000 4350 5000
Wire Wire Line
	3950 4900 4350 4900
Wire Wire Line
	3950 4800 4350 4800
$Comp
L Connector:Conn_01x03_Female J5
U 1 1 5FA15A3A
P 8400 5050
F 0 "J5" H 8428 5076 50  0000 L CNN
F 1 "Conn_01x03_Female" H 8428 4985 50  0000 L CNN
F 2 "Connector THT:PinSocket_1x03_P2.54mm_Vertical" H 8400 5050 50  0001 C CNN
F 3 "~" H 8400 5050 50  0001 C CNN
	1    8400 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 5050 8000 5050
Text Label 8000 5050 0    50   ~ 0
TXDE
$Comp
L Connector_Generic:Conn_02x03_Odd_Even ICSP1
U 1 1 5FA2572B
P 5200 2100
F 0 "ICSP1" H 5250 2417 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 5250 2326 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" H 5200 2100 50  0001 C CNN
F 3 "~" H 5200 2100 50  0001 C CNN
	1    5200 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4100 5850 4100
Wire Wire Line
	5850 4100 5850 2400
Wire Wire Line
	5850 2400 5000 2400
Wire Wire Line
	5000 2400 5000 2200
Connection ~ 4950 4100
Wire Wire Line
	3950 3100 4050 3100
Wire Wire Line
	3950 3000 4050 3000
Wire Wire Line
	3950 2900 4050 2900
Text Label 4050 2900 0    50   ~ 0
MOSI
Text Label 4050 3000 0    50   ~ 0
MISO
Text Label 4050 3100 0    50   ~ 0
SCK
Wire Wire Line
	5000 2100 4750 2100
Wire Wire Line
	5000 2000 4750 2000
Text Label 4750 2100 0    50   ~ 0
SCK
Text Label 4750 2000 0    50   ~ 0
MISO
Wire Wire Line
	5500 2000 5750 2000
$Comp
L power:+5V #PWR03
U 1 1 5FA46A11
P 5750 2000
F 0 "#PWR03" H 5750 1850 50  0001 C CNN
F 1 "+5V" H 5765 2173 50  0000 C CNN
F 2 "" H 5750 2000 50  0001 C CNN
F 3 "" H 5750 2000 50  0001 C CNN
	1    5750 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2200 5750 2200
$Comp
L power:GND #PWR04
U 1 1 5FA4B191
P 5750 2200
F 0 "#PWR04" H 5750 1950 50  0001 C CNN
F 1 "GND" H 5755 2027 50  0000 C CNN
F 2 "" H 5750 2200 50  0001 C CNN
F 3 "" H 5750 2200 50  0001 C CNN
	1    5750 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2100 5650 2100
Text Label 5650 2100 0    50   ~ 0
MOSI
Wire Wire Line
	3950 4300 4100 4300
Wire Wire Line
	3950 4400 4100 4400
Text Label 4100 4300 0    50   ~ 0
RXD
Text Label 4100 4400 0    50   ~ 0
TXD
$Comp
L Connector:Conn_01x02_Female J_I2C2
U 1 1 5FA596D1
P 8500 4200
F 0 "J_I2C2" H 8528 4176 50  0000 L CNN
F 1 "Conn_01x02_Female" H 8528 4085 50  0000 L CNN
F 2 "Connector THT:PinSocket_1x02_P2.54mm_Vertical" H 8500 4200 50  0001 C CNN
F 3 "~" H 8500 4200 50  0001 C CNN
	1    8500 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 4200 8050 4200
Wire Wire Line
	8300 4300 8050 4300
Text Label 8050 4200 0    50   ~ 0
RXD
Text Label 8050 4300 0    50   ~ 0
TXD
$Comp
L Regulator_Switching:R-78E5.0-0.5 U4
U 1 1 5FA6D940
P 1250 4400
F 0 "U4" H 1250 4642 50  0000 C CNN
F 1 "R-78E5.0-0.5" H 1250 4551 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 1300 4150 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78Exx-0.5.pdf" H 1250 4400 50  0001 C CNN
	1    1250 4400
	1    0    0    -1  
$EndComp
$Comp
L power:+28V #PWR05
U 1 1 5FA72089
P 850 4400
F 0 "#PWR05" H 850 4250 50  0001 C CNN
F 1 "+28V" H 865 4573 50  0000 C CNN
F 2 "" H 1100 4450 50  0001 C CNN
F 3 "" H 1100 4450 50  0001 C CNN
	1    850  4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5FA72982
P 1250 4750
F 0 "#PWR06" H 1250 4500 50  0001 C CNN
F 1 "GND" H 1255 4577 50  0000 C CNN
F 2 "" H 1250 4750 50  0001 C CNN
F 3 "" H 1250 4750 50  0001 C CNN
	1    1250 4750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR07
U 1 1 5FA72F11
P 1650 4400
F 0 "#PWR07" H 1650 4250 50  0001 C CNN
F 1 "+5V" H 1665 4573 50  0000 C CNN
F 2 "" H 1650 4400 50  0001 C CNN
F 3 "" H 1650 4400 50  0001 C CNN
	1    1650 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 4750 1250 4700
Wire Wire Line
	950  4400 850  4400
Wire Wire Line
	1550 4400 1650 4400
$Comp
L power:+5V #PWR0111
U 1 1 5F6054E5
P 1450 2550
F 0 "#PWR0111" H 1450 2400 50  0001 C CNN
F 1 "+5V" H 1465 2723 50  0000 C CNN
F 2 "" H 1450 2550 50  0001 C CNN
F 3 "" H 1450 2550 50  0001 C CNN
	1    1450 2550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
