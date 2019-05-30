EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:diode
LIBS:maxim
LIBS:objet_chambre-cache
LIBS:sensors
LIBS:objet_cuisine-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +3V3 #PWR01
U 1 1 5BDEBB58
P 1100 950
F 0 "#PWR01" H 1100 800 50  0001 C CNN
F 1 "+3V3" H 1100 1090 50  0000 C CNN
F 2 "" H 1100 950 50  0001 C CNN
F 3 "" H 1100 950 50  0001 C CNN
	1    1100 950 
	1    0    0    -1  
$EndComp
NoConn ~ 1200 1650
$Comp
L Buzzer BZ1
U 1 1 5BDEBC13
P 10300 1000
F 0 "BZ1" H 10450 1050 50  0000 L CNN
F 1 "Buzzer" H 10450 950 50  0000 L CNN
F 2 "Buzzers_Beepers:Buzzer_12x9.5RM7.6" V 10275 1100 50  0001 C CNN
F 3 "" V 10275 1100 50  0001 C CNN
	1    10300 1000
	1    0    0    -1  
$EndComp
Text GLabel 9500 900  0    60   Input ~ 0
BUZZER_A
$Comp
L ATMEGA328P-AU U2
U 1 1 5BDEC0DA
P 2100 2150
F 0 "U2" H 1350 3400 50  0000 L BNN
F 1 "ATMEGA328P-AU" H 2500 750 50  0000 L BNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 2100 2150 50  0001 C CIN
F 3 "" H 2100 2150 50  0001 C CNN
	1    2100 2150
	1    0    0    -1  
$EndComp
$Comp
L DS1307+ U3
U 1 1 5BDEC1A2
P 9450 5300
F 0 "U3" H 9720 5850 50  0000 C CNN
F 1 "DS1307" H 9750 4750 50  0000 C CNN
F 2 "Housings_SOIC:SO-8_5.3x6.2mm_Pitch1.27mm" H 9450 5300 50  0001 C CNN
F 3 "" H 9450 5300 50  0001 C CNN
	1    9450 5300
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR02
U 1 1 5BDEC2E3
P 9450 4000
F 0 "#PWR02" H 9450 3850 50  0001 C CNN
F 1 "+3V3" H 9450 4140 50  0000 C CNN
F 2 "" H 9450 4000 50  0001 C CNN
F 3 "" H 9450 4000 50  0001 C CNN
	1    9450 4000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5BDEC303
P 9450 6050
F 0 "#PWR03" H 9450 5800 50  0001 C CNN
F 1 "GND" H 9450 5900 50  0000 C CNN
F 2 "" H 9450 6050 50  0001 C CNN
F 3 "" H 9450 6050 50  0001 C CNN
	1    9450 6050
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5BDEC384
P 8300 5600
F 0 "Y1" H 8300 5750 50  0000 C CNN
F 1 "32.468kHz" H 8300 5450 50  0000 C CNN
F 2 "Crystals:Crystal_AT310_d3.0mm_l10.0mm_Horizontal" H 8300 5600 50  0001 C CNN
F 3 "" H 8300 5600 50  0001 C CNN
	1    8300 5600
	0    1    1    0   
$EndComp
$Comp
L Conn_01x01 J10
U 1 1 5BDEC4DE
P 10450 5600
F 0 "J10" H 10450 5700 50  0000 C CNN
F 1 "VBAT" H 10450 5500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 10450 5600 50  0001 C CNN
F 3 "" H 10450 5600 50  0001 C CNN
	1    10450 5600
	1    0    0    -1  
$EndComp
Text GLabel 10450 5000 2    60   Output ~ 0
SQW_1HZ
Text GLabel 8300 5000 0    60   Input ~ 0
SCL
Text GLabel 8300 5200 0    60   BiDi ~ 0
SDA
$Comp
L R R2
U 1 1 5BDEC7E1
P 8450 4650
F 0 "R2" V 8530 4650 50  0000 C CNN
F 1 "10k" V 8450 4650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8380 4650 50  0001 C CNN
F 3 "" H 8450 4650 50  0001 C CNN
	1    8450 4650
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5BDEC85E
P 8650 4650
F 0 "R3" V 8730 4650 50  0000 C CNN
F 1 "10k" V 8650 4650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8580 4650 50  0001 C CNN
F 3 "" H 8650 4650 50  0001 C CNN
	1    8650 4650
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5BDECBF3
P 10250 4650
F 0 "R5" V 10330 4650 50  0000 C CNN
F 1 "10k" V 10250 4650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 10180 4650 50  0001 C CNN
F 3 "" H 10250 4650 50  0001 C CNN
	1    10250 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 3350 1200 3350
Wire Wire Line
	1100 3150 1100 3450
Wire Wire Line
	1200 3250 1100 3250
Connection ~ 1100 3350
Wire Wire Line
	800  1350 1200 1350
Wire Wire Line
	1100 950  1100 1350
Wire Wire Line
	1200 1050 1100 1050
Connection ~ 1100 1050
Wire Wire Line
	1200 3150 1100 3150
Connection ~ 1100 3250
Wire Wire Line
	1200 1150 1100 1150
Connection ~ 1100 1150
Wire Wire Line
	9450 6050 9450 5900
Wire Wire Line
	9450 4000 9450 4700
Wire Wire Line
	8300 5750 8300 5800
Wire Wire Line
	8300 5800 8600 5800
Wire Wire Line
	8600 5800 8600 5700
Wire Wire Line
	8600 5700 8850 5700
Wire Wire Line
	8300 5450 8300 5400
Wire Wire Line
	8300 5400 8600 5400
Wire Wire Line
	8600 5400 8600 5500
Wire Wire Line
	8600 5500 8850 5500
Wire Wire Line
	10050 5600 10250 5600
Wire Wire Line
	8300 5000 8850 5000
Wire Wire Line
	8300 5200 8850 5200
Wire Wire Line
	10050 5000 10450 5000
Wire Wire Line
	10250 5000 10250 4800
Connection ~ 10250 5000
Wire Wire Line
	8450 4800 8450 5000
Connection ~ 8450 5000
Wire Wire Line
	8650 4800 8650 5200
Connection ~ 8650 5200
Wire Wire Line
	8650 4150 8650 4500
Wire Wire Line
	8450 4150 10250 4150
Connection ~ 9450 4150
Wire Wire Line
	8450 4150 8450 4500
Connection ~ 8650 4150
Wire Wire Line
	10250 4150 10250 4500
$Comp
L OLED_SCREEN U1
U 1 1 5BDED219
P 1150 7100
F 0 "U1" H 800 6700 60  0000 C CNN
F 1 "OLED_SCREEN" H 1150 6800 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 1150 7100 60  0001 C CNN
F 3 "" H 1150 7100 60  0001 C CNN
	1    1150 7100
	0    1    1    0   
$EndComp
Text GLabel 3400 2400 2    60   Output ~ 0
SCL
Text GLabel 3400 2300 2    60   BiDi ~ 0
SDA
Wire Wire Line
	1950 7250 1700 7250
Wire Wire Line
	1700 7150 1950 7150
$Comp
L GND #PWR04
U 1 1 5BDED6D4
P 1100 3450
F 0 "#PWR04" H 1100 3200 50  0001 C CNN
F 1 "GND" H 1100 3300 50  0000 C CNN
F 2 "" H 1100 3450 50  0001 C CNN
F 3 "" H 1100 3450 50  0001 C CNN
	1    1100 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5BDED7AF
P 2350 7050
F 0 "#PWR05" H 2350 6800 50  0001 C CNN
F 1 "GND" H 2350 6900 50  0000 C CNN
F 2 "" H 2350 7050 50  0001 C CNN
F 3 "" H 2350 7050 50  0001 C CNN
	1    2350 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 6950 2350 6950
Wire Wire Line
	2350 6950 2350 7050
$Comp
L +3V3 #PWR06
U 1 1 5BDED8C6
P 1800 6750
F 0 "#PWR06" H 1800 6600 50  0001 C CNN
F 1 "+3V3" H 1800 6890 50  0000 C CNN
F 2 "" H 1800 6750 50  0001 C CNN
F 3 "" H 1800 6750 50  0001 C CNN
	1    1800 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 7050 1800 7050
Wire Wire Line
	1800 7050 1800 6750
$Comp
L Rotary_Encoder_Switch SW1
U 1 1 5BDEDA78
P 5050 6700
F 0 "SW1" H 5050 6960 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 5050 6440 50  0000 C CNN
F 2 "rotary_encoder:Rotary_Encoder" H 4950 6860 50  0001 C CNN
F 3 "" H 5050 6960 50  0001 C CNN
	1    5050 6700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5BDEDC35
P 5600 7250
F 0 "#PWR07" H 5600 7000 50  0001 C CNN
F 1 "GND" H 5600 7100 50  0000 C CNN
F 2 "" H 5600 7250 50  0001 C CNN
F 3 "" H 5600 7250 50  0001 C CNN
	1    5600 7250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5BDEDCA2
P 4500 7400
F 0 "#PWR08" H 4500 7150 50  0001 C CNN
F 1 "GND" H 4500 7250 50  0000 C CNN
F 2 "" H 4500 7400 50  0001 C CNN
F 3 "" H 4500 7400 50  0001 C CNN
	1    4500 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 6700 4500 6700
Wire Wire Line
	4500 6700 4500 7400
Wire Wire Line
	5350 6800 5600 6800
Wire Wire Line
	5600 6800 5600 7250
Text GLabel 6100 6600 2    60   Output ~ 0
SW
Text GLabel 3650 6600 0    60   Output ~ 0
A
Text GLabel 3650 6800 0    60   Output ~ 0
B
Wire Wire Line
	3650 6600 4750 6600
Wire Wire Line
	3650 6800 4750 6800
$Comp
L C C3
U 1 1 5BDEE16B
P 5850 6900
F 0 "C3" H 5875 7000 50  0000 L CNN
F 1 "100nF" H 5875 6800 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 5888 6750 50  0001 C CNN
F 3 "" H 5850 6900 50  0001 C CNN
	1    5850 6900
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5BDEE25D
P 4200 7050
F 0 "C2" H 4225 7150 50  0000 L CNN
F 1 "100nF" H 4225 6950 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 4238 6900 50  0001 C CNN
F 3 "" H 4200 7050 50  0001 C CNN
	1    4200 7050
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5BDEE294
P 3900 7050
F 0 "C1" H 3925 7150 50  0000 L CNN
F 1 "100nF" H 3925 6950 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 3938 6900 50  0001 C CNN
F 3 "" H 3900 7050 50  0001 C CNN
	1    3900 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 7050 5850 7150
Wire Wire Line
	5850 7150 5600 7150
Connection ~ 5600 7150
Wire Wire Line
	5350 6600 6100 6600
Wire Wire Line
	5850 6600 5850 6750
Connection ~ 5850 6600
Wire Wire Line
	4200 6800 4200 6900
Connection ~ 4200 6800
Wire Wire Line
	3900 6600 3900 6900
Connection ~ 3900 6600
Wire Wire Line
	3900 7300 4500 7300
Wire Wire Line
	3900 7300 3900 7200
Wire Wire Line
	4200 7200 4200 7300
Connection ~ 4200 7300
Connection ~ 4500 7300
$Comp
L R R4
U 1 1 5BDEF881
P 9850 900
F 0 "R4" V 9930 900 50  0000 C CNN
F 1 "100" V 9850 900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9780 900 50  0001 C CNN
F 3 "" H 9850 900 50  0001 C CNN
	1    9850 900 
	0    1    1    0   
$EndComp
Text GLabel 9500 1100 0    60   Input ~ 0
BUZZER_B
Wire Wire Line
	9500 900  9700 900 
Wire Wire Line
	10000 900  10200 900 
Wire Wire Line
	10200 1100 9500 1100
Wire Wire Line
	3400 2300 3100 2300
Wire Wire Line
	3100 2400 3400 2400
$Comp
L DS18B20 U4
U 1 1 5BDEFF95
P 10500 2000
F 0 "U4" H 10350 2250 50  0000 C CNN
F 1 "DS18B20" H 10500 1750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 10350 2250 50  0001 C CNN
F 3 "" H 10350 2250 50  0001 C CNN
	1    10500 2000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR09
U 1 1 5BDF0326
P 10100 1500
F 0 "#PWR09" H 10100 1350 50  0001 C CNN
F 1 "+3V3" H 10100 1640 50  0000 C CNN
F 2 "" H 10100 1500 50  0001 C CNN
F 3 "" H 10100 1500 50  0001 C CNN
	1    10100 1500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 5BDF035E
P 10100 2200
F 0 "#PWR010" H 10100 1950 50  0001 C CNN
F 1 "GND" H 10100 2050 50  0000 C CNN
F 2 "" H 10100 2200 50  0001 C CNN
F 3 "" H 10100 2200 50  0001 C CNN
	1    10100 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 2100 10100 2100
Wire Wire Line
	10100 2100 10100 2200
Wire Wire Line
	10100 1900 10200 1900
Wire Wire Line
	10100 1900 10100 1500
Text GLabel 9300 2000 0    60   BiDi ~ 0
TEMP_SENSOR
Wire Wire Line
	9300 2000 10200 2000
Text GLabel 3400 3350 2    60   BiDi ~ 0
TEMP_SENSOR
Wire Wire Line
	3400 3350 3100 3350
$Comp
L +3V3 #PWR011
U 1 1 5BDF0A09
P 3400 1900
F 0 "#PWR011" H 3400 1750 50  0001 C CNN
F 1 "+3V3" H 3400 2040 50  0000 C CNN
F 2 "" H 3400 1900 50  0001 C CNN
F 3 "" H 3400 1900 50  0001 C CNN
	1    3400 1900
	0    1    1    0   
$EndComp
Text GLabel 3400 2850 2    60   Input ~ 0
SQW_1HZ
Wire Wire Line
	3400 2850 3100 2850
Text GLabel 3400 1050 2    60   Input ~ 0
SW
Wire Wire Line
	3400 1050 3100 1050
Text GLabel 3400 3050 2    60   Input ~ 0
A
Text GLabel 3400 3150 2    60   Input ~ 0
B
Wire Wire Line
	3400 3050 3100 3050
Wire Wire Line
	3100 3150 3400 3150
Text GLabel 3400 1150 2    60   Output ~ 0
BUZZER_A
Text GLabel 3400 1250 2    60   Output ~ 0
BUZZER_B
Wire Wire Line
	3400 1150 3100 1150
Wire Wire Line
	3100 1250 3400 1250
$Comp
L Conn_01x02 J5
U 1 1 5BDF19EA
P 4200 2650
F 0 "J5" H 4200 2750 50  0000 C CNN
F 1 "UART" H 4200 2450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 4200 2650 50  0001 C CNN
F 3 "" H 4200 2650 50  0001 C CNN
	1    4200 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2650 4000 2650
Wire Wire Line
	4000 2750 3100 2750
$Comp
L Conn_01x03 J3
U 1 1 5BDF1CDB
P 4200 1450
F 0 "J3" H 4200 1650 50  0000 C CNN
F 1 "SPI" H 4200 1250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4200 1450 50  0001 C CNN
F 3 "" H 4200 1450 50  0001 C CNN
	1    4200 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1350 4000 1350
Wire Wire Line
	4000 1450 3100 1450
Wire Wire Line
	3100 1550 4000 1550
Wire Wire Line
	3400 1900 3100 1900
$Comp
L Conn_01x02 J2
U 1 1 5BDF2199
P 3950 1650
F 0 "J2" H 3950 1750 50  0000 C CNN
F 1 "OSC" H 3950 1450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3950 1650 50  0001 C CNN
F 3 "" H 3950 1650 50  0001 C CNN
	1    3950 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1650 3100 1650
Wire Wire Line
	3100 1750 3750 1750
$Comp
L Conn_01x03 J4
U 1 1 5BDF239A
P 4200 2100
F 0 "J4" H 4200 2300 50  0000 C CNN
F 1 "ADC" H 4200 1900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4200 2100 50  0001 C CNN
F 3 "" H 4200 2100 50  0001 C CNN
	1    4200 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2000 4000 2000
Wire Wire Line
	3100 2100 4000 2100
Wire Wire Line
	4000 2200 3100 2200
$Comp
L Conn_01x02 J1
U 1 1 5BDF26B7
P 850 2400
F 0 "J1" H 850 2500 50  0000 C CNN
F 1 "ADC" H 850 2200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 850 2400 50  0001 C CNN
F 3 "" H 850 2400 50  0001 C CNN
	1    850  2400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1200 2400 1050 2400
Wire Wire Line
	1050 2500 1200 2500
$Comp
L R R1
U 1 1 5BDF2B12
P 4650 2250
F 0 "R1" V 4730 2250 50  0000 C CNN
F 1 "10k" V 4650 2250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4580 2250 50  0001 C CNN
F 3 "" H 4650 2250 50  0001 C CNN
	1    4650 2250
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J6
U 1 1 5BDF2BD4
P 4950 2500
F 0 "J6" H 4950 2600 50  0000 C CNN
F 1 "RST" H 4950 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4950 2500 50  0001 C CNN
F 3 "" H 4950 2500 50  0001 C CNN
	1    4950 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2500 4750 2500
Wire Wire Line
	4650 2400 4650 2500
Connection ~ 4650 2500
$Comp
L +3V3 #PWR012
U 1 1 5BDF2E29
P 4650 2000
F 0 "#PWR012" H 4650 1850 50  0001 C CNN
F 1 "+3V3" H 4650 2140 50  0000 C CNN
F 2 "" H 4650 2000 50  0001 C CNN
F 3 "" H 4650 2000 50  0001 C CNN
	1    4650 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2000 4650 2100
$Comp
L Conn_01x01 J7
U 1 1 5BDF3118
P 4950 2950
F 0 "J7" H 4950 3050 50  0000 C CNN
F 1 "INT1" H 4950 2850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4950 2950 50  0001 C CNN
F 3 "" H 4950 2950 50  0001 C CNN
	1    4950 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2950 3100 2950
$Comp
L Conn_01x01 J8
U 1 1 5BDF34A6
P 4950 3250
F 0 "J8" H 4950 3350 50  0000 C CNN
F 1 "PD6" H 4950 3150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4950 3250 50  0001 C CNN
F 3 "" H 4950 3250 50  0001 C CNN
	1    4950 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3250 3100 3250
$Comp
L Conn_01x02 J9
U 1 1 5BDF3DFB
P 10200 3100
F 0 "J9" H 10200 3200 50  0000 C CNN
F 1 "PWR" H 10200 2900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 10200 3100 50  0001 C CNN
F 3 "" H 10200 3100 50  0001 C CNN
	1    10200 3100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR013
U 1 1 5BDF4029
P 9900 3000
F 0 "#PWR013" H 9900 2850 50  0001 C CNN
F 1 "+3V3" H 9900 3140 50  0000 C CNN
F 2 "" H 9900 3000 50  0001 C CNN
F 3 "" H 9900 3000 50  0001 C CNN
	1    9900 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5BDF4228
P 9900 3300
F 0 "#PWR014" H 9900 3050 50  0001 C CNN
F 1 "GND" H 9900 3150 50  0000 C CNN
F 2 "" H 9900 3300 50  0001 C CNN
F 3 "" H 9900 3300 50  0001 C CNN
	1    9900 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 3300 9900 3200
Wire Wire Line
	9900 3200 10000 3200
Wire Wire Line
	9900 3100 10000 3100
Wire Wire Line
	9900 3100 9900 3000
$Comp
L Battery BT1
U 1 1 5BDF5086
P 6850 2500
F 0 "BT1" H 6950 2600 50  0000 L CNN
F 1 "Battery" H 6950 2500 50  0000 L CNN
F 2 "Battery_Holders:Keystone_2468_2xAAA" V 6850 2560 50  0001 C CNN
F 3 "" V 6850 2560 50  0001 C CNN
	1    6850 2500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5BDF55BA
P 6850 2800
F 0 "#PWR015" H 6850 2550 50  0001 C CNN
F 1 "GND" H 6850 2650 50  0000 C CNN
F 2 "" H 6850 2800 50  0001 C CNN
F 3 "" H 6850 2800 50  0001 C CNN
	1    6850 2800
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR016
U 1 1 5BDF5717
P 6750 1650
F 0 "#PWR016" H 6750 1500 50  0001 C CNN
F 1 "+3V3" H 6750 1790 50  0000 C CNN
F 2 "" H 6750 1650 50  0001 C CNN
F 3 "" H 6750 1650 50  0001 C CNN
	1    6750 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 2800 6850 2700
Wire Wire Line
	6850 2300 6850 2200
Wire Wire Line
	6750 1800 6750 1650
$Comp
L GND #PWR017
U 1 1 5BDF6199
P 9150 4550
F 0 "#PWR017" H 9150 4300 50  0001 C CNN
F 1 "GND" H 9150 4400 50  0000 C CNN
F 2 "" H 9150 4550 50  0001 C CNN
F 3 "" H 9150 4550 50  0001 C CNN
	1    9150 4550
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 5BDF627E
P 9150 4350
F 0 "C5" H 9175 4450 50  0000 L CNN
F 1 "10nF" H 9175 4250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9188 4200 50  0001 C CNN
F 3 "" H 9150 4350 50  0001 C CNN
	1    9150 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  1350 800  1400
Connection ~ 1100 1350
Wire Wire Line
	9150 4500 9150 4550
Wire Wire Line
	9150 4200 9150 4150
Connection ~ 9150 4150
$Comp
L GND #PWR018
U 1 1 5BDF8241
P 800 1750
F 0 "#PWR018" H 800 1500 50  0001 C CNN
F 1 "GND" H 800 1600 50  0000 C CNN
F 2 "" H 800 1750 50  0001 C CNN
F 3 "" H 800 1750 50  0001 C CNN
	1    800  1750
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5BDF8247
P 800 1550
F 0 "C4" H 825 1650 50  0000 L CNN
F 1 "10nF" H 825 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 838 1400 50  0001 C CNN
F 3 "" H 800 1550 50  0001 C CNN
	1    800  1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  1700 800  1750
$Comp
L SW_SPDT SW2
U 1 1 5BDF8C8F
P 6850 2000
F 0 "SW2" H 6850 2170 50  0000 C CNN
F 1 "PWR_SW" H 6850 1800 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_CuK_OS102011MA1QN1_SPDT_Angled" H 6850 2000 50  0001 C CNN
F 3 "" H 6850 2000 50  0001 C CNN
	1    6850 2000
	0    -1   -1   0   
$EndComp
NoConn ~ 6950 1800
Text GLabel 1950 7150 2    60   Input ~ 0
SCL
Text GLabel 1950 7250 2    60   BiDi ~ 0
SDA
$Comp
L R R6
U 1 1 5BDFA7D0
P 9700 1800
F 0 "R6" V 9780 1800 50  0000 C CNN
F 1 "4k7" V 9700 1800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9630 1800 50  0001 C CNN
F 3 "" H 9700 1800 50  0001 C CNN
	1    9700 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 1550 9700 1550
Wire Wire Line
	9700 1550 9700 1650
Connection ~ 10100 1550
Wire Wire Line
	9700 1950 9700 2000
Connection ~ 9700 2000
$EndSCHEMATC
