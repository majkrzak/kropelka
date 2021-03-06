EESchema Schematic File Version 4
EELAYER 30 0
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
L MCU_Microchip_ATtiny:ATtiny13A-PU U1
U 1 1 612D0EC3
P 5100 3800
F 0 "U1" H 4571 3846 50  0000 R CNN
F 1 "ATtiny13A-PU" H 4571 3755 50  0000 R CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 5100 3800 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc8126.pdf" H 5100 3800 50  0001 C CNN
	1    5100 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 4050 6200 4050
Wire Wire Line
	6600 3950 6600 4050
Wire Wire Line
	7000 3950 6600 3950
Wire Wire Line
	6550 4000 6250 4000
Wire Wire Line
	6550 3750 6550 4000
Wire Wire Line
	7000 3750 6550 3750
Wire Wire Line
	6500 4100 6150 4100
Wire Wire Line
	6500 3650 6500 4100
Wire Wire Line
	7000 3650 6500 3650
Wire Wire Line
	6450 4150 6100 4150
Wire Wire Line
	6450 3550 6450 4150
Wire Wire Line
	7000 3550 6450 3550
Wire Wire Line
	6100 3900 6100 4150
Wire Wire Line
	5700 3900 6100 3900
Wire Wire Line
	6150 3700 6150 4100
Wire Wire Line
	5700 3700 6150 3700
Wire Wire Line
	6200 3600 6200 4050
Wire Wire Line
	5700 3600 6200 3600
Wire Wire Line
	6250 3500 6250 4000
Wire Wire Line
	5700 3500 6250 3500
$Comp
L board:E07-M1101D U2
U 1 1 612D3103
P 7100 3800
F 0 "U2" H 6572 3846 50  0000 R CNN
F 1 "E07-M1101D" H 6572 3755 50  0000 R CNN
F 2 "board:E07-M1101D" H 6500 3600 50  0001 C CNN
F 3 "https://www.ebyte.com/en/downpdf.aspx?id=165" H 6500 3600 50  0001 C CNN
	1    7100 3800
	-1   0    0    -1  
$EndComp
$Comp
L board:Float_Switch S1
U 1 1 612EBD95
P 6150 4850
F 0 "S1" H 6250 4900 50  0000 C CNN
F 1 "Float_Switch" H 6250 4924 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6150 4950 50  0001 C CNN
F 3 "" H 6150 4950 50  0001 C CNN
	1    6150 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4950 6600 4950
Wire Wire Line
	6050 4950 5850 4950
Wire Wire Line
	5850 4950 5850 3800
Wire Wire Line
	5850 3800 5700 3800
$Comp
L board:DFR0579 U3
U 1 1 61302487
P 2600 2350
F 0 "U3" H 2750 2400 50  0000 C CNN
F 1 "DFR0579" H 2750 2000 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2600 2350 50  0001 C CNN
F 3 "" H 2600 2350 50  0001 C CNN
	1    2600 2350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0101
U 1 1 61302B57
P 3150 2300
F 0 "#PWR0101" H 3150 2150 50  0001 C CNN
F 1 "VCC" H 3165 2473 50  0000 C CNN
F 2 "" H 3150 2300 50  0001 C CNN
F 3 "" H 3150 2300 50  0001 C CNN
	1    3150 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 61303AFF
P 3150 2750
F 0 "#PWR0102" H 3150 2500 50  0001 C CNN
F 1 "GND" H 3155 2577 50  0000 C CNN
F 2 "" H 3150 2750 50  0001 C CNN
F 3 "" H 3150 2750 50  0001 C CNN
	1    3150 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2450 3150 2450
Wire Wire Line
	3150 2450 3150 2300
Wire Wire Line
	3000 2550 3150 2550
Wire Wire Line
	3150 2550 3150 2750
$Comp
L power:VCC #PWR0103
U 1 1 61306459
P 5100 2950
F 0 "#PWR0103" H 5100 2800 50  0001 C CNN
F 1 "VCC" H 5115 3123 50  0000 C CNN
F 2 "" H 5100 2950 50  0001 C CNN
F 3 "" H 5100 2950 50  0001 C CNN
	1    5100 2950
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0104
U 1 1 613068AE
P 7350 2900
F 0 "#PWR0104" H 7350 2750 50  0001 C CNN
F 1 "VCC" H 7365 3073 50  0000 C CNN
F 2 "" H 7350 2900 50  0001 C CNN
F 3 "" H 7350 2900 50  0001 C CNN
	1    7350 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 61308941
P 5100 4750
F 0 "#PWR0105" H 5100 4500 50  0001 C CNN
F 1 "GND" H 5105 4577 50  0000 C CNN
F 2 "" H 5100 4750 50  0001 C CNN
F 3 "" H 5100 4750 50  0001 C CNN
	1    5100 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 61309435
P 6600 5550
F 0 "#PWR0106" H 6600 5300 50  0001 C CNN
F 1 "GND" H 6605 5377 50  0000 C CNN
F 2 "" H 6600 5550 50  0001 C CNN
F 3 "" H 6600 5550 50  0001 C CNN
	1    6600 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 61309D09
P 7350 4750
F 0 "#PWR0107" H 7350 4500 50  0001 C CNN
F 1 "GND" H 7355 4577 50  0000 C CNN
F 2 "" H 7350 4750 50  0001 C CNN
F 3 "" H 7350 4750 50  0001 C CNN
	1    7350 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4400 7350 4750
Wire Wire Line
	5100 4400 5100 4750
Wire Wire Line
	6600 4950 6600 5550
Wire Wire Line
	5100 2950 5100 3200
Wire Wire Line
	7350 2900 7350 3200
NoConn ~ 5700 4000
NoConn ~ 7000 3850
NoConn ~ 7000 4050
$EndSCHEMATC
