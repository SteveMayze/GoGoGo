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
L RPI-579N1 U1
U 1 1 57167422
P 4250 3500
F 0 "U1" H 4050 3700 50  0000 L CNN
F 1 "RPI-579N1" H 4250 3700 50  0000 L CNN
F 2 "Gogogo-footprints:RPI-579N1" H 4050 3300 50  0000 L CIN
F 3 "" H 4250 3400 50  0000 L CNN
	1    4250 3500
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P1
U 1 1 571674B8
P 3300 2650
F 0 "P1" H 3300 2900 50  0000 C CNN
F 1 "CONN_01X04" V 3400 2650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 3300 2650 50  0001 C CNN
F 3 "" H 3300 2650 50  0000 C CNN
	1    3300 2650
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 57167519
P 5300 2650
F 0 "P2" H 5300 2900 50  0000 C CNN
F 1 "CONN_01X04" V 5400 2650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 5300 2650 50  0001 C CNN
F 3 "" H 5300 2650 50  0000 C CNN
	1    5300 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3400 3550 3400
Wire Wire Line
	3950 3600 3550 3600
Wire Wire Line
	4550 3400 5050 3400
Wire Wire Line
	4550 3600 5050 3600
Text Label 3550 3400 0    60   ~ 0
Vcc
Text Label 3550 3600 0    60   ~ 0
Cathode
Text Label 5050 3400 2    60   ~ 0
Collector
Text Label 5050 3600 2    60   ~ 0
GND
Wire Wire Line
	3500 2500 5100 2500
Wire Wire Line
	5100 2600 3500 2600
Wire Wire Line
	3500 2700 5100 2700
Wire Wire Line
	3500 2800 5100 2800
Text Label 4050 2500 0    60   ~ 0
Vcc
Text Label 4050 2600 0    60   ~ 0
Cathode
Text Label 4050 2700 0    60   ~ 0
Collector
Text Label 4050 2800 0    60   ~ 0
GND
$EndSCHEMATC
