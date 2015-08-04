EESchema Schematic File Version 2
LIBS:power
LIBS:device
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
LIBS:Gogogo-Symbols
LIBS:MotorEncoderBoard-cache
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
L R R2
U 1 1 558FF53C
P 4150 2550
F 0 "R2" V 4230 2550 50  0000 C CNN
F 1 "1K" V 4150 2550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4080 2550 30  0001 C CNN
F 3 "" H 4150 2550 30  0000 C CNN
	1    4150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2950 3000 2950
Wire Wire Line
	3000 2950 3000 2250
Wire Wire Line
	2150 2250 6550 2250
Wire Wire Line
	4150 2250 4150 2400
Wire Wire Line
	4150 2700 4150 2950
Wire Wire Line
	3900 2950 4850 2950
$Comp
L VCC #PWR01
U 1 1 558FF5C5
P 3550 2100
F 0 "#PWR01" H 3550 1950 50  0001 C CNN
F 1 "VCC" H 3550 2250 50  0000 C CNN
F 2 "" H 3550 2100 60  0000 C CNN
F 3 "" H 3550 2100 60  0000 C CNN
	1    3550 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2100 3550 2250
Connection ~ 3550 2250
$Comp
L R R3
U 1 1 558FF5EA
P 3000 3550
F 0 "R3" V 3080 3550 50  0000 C CNN
F 1 "10k" V 3000 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2930 3550 30  0001 C CNN
F 3 "" H 3000 3550 30  0000 C CNN
	1    3000 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3150 3000 3150
Wire Wire Line
	3000 3150 3000 3400
$Comp
L GND #PWR02
U 1 1 558FF661
P 3000 4550
F 0 "#PWR02" H 3000 4300 50  0001 C CNN
F 1 "GND" H 3000 4400 50  0000 C CNN
F 2 "" H 3000 4550 60  0000 C CNN
F 3 "" H 3000 4550 60  0000 C CNN
	1    3000 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3700 3000 4550
Wire Wire Line
	3900 3150 4150 3150
Wire Wire Line
	4150 3150 4150 4400
Wire Wire Line
	3000 4400 5350 4400
Connection ~ 3000 4400
$Comp
L LM311N U2
U 1 1 558FF69C
P 5350 3050
F 0 "U2" H 5550 3350 70  0000 C CNN
F 1 "LM311D" H 5550 3250 70  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5350 3050 60  0001 C CNN
F 3 "" H 5350 3050 60  0000 C CNN
F 4 "LM311DR" H 5350 3050 60  0001 C CNN "MPN"
F 5 "1072988 - 62" H 5350 3050 60  0001 C CNN "Conrad_PN"
	1    5350 3050
	1    0    0    -1  
$EndComp
Connection ~ 4150 2950
Wire Wire Line
	5250 2250 5250 2650
Connection ~ 4150 2250
$Comp
L R R1
U 1 1 558FF72A
P 6550 2500
F 0 "R1" V 6630 2500 50  0000 C CNN
F 1 "1K" V 6550 2500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6480 2500 30  0001 C CNN
F 3 "" H 6550 2500 30  0000 C CNN
	1    6550 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2250 6550 2350
Connection ~ 5250 2250
Wire Wire Line
	5850 3050 7050 3050
Wire Wire Line
	6550 3050 6550 2650
$Comp
L R R4
U 1 1 558FF7D1
P 4500 3550
F 0 "R4" V 4580 3550 50  0000 C CNN
F 1 "1K" V 4500 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4430 3550 30  0001 C CNN
F 3 "" H 4500 3550 30  0000 C CNN
	1    4500 3550
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 558FF837
P 4500 4050
F 0 "R5" V 4580 4050 50  0000 C CNN
F 1 "1K" V 4500 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4430 4050 30  0001 C CNN
F 3 "" H 4500 4050 30  0000 C CNN
	1    4500 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 3700 4500 3900
Wire Wire Line
	4750 3800 4500 3800
Wire Wire Line
	4750 3150 4750 3800
Wire Wire Line
	4750 3150 4850 3150
Connection ~ 4500 3800
$Comp
L VCC #PWR03
U 1 1 558FF8AF
P 4500 3300
F 0 "#PWR03" H 4500 3150 50  0001 C CNN
F 1 "VCC" H 4500 3450 50  0000 C CNN
F 2 "" H 4500 3300 60  0000 C CNN
F 3 "" H 4500 3300 60  0000 C CNN
	1    4500 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 3300 4500 3400
Wire Wire Line
	4500 4400 4500 4200
Connection ~ 4150 4400
Wire Wire Line
	5350 4400 5350 3450
Connection ~ 4500 4400
Wire Wire Line
	5250 3450 5250 4400
Connection ~ 5250 4400
Wire Wire Line
	5450 3450 5450 3600
Wire Wire Line
	5450 3600 6050 3600
Wire Wire Line
	6050 3600 6050 3150
Wire Wire Line
	6050 3150 5850 3150
$Comp
L CONN_01X02 P2
U 1 1 558FFA04
P 7250 3100
F 0 "P2" H 7250 3250 50  0000 C CNN
F 1 "Out" V 7350 3100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 7250 3100 60  0001 C CNN
F 3 "" H 7250 3100 60  0000 C CNN
	1    7250 3100
	1    0    0    -1  
$EndComp
Connection ~ 6550 3050
$Comp
L GND #PWR04
U 1 1 558FFAB9
P 6900 3350
F 0 "#PWR04" H 6900 3100 50  0001 C CNN
F 1 "GND" H 6900 3200 50  0000 C CNN
F 2 "" H 6900 3350 60  0000 C CNN
F 3 "" H 6900 3350 60  0000 C CNN
	1    6900 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3150 6900 3150
Wire Wire Line
	6900 3150 6900 3350
$Comp
L CONN_01X02 P1
U 1 1 558FFB0D
P 1950 2300
F 0 "P1" H 1950 2450 50  0000 C CNN
F 1 "PWR" V 2050 2300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1950 2300 60  0001 C CNN
F 3 "" H 1950 2300 60  0000 C CNN
	1    1950 2300
	-1   0    0    -1  
$EndComp
Connection ~ 3000 2250
$Comp
L GND #PWR05
U 1 1 558FFC31
P 2350 2650
F 0 "#PWR05" H 2350 2400 50  0001 C CNN
F 1 "GND" H 2350 2500 50  0000 C CNN
F 2 "" H 2350 2650 60  0000 C CNN
F 3 "" H 2350 2650 60  0000 C CNN
	1    2350 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 2350 2350 2350
Wire Wire Line
	2350 2350 2350 2650
$Comp
L CONN_01X01 TP1
U 1 1 558FF94A
P 4600 2600
F 0 "TP1" H 4600 2700 50  0000 C CNN
F 1 "OptoOut" V 4700 2600 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Big" H 4600 2600 60  0001 C CNN
F 3 "" H 4600 2600 60  0000 C CNN
F 4 "Value" H 4600 2600 60  0001 C CNN "MPN"
	1    4600 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4600 2800 4600 2950
Connection ~ 4600 2950
Text Label 6700 3050 0    60   ~ 0
Output
Text Label 4250 2950 0    60   ~ 0
OptoOut
$Comp
L C C1
U 1 1 5590040D
P 6150 2550
F 0 "C1" H 6175 2650 50  0000 L CNN
F 1 "10u" H 6175 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6188 2400 30  0001 C CNN
F 3 "" H 6150 2550 60  0000 C CNN
	1    6150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2250 6150 2400
Connection ~ 6150 2250
$Comp
L GND #PWR06
U 1 1 559004EE
P 6150 2800
F 0 "#PWR06" H 6150 2550 50  0001 C CNN
F 1 "GND" H 6150 2650 50  0000 C CNN
F 2 "" H 6150 2800 60  0000 C CNN
F 3 "" H 6150 2800 60  0000 C CNN
	1    6150 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2700 6150 2800
$Comp
L RPI-579N1 U1
U 1 1 55BCBC09
P 3600 3050
F 0 "U1" H 3400 3250 50  0000 L CNN
F 1 "RPI-579N1" H 3600 3250 50  0000 L CNN
F 2 "DIP-4" H 3400 2850 50  0000 L CIN
F 3 "" H 3600 2950 50  0000 L CNN
	1    3600 3050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
