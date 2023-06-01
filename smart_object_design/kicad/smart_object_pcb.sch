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
L SamacSys_Parts:150066M173000 LED1
U 1 1 5FE41EB8
P 3050 2400
F 0 "LED1" H 3600 2665 50  0000 C CNN
F 1 "150066M173000" H 3600 2574 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 4000 2500 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 4000 2400 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 4000 2300 50  0001 L CNN "Description"
F 5 "0.5" H 4000 2200 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 4000 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 4000 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 4000 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 4000 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 4000 1700 50  0001 L CNN "Arrow Part Number"
F 11 "" H 4000 1600 50  0001 L CNN "Arrow Price/Stock"
	1    3050 2400
	-1   0    0    1   
$EndComp
$Comp
L SamacSys_Parts:150066M173000 LED2
U 1 1 5FE4418B
P 3050 3150
F 0 "LED2" H 3600 3415 50  0000 C CNN
F 1 "150066M173000" H 3600 3324 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 4000 3250 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 4000 3150 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 4000 3050 50  0001 L CNN "Description"
F 5 "0.5" H 4000 2950 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 4000 2850 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 4000 2750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 4000 2650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 4000 2550 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 4000 2450 50  0001 L CNN "Arrow Part Number"
F 11 "" H 4000 2350 50  0001 L CNN "Arrow Price/Stock"
	1    3050 3150
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR0101
U 1 1 5FE5DBC3
P 9400 950
F 0 "#PWR0101" H 9400 800 50  0001 C CNN
F 1 "+3.3V" H 9415 1123 50  0000 C CNN
F 2 "" H 9400 950 50  0001 C CNN
F 3 "" H 9400 950 50  0001 C CNN
	1    9400 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5FE5E601
P 9850 1050
F 0 "#PWR0102" H 9850 800 50  0001 C CNN
F 1 "GND" H 9855 877 50  0000 C CNN
F 2 "" H 9850 1050 50  0001 C CNN
F 3 "" H 9850 1050 50  0001 C CNN
	1    9850 1050
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5FE5F59E
P 9400 1050
F 0 "#FLG0101" H 9400 1125 50  0001 C CNN
F 1 "PWR_FLAG" H 9400 1223 50  0000 C CNN
F 2 "" H 9400 1050 50  0001 C CNN
F 3 "~" H 9400 1050 50  0001 C CNN
	1    9400 1050
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5FE5FCEB
P 9850 950
F 0 "#FLG0102" H 9850 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 9850 1123 50  0000 C CNN
F 2 "" H 9850 950 50  0001 C CNN
F 3 "~" H 9850 950 50  0001 C CNN
	1    9850 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 1050 9400 1000
Wire Wire Line
	9850 1050 9850 1000
Text GLabel 9200 1000 0    50   Input ~ 0
3V3
Wire Wire Line
	9200 1000 9400 1000
Connection ~ 9400 1000
Wire Wire Line
	9400 1000 9400 950 
Text GLabel 10000 1000 2    50   Input ~ 0
GND
Wire Wire Line
	9850 1000 10000 1000
Connection ~ 9850 1000
Wire Wire Line
	9850 1000 9850 950 
$Comp
L SamacSys_Parts:150066M173000 LED3
U 1 1 5FE6D7F4
P 3050 3850
F 0 "LED3" H 3600 3485 50  0000 C CNN
F 1 "150066M173000" H 3600 3576 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 4000 3950 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 4000 3850 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 4000 3750 50  0001 L CNN "Description"
F 5 "0.5" H 4000 3650 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 4000 3550 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 4000 3450 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 4000 3350 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 4000 3250 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 4000 3150 50  0001 L CNN "Arrow Part Number"
F 11 "" H 4000 3050 50  0001 L CNN "Arrow Price/Stock"
	1    3050 3850
	-1   0    0    1   
$EndComp
$Comp
L SamacSys_Parts:150066M173000 LED4
U 1 1 5FE6D802
P 3050 4450
F 0 "LED4" H 3600 4715 50  0000 C CNN
F 1 "150066M173000" H 3600 4624 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 4000 4550 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 4000 4450 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 4000 4350 50  0001 L CNN "Description"
F 5 "0.5" H 4000 4250 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 4000 4150 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 4000 4050 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 4000 3950 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 4000 3850 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 4000 3750 50  0001 L CNN "Arrow Part Number"
F 11 "" H 4000 3650 50  0001 L CNN "Arrow Price/Stock"
	1    3050 4450
	-1   0    0    1   
$EndComp
Wire Wire Line
	1950 3050 1750 3050
Connection ~ 1750 3050
Wire Wire Line
	1750 3050 1750 3750
Wire Wire Line
	1750 2300 1950 2300
Wire Wire Line
	1750 2300 1750 3050
Wire Wire Line
	1950 3750 1750 3750
Connection ~ 1750 3750
Wire Wire Line
	1750 3750 1750 4350
Wire Wire Line
	1950 4350 1750 4350
Connection ~ 1750 4350
$Comp
L Device:R R3
U 1 1 5FE902E0
P 3700 2250
F 0 "R3" V 3700 2250 50  0000 C CNN
F 1 "68 ohms" V 3650 2650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 2250 50  0001 C CNN
F 3 "~" H 3700 2250 50  0001 C CNN
	1    3700 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5FE91CFD
P 3700 2400
F 0 "R4" V 3700 2400 50  0000 C CNN
F 1 "1 ohm" V 3650 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 2400 50  0001 C CNN
F 3 "~" H 3700 2400 50  0001 C CNN
	1    3700 2400
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5FE921D9
P 3700 2550
F 0 "R5" V 3700 2550 50  0000 C CNN
F 1 "1 ohm" V 3650 2950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 2550 50  0001 C CNN
F 3 "~" H 3700 2550 50  0001 C CNN
	1    3700 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 2300 3200 2300
Wire Wire Line
	3200 2300 3200 2250
Wire Wire Line
	3200 2250 3350 2250
Wire Wire Line
	3050 2400 3250 2400
Wire Wire Line
	1950 2400 1950 2550
Wire Wire Line
	1950 2550 3150 2550
$Comp
L Device:R R11
U 1 1 5FE9ED85
P 3700 4000
F 0 "R11" V 3700 4000 50  0000 C CNN
F 1 "1 ohm" V 3650 4300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 4000 50  0001 C CNN
F 3 "~" H 3700 4000 50  0001 C CNN
	1    3700 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R R12
U 1 1 5FE9ED8B
P 3700 4300
F 0 "R12" V 3700 4300 50  0000 C CNN
F 1 "68 ohms" V 3650 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 4300 50  0001 C CNN
F 3 "~" H 3700 4300 50  0001 C CNN
	1    3700 4300
	0    1    1    0   
$EndComp
$Comp
L Device:R R13
U 1 1 5FE9ED91
P 3700 4450
F 0 "R13" V 3700 4450 50  0000 C CNN
F 1 "1 ohm" V 3650 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 4450 50  0001 C CNN
F 3 "~" H 3700 4450 50  0001 C CNN
	1    3700 4450
	0    1    1    0   
$EndComp
$Comp
L Device:R R14
U 1 1 5FE9ED97
P 3700 4600
F 0 "R14" V 3700 4600 50  0000 C CNN
F 1 "1 ohm" V 3650 4900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 4600 50  0001 C CNN
F 3 "~" H 3700 4600 50  0001 C CNN
	1    3700 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 3050 3250 3050
Wire Wire Line
	3250 3050 3250 3000
Wire Wire Line
	3250 3000 3300 3000
Wire Wire Line
	3050 3150 3150 3150
Wire Wire Line
	1950 3150 1950 3300
Wire Wire Line
	1950 3300 3050 3300
Wire Wire Line
	3050 3750 3100 3750
Wire Wire Line
	3300 3750 3300 3700
Wire Wire Line
	3300 3700 3550 3700
Wire Wire Line
	3050 3850 3400 3850
Wire Wire Line
	1950 3850 1950 4000
Wire Wire Line
	1950 4000 3050 4000
Wire Wire Line
	3050 4350 3250 4350
Wire Wire Line
	3250 4350 3250 4300
Wire Wire Line
	3250 4300 3550 4300
Wire Wire Line
	3050 4450 3300 4450
Wire Wire Line
	1950 4450 1950 4600
Wire Wire Line
	1950 4600 3050 4600
Wire Wire Line
	3850 2250 5000 2250
Wire Wire Line
	3850 2400 4850 2400
Wire Wire Line
	3850 2550 4700 2550
Wire Wire Line
	3850 3700 4250 3700
Wire Wire Line
	4250 3700 4250 3600
Wire Wire Line
	4250 3600 5000 3600
Wire Wire Line
	4400 3850 4400 3700
Wire Wire Line
	4400 3700 5000 3700
Wire Wire Line
	3850 4000 5000 4000
Wire Wire Line
	5000 4000 5000 4400
Wire Wire Line
	5000 4400 5300 4400
Wire Wire Line
	3850 4300 4850 4300
Wire Wire Line
	4850 4500 5400 4500
Wire Wire Line
	5400 4500 5400 4400
Wire Wire Line
	4700 4450 4700 4550
Wire Wire Line
	4700 4550 5500 4550
Wire Wire Line
	5500 4550 5500 4400
Wire Wire Line
	3850 4600 5600 4600
Wire Wire Line
	5600 4600 5600 4400
$Comp
L SamacSys_Parts:150066M173000 LED5
U 1 1 5FE8BECB
P 8650 2400
F 0 "LED5" H 9200 2665 50  0000 C CNN
F 1 "150066M173000" H 9200 2574 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 9600 2500 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 9600 2400 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 9600 2300 50  0001 L CNN "Description"
F 5 "0.5" H 9600 2200 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 9600 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 9600 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 9600 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 9600 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 9600 1700 50  0001 L CNN "Arrow Part Number"
F 11 "" H 9600 1600 50  0001 L CNN "Arrow Price/Stock"
	1    8650 2400
	1    0    0    -1  
$EndComp
$Comp
L SamacSys_Parts:150066M173000 LED7
U 1 1 5FE8BEAF
P 8650 3850
F 0 "LED7" H 9200 4115 50  0000 C CNN
F 1 "150066M173000" H 9200 4024 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 9600 3950 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 9600 3850 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 9600 3750 50  0001 L CNN "Description"
F 5 "0.5" H 9600 3650 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 9600 3550 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 9600 3450 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 9600 3350 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 9600 3250 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 9600 3150 50  0001 L CNN "Arrow Part Number"
F 11 "" H 9600 3050 50  0001 L CNN "Arrow Price/Stock"
	1    8650 3850
	1    0    0    -1  
$EndComp
$Comp
L SamacSys_Parts:150066M173000 LED8
U 1 1 5FE8BEA1
P 8650 4450
F 0 "LED8" H 9200 4715 50  0000 C CNN
F 1 "150066M173000" H 9200 4624 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 9600 4550 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 9600 4450 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 9600 4350 50  0001 L CNN "Description"
F 5 "0.5" H 9600 4250 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 9600 4150 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 9600 4050 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 9600 3950 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 9600 3850 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 9600 3750 50  0001 L CNN "Arrow Part Number"
F 11 "" H 9600 3650 50  0001 L CNN "Arrow Price/Stock"
	1    8650 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 2500 9950 2500
Connection ~ 9950 2500
Connection ~ 9950 3950
Wire Wire Line
	9950 3950 9950 4550
$Comp
L Device:R R16
U 1 1 5FF8933F
P 7900 2250
F 0 "R16" V 7900 2250 50  0000 C CNN
F 1 "1 ohm" V 7850 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 2250 50  0001 C CNN
F 3 "~" H 7900 2250 50  0001 C CNN
	1    7900 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R17
U 1 1 5FF89345
P 7900 2400
F 0 "R17" V 7900 2400 50  0000 C CNN
F 1 "1 ohm" V 7850 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 2400 50  0001 C CNN
F 3 "~" H 7900 2400 50  0001 C CNN
	1    7900 2400
	0    1    1    0   
$EndComp
$Comp
L Device:R R18
U 1 1 5FF8934B
P 7900 2550
F 0 "R18" V 7900 2550 50  0000 C CNN
F 1 "68 ohms" V 7850 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 2550 50  0001 C CNN
F 3 "~" H 7900 2550 50  0001 C CNN
	1    7900 2550
	0    1    1    0   
$EndComp
$Comp
L Device:R R22
U 1 1 5FF89363
P 7900 3700
F 0 "R22" V 7900 3700 50  0000 C CNN
F 1 "1 ohm" V 7850 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 3700 50  0001 C CNN
F 3 "~" H 7900 3700 50  0001 C CNN
	1    7900 3700
	0    1    1    0   
$EndComp
$Comp
L Device:R R23
U 1 1 5FF89369
P 7900 3850
F 0 "R23" V 7900 3850 50  0000 C CNN
F 1 "1 ohm" V 7850 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 3850 50  0001 C CNN
F 3 "~" H 7900 3850 50  0001 C CNN
	1    7900 3850
	0    1    1    0   
$EndComp
$Comp
L Device:R R24
U 1 1 5FF8936F
P 7900 4000
F 0 "R24" V 7900 4000 50  0000 C CNN
F 1 "68 ohms" V 7850 3600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 4000 50  0001 C CNN
F 3 "~" H 7900 4000 50  0001 C CNN
	1    7900 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R R25
U 1 1 5FF89375
P 7900 4300
F 0 "R25" V 7900 4300 50  0000 C CNN
F 1 "1 ohm" V 7850 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 4300 50  0001 C CNN
F 3 "~" H 7900 4300 50  0001 C CNN
	1    7900 4300
	0    1    1    0   
$EndComp
$Comp
L Device:R R26
U 1 1 5FF8937B
P 7900 4450
F 0 "R26" V 7900 4450 50  0000 C CNN
F 1 "1 ohm" V 7850 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 4450 50  0001 C CNN
F 3 "~" H 7900 4450 50  0001 C CNN
	1    7900 4450
	0    1    1    0   
$EndComp
$Comp
L Device:R R27
U 1 1 5FF89381
P 7900 4600
F 0 "R27" V 7900 4600 50  0000 C CNN
F 1 "68 ohms" V 7850 4200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 4600 50  0001 C CNN
F 3 "~" H 7900 4600 50  0001 C CNN
	1    7900 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	8650 2400 8300 2400
Wire Wire Line
	8650 3850 8350 3850
Wire Wire Line
	8650 4450 8400 4450
Wire Wire Line
	9750 2400 9750 2250
Wire Wire Line
	9750 2250 8400 2250
Wire Wire Line
	8650 2500 8400 2500
Wire Wire Line
	8400 2500 8400 2550
Wire Wire Line
	8400 2550 8150 2550
Wire Wire Line
	8650 3950 8400 3950
Wire Wire Line
	8400 3950 8400 4000
Wire Wire Line
	8400 4000 8200 4000
Wire Wire Line
	8650 4550 8400 4550
Wire Wire Line
	8400 4550 8400 4600
Wire Wire Line
	8400 4600 8200 4600
Wire Wire Line
	9750 3850 9750 3700
Wire Wire Line
	9750 3700 8300 3700
Wire Wire Line
	9750 4450 9750 4300
Wire Wire Line
	9750 4300 8300 4300
Wire Wire Line
	6400 3600 7050 3600
Wire Wire Line
	6400 3700 6950 3700
Wire Wire Line
	6500 4400 6000 4400
Wire Wire Line
	6650 4500 5900 4500
Wire Wire Line
	5900 4500 5900 4400
Wire Wire Line
	6800 4550 5800 4550
Wire Wire Line
	5800 4550 5800 4400
Wire Wire Line
	6400 2250 7750 2250
Wire Wire Line
	6550 2400 7750 2400
Wire Wire Line
	7750 2550 6700 2550
Wire Wire Line
	7050 3600 7050 3700
Wire Wire Line
	7050 3700 7750 3700
Wire Wire Line
	6950 3700 6950 3850
Wire Wire Line
	6950 3850 7750 3850
Wire Wire Line
	6500 4000 7750 4000
Wire Wire Line
	6500 4000 6500 4400
Wire Wire Line
	6650 4300 7750 4300
Wire Wire Line
	6650 4300 6650 4500
Wire Wire Line
	6800 4450 7750 4450
Wire Wire Line
	6800 4450 6800 4550
Wire Wire Line
	7750 4600 5700 4600
Wire Wire Line
	5700 4600 5700 4400
Text GLabel 5300 2050 1    50   Input ~ 0
GND
$Comp
L Device:C C1
U 1 1 6004428A
P 5650 1500
F 0 "C1" V 5902 1500 50  0000 C CNN
F 1 "1µF" V 5811 1500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5688 1350 50  0001 C CNN
F 3 "~" H 5650 1500 50  0001 C CNN
	1    5650 1500
	0    -1   -1   0   
$EndComp
Text GLabel 7100 1500 2    50   Input ~ 0
GND
$Comp
L Device:R R15
U 1 1 600AFC01
P 5650 1800
F 0 "R15" V 5650 1800 50  0000 C CNN
F 1 "3.6k" V 5534 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5580 1800 50  0001 C CNN
F 3 "~" H 5650 1800 50  0001 C CNN
	1    5650 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 1500 5500 1500
Wire Wire Line
	5800 1800 5800 1500
Connection ~ 5800 1500
$Comp
L Device:C C2
U 1 1 600E7548
P 6450 1850
F 0 "C2" V 6198 1850 50  0000 C CNN
F 1 "1µF" V 6289 1850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6488 1700 50  0001 C CNN
F 3 "~" H 6450 1850 50  0001 C CNN
	1    6450 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 1850 6600 1500
Connection ~ 6600 1500
Wire Wire Line
	5800 1500 6600 1500
Wire Wire Line
	5900 1850 6300 1850
Wire Wire Line
	5900 1850 5900 1750
Connection ~ 5900 1850
Wire Wire Line
	5300 2050 5300 2300
Wire Wire Line
	5400 1500 5400 2300
Wire Wire Line
	5500 1800 5500 2300
Wire Wire Line
	5900 1850 5900 2300
Wire Wire Line
	6600 1500 6800 1500
Wire Wire Line
	6800 1950 6800 1500
Connection ~ 6800 1500
Wire Wire Line
	6800 1500 7100 1500
Wire Wire Line
	6100 2300 6000 2300
Wire Wire Line
	6100 2300 6100 1950
Wire Wire Line
	6100 1950 6800 1950
Text GLabel 5600 2150 1    50   Input ~ 0
EN
Text GLabel 5700 2150 1    50   Input ~ 0
SCL
Text GLabel 5800 2150 1    50   Input ~ 0
SDA
Wire Wire Line
	5600 2300 5600 2150
Wire Wire Line
	5700 2300 5700 2150
Wire Wire Line
	5800 2300 5800 2150
Text GLabel 5900 1750 1    50   Input ~ 0
3V3
Text GLabel 4050 5950 0    50   Input ~ 0
EN
Text GLabel 4050 5800 0    50   Input ~ 0
SCL
Text GLabel 4050 5700 0    50   Input ~ 0
SDA
$Comp
L Device:R R1
U 1 1 6019C315
P 4350 5350
F 0 "R1" V 4350 5350 50  0000 C CNN
F 1 "4.7k" V 4250 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4280 5350 50  0001 C CNN
F 3 "~" H 4350 5350 50  0001 C CNN
	1    4350 5350
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 601A2AE0
P 4950 5350
F 0 "R2" V 4950 5350 50  0000 C CNN
F 1 "4.7k" V 4834 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4880 5350 50  0001 C CNN
F 3 "~" H 4950 5350 50  0001 C CNN
	1    4950 5350
	-1   0    0    1   
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 6032B22B
P 7850 5200
F 0 "H1" H 7950 5246 50  0000 L CNN
F 1 "MountingHole" H 7950 5155 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 7850 5200 50  0001 C CNN
F 3 "~" H 7850 5200 50  0001 C CNN
	1    7850 5200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 6032C266
P 8750 5200
F 0 "H3" H 8850 5246 50  0000 L CNN
F 1 "MountingHole" H 8850 5155 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 8750 5200 50  0001 C CNN
F 3 "~" H 8750 5200 50  0001 C CNN
	1    8750 5200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 60334AAF
P 7850 5500
F 0 "H2" H 7950 5546 50  0000 L CNN
F 1 "MountingHole" H 7950 5455 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 7850 5500 50  0001 C CNN
F 3 "~" H 7850 5500 50  0001 C CNN
	1    7850 5500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 60334AB5
P 8750 5500
F 0 "H4" H 8850 5546 50  0000 L CNN
F 1 "MountingHole" H 8850 5455 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 8750 5500 50  0001 C CNN
F 3 "~" H 8750 5500 50  0001 C CNN
	1    8750 5500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H5
U 1 1 6033D102
P 7850 5750
F 0 "H5" H 7950 5796 50  0000 L CNN
F 1 "MountingHole" H 7950 5705 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 7850 5750 50  0001 C CNN
F 3 "~" H 7850 5750 50  0001 C CNN
	1    7850 5750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H7
U 1 1 6033D108
P 8750 5750
F 0 "H7" H 8850 5796 50  0000 L CNN
F 1 "MountingHole" H 8850 5705 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 8750 5750 50  0001 C CNN
F 3 "~" H 8750 5750 50  0001 C CNN
	1    8750 5750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H6
U 1 1 6033D10E
P 7850 6050
F 0 "H6" H 7950 6096 50  0000 L CNN
F 1 "MountingHole" H 7950 6005 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 7850 6050 50  0001 C CNN
F 3 "~" H 7850 6050 50  0001 C CNN
	1    7850 6050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H8
U 1 1 6033D114
P 8750 6050
F 0 "H8" H 8850 6096 50  0000 L CNN
F 1 "MountingHole" H 8850 6005 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.1mm" H 8750 6050 50  0001 C CNN
F 3 "~" H 8750 6050 50  0001 C CNN
	1    8750 6050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x19_Female J1
U 1 1 5FE3D4AB
P 1600 6400
F 0 "J1" H 1628 6426 50  0000 L CNN
F 1 "ESP32_Conn_left" H 850 7550 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x19_P2.54mm_Vertical" H 1600 6400 50  0001 C CNN
F 3 "~" H 1600 6400 50  0001 C CNN
	1    1600 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 5500 2250 5500
Text GLabel 2250 5500 2    50   Input ~ 0
3V3
$Comp
L Connector:Conn_01x19_Female J2
U 1 1 5FEBF898
P 1850 6400
F 0 "J2" H 1742 5275 50  0000 C CNN
F 1 "ESP32_Conn_right" H 1742 5366 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x19_P2.54mm_Vertical" H 1850 6400 50  0001 C CNN
F 3 "~" H 1850 6400 50  0001 C CNN
	1    1850 6400
	-1   0    0    1   
$EndComp
Text GLabel 2200 6800 2    50   Input ~ 0
GND
Wire Wire Line
	2200 6800 2050 6800
Text GLabel 1200 6200 0    50   Input ~ 0
SCL_ESP
Wire Wire Line
	1200 6200 1400 6200
Text GLabel 5700 5800 2    50   Input ~ 0
SCL_ESP
Wire Wire Line
	1200 6300 1400 6300
Text GLabel 1200 6300 0    50   Input ~ 0
SDA_ESP
Text GLabel 5700 5700 2    50   Input ~ 0
SDA_ESP
$Comp
L Connector:Conn_01x09_Female J3
U 1 1 5FE5D829
P 4400 6900
F 0 "J3" H 4428 6926 50  0000 L CNN
F 1 "ADXL345_Conn" H 4428 6835 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x09_P2.54mm_Vertical" H 4400 6900 50  0001 C CNN
F 3 "~" H 4400 6900 50  0001 C CNN
	1    4400 6900
	1    0    0    -1  
$EndComp
Wire Notes Line
	3600 7350 5000 7350
Wire Notes Line
	5000 7350 5000 6300
Wire Notes Line
	5000 6300 3600 6300
Wire Notes Line
	3600 6300 3600 7350
Wire Notes Line
	5150 6250 5150 7350
Wire Notes Line
	650  7550 2800 7550
Wire Notes Line
	2800 7550 2800 5100
Wire Notes Line
	2800 5100 650  5100
Wire Notes Line
	650  5100 650  7550
Text Notes 1600 7500 0    50   ~ 0
ESP32
Text Notes 4100 6400 0    50   ~ 0
ADXL345
Text Notes 5600 6350 0    50   ~ 0
TCS34725
Wire Notes Line
	7700 5050 7700 6250
Wire Notes Line
	7700 6250 9650 6250
Wire Notes Line
	9650 6250 9650 5050
Wire Notes Line
	9650 5050 7700 5050
Wire Notes Line
	8850 700  8850 1400
Wire Notes Line
	8850 1400 10300 1400
Wire Notes Line
	10300 1400 10300 700 
Wire Notes Line
	10300 700  8850 700 
Text GLabel 4000 6700 0    50   Input ~ 0
GND
Wire Wire Line
	4000 6700 4200 6700
Wire Wire Line
	4000 6500 4200 6500
Text GLabel 4000 7300 0    50   Input ~ 0
SCL_ESP
Text GLabel 4000 7200 0    50   Input ~ 0
SDA_ESP
Wire Wire Line
	4000 7200 4200 7200
Wire Wire Line
	4000 7300 4200 7300
Text GLabel 5650 6900 0    50   Input ~ 0
GND
Wire Wire Line
	5650 6900 5750 6900
Text GLabel 5650 7000 0    50   Input ~ 0
3V3
Wire Wire Line
	5650 7000 5750 7000
Text GLabel 5650 6800 0    50   Input ~ 0
SCL_ESP
Text GLabel 5650 6700 0    50   Input ~ 0
SDA_ESP
Wire Wire Line
	5650 6800 5750 6800
Wire Wire Line
	5650 6700 5750 6700
$Comp
L Connector:Conn_01x04_Female J4
U 1 1 5FE3E610
P 5950 6800
F 0 "J4" H 5978 6776 50  0000 L CNN
F 1 "TCS4725_Conn_4pins" H 5978 6685 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 5950 6800 50  0001 C CNN
F 3 "~" H 5950 6800 50  0001 C CNN
	1    5950 6800
	1    0    0    -1  
$EndComp
Wire Notes Line
	6800 7350 6800 6250
Wire Notes Line
	5150 7350 6800 7350
Wire Notes Line
	5150 6250 6800 6250
$Comp
L 629:629 J5
U 1 1 5FE71CCF
P 1150 850
F 0 "J5" H 908 1115 50  0000 C CNN
F 1 "629" H 908 1024 50  0000 C CNN
F 2 "keystone_629:Keystone-629-0" H 1150 1250 50  0001 L CNN
F 3 "http://www.mouser.com/ds/2/215/29-743118.pdf" H 1150 1350 50  0001 L CNN
F 4 "Conn" H 1150 1450 50  0001 L CNN "category"
F 5 "CONTACT BATT NEG SPRING AA/AAA/N" H 1150 1550 50  0001 L CNN "digikey description"
F 6 "36-629-ND" H 1150 1650 50  0001 L CNN "digikey part number"
F 7 "yes" H 1150 1750 50  0001 L CNN "lead free"
F 8 "2f07c28bba71dd29" H 1150 1850 50  0001 L CNN "library id"
F 9 "Keystone" H 1150 1950 50  0001 L CNN "manufacturer"
F 10 "534-629" H 1150 2050 50  0001 L CNN "mouser part number"
F 11 "PTH_BATT_CONTACT" H 1150 2150 50  0001 L CNN "package"
F 12 "yes" H 1150 2250 50  0001 L CNN "rohs"
	1    1150 850 
	1    0    0    -1  
$EndComp
$Comp
L 629:629 J6
U 1 1 5FE93200
P 1150 1300
F 0 "J6" H 908 1565 50  0000 C CNN
F 1 "629" H 908 1474 50  0000 C CNN
F 2 "keystone_629:Keystone-629-0" H 1150 1700 50  0001 L CNN
F 3 "http://www.mouser.com/ds/2/215/29-743118.pdf" H 1150 1800 50  0001 L CNN
F 4 "Conn" H 1150 1900 50  0001 L CNN "category"
F 5 "CONTACT BATT NEG SPRING AA/AAA/N" H 1150 2000 50  0001 L CNN "digikey description"
F 6 "36-629-ND" H 1150 2100 50  0001 L CNN "digikey part number"
F 7 "yes" H 1150 2200 50  0001 L CNN "lead free"
F 8 "2f07c28bba71dd29" H 1150 2300 50  0001 L CNN "library id"
F 9 "Keystone" H 1150 2400 50  0001 L CNN "manufacturer"
F 10 "534-629" H 1150 2500 50  0001 L CNN "mouser part number"
F 11 "PTH_BATT_CONTACT" H 1150 2600 50  0001 L CNN "package"
F 12 "yes" H 1150 2700 50  0001 L CNN "rohs"
	1    1150 1300
	1    0    0    -1  
$EndComp
$Comp
L 629:629 J7
U 1 1 5FE9E568
P 1850 1100
F 0 "J7" H 1522 1054 50  0000 R CNN
F 1 "637" H 1522 1145 50  0000 R CNN
F 2 "keystone_637:Keystone-637-0" H 1850 1600 50  0001 L CNN
F 3 "http://www.mouser.com/ds/2/215/37-743119.pdf" H 1850 1700 50  0001 L CNN
F 4 "Conn" H 1850 1800 50  0001 L CNN "category"
F 5 "CONTACT BATT POSITIVE AA/AAA/N" H 1850 1900 50  0001 L CNN "digikey description"
F 6 "36-637-ND" H 1850 2000 50  0001 L CNN "digikey part number"
F 7 "yes" H 1850 2100 50  0001 L CNN "is connector"
F 8 "yes" H 1850 2200 50  0001 L CNN "is male"
F 9 "yes" H 1850 2300 50  0001 L CNN "lead free"
F 10 "1060b6acdef18e55" H 1850 2400 50  0001 L CNN "library id"
F 11 "Keystone" H 1850 2500 50  0001 L CNN "manufacturer"
F 12 "534-637" H 1850 2600 50  0001 L CNN "mouser part number"
F 13 "PTH_BATT_CONN" H 1850 2700 50  0001 L CNN "package"
F 14 "yes" H 1850 2800 50  0001 L CNN "rohs"
	1    1850 1100
	-1   0    0    1   
$EndComp
Text GLabel 1150 850  2    50   Input ~ 0
GND
Text GLabel 1150 1300 2    50   Input ~ 0
GND
Wire Wire Line
	1050 850  1150 850 
Wire Wire Line
	1050 1300 1150 1300
Connection ~ 9950 3250
Wire Wire Line
	9950 3250 9950 3950
Wire Wire Line
	9950 3250 9950 2500
Wire Wire Line
	4850 4300 4850 4500
Wire Wire Line
	3850 4450 4700 4450
Wire Wire Line
	7050 3300 7050 3500
Wire Wire Line
	7050 3300 7750 3300
Wire Wire Line
	6950 3150 6950 3400
Wire Wire Line
	6950 3150 7750 3150
Wire Wire Line
	6850 3000 6850 3300
Wire Wire Line
	6850 3000 7750 3000
Wire Wire Line
	6700 2550 6700 3200
Wire Wire Line
	6550 2400 6550 3100
Wire Wire Line
	6400 2250 6400 3000
Wire Wire Line
	6400 3500 7050 3500
Wire Wire Line
	6400 3400 6950 3400
Wire Wire Line
	6400 3300 6850 3300
Wire Wire Line
	6400 3200 6700 3200
Wire Wire Line
	6400 3100 6550 3100
Wire Wire Line
	9750 3000 8300 3000
Wire Wire Line
	9750 3150 9750 3000
Wire Wire Line
	8400 3300 8250 3300
Wire Wire Line
	8400 3250 8400 3300
Wire Wire Line
	8650 3250 8400 3250
Wire Wire Line
	8650 3150 8450 3150
$Comp
L Device:R R21
U 1 1 5FF8935D
P 7900 3300
F 0 "R21" V 7900 3300 50  0000 C CNN
F 1 "68 ohms" V 7850 2900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 3300 50  0001 C CNN
F 3 "~" H 7900 3300 50  0001 C CNN
	1    7900 3300
	0    1    1    0   
$EndComp
$Comp
L Device:R R20
U 1 1 5FF89357
P 7900 3150
F 0 "R20" V 7900 3150 50  0000 C CNN
F 1 "1 ohm" V 7850 2700 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 3150 50  0001 C CNN
F 3 "~" H 7900 3150 50  0001 C CNN
	1    7900 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R19
U 1 1 5FF89351
P 7900 3000
F 0 "R19" V 7900 3000 50  0000 C CNN
F 1 "1 ohm" V 7850 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 3000 50  0001 C CNN
F 3 "~" H 7900 3000 50  0001 C CNN
	1    7900 3000
	0    1    1    0   
$EndComp
$Comp
L SamacSys_Parts:150066M173000 LED6
U 1 1 5FE8BEBD
P 8650 3150
F 0 "LED6" H 9200 3415 50  0000 C CNN
F 1 "150066M173000" H 9200 3324 50  0000 C CNN
F 2 "SamacSys_Parts:150066M173000" H 9600 3250 50  0001 L CNN
F 3 "https://katalog.we-online.de/led/datasheet/150066M173000.pdf" H 9600 3150 50  0001 L CNN
F 4 "WL-SFCW Full-color Chip LED waterclear" H 9600 3050 50  0001 L CNN "Description"
F 5 "0.5" H 9600 2950 50  0001 L CNN "Height"
F 6 "Wurth Elektronik" H 9600 2850 50  0001 L CNN "Manufacturer_Name"
F 7 "150066M173000" H 9600 2750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "710-150066M173000" H 9600 2650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/150066M173000?qs=5aG0NVq1C4zCKiw%252BI5627A%3D%3D" H 9600 2550 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 9600 2450 50  0001 L CNN "Arrow Part Number"
F 11 "" H 9600 2350 50  0001 L CNN "Arrow Price/Stock"
	1    8650 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3500 5000 3500
Wire Wire Line
	4250 3300 4250 3500
Wire Wire Line
	3850 3300 4250 3300
Wire Wire Line
	4400 3400 5000 3400
Wire Wire Line
	4400 3150 4400 3400
Wire Wire Line
	3850 3150 4400 3150
Wire Wire Line
	4550 3300 5000 3300
Wire Wire Line
	4550 3000 4550 3300
Wire Wire Line
	3850 3000 4550 3000
Wire Wire Line
	4700 3200 5000 3200
Wire Wire Line
	4700 2550 4700 3200
Wire Wire Line
	4850 3100 5000 3100
Wire Wire Line
	4850 2400 4850 3100
Wire Wire Line
	5000 2250 5000 3000
$Comp
L Device:R R8
U 1 1 5FE998BB
P 3700 3300
F 0 "R8" V 3700 3300 50  0000 C CNN
F 1 "1 ohm" V 3650 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 3300 50  0001 C CNN
F 3 "~" H 3700 3300 50  0001 C CNN
	1    3700 3300
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5FE998B5
P 3700 3150
F 0 "R7" V 3700 3150 50  0000 C CNN
F 1 "1 ohm" V 3650 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 3150 50  0001 C CNN
F 3 "~" H 3700 3150 50  0001 C CNN
	1    3700 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5FE998AF
P 3700 3000
F 0 "R6" V 3700 3000 50  0000 C CNN
F 1 "68 ohms" V 3650 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 3000 50  0001 C CNN
F 3 "~" H 3700 3000 50  0001 C CNN
	1    3700 3000
	0    1    1    0   
$EndComp
$Comp
L SamacSys_Parts:LP5024RSMR IC1
U 1 1 5FE3FAD8
P 5000 3000
F 0 "IC1" H 5650 3000 50  0000 L CNN
F 1 "LP5024RSMR" H 5450 3150 50  0000 L CNN
F 2 "SamacSys_Parts:QFN40P400X400X100-33N-D" H 6250 3500 50  0001 L CNN
F 3 "http://www.ti.com/lit/gpn/lp5024" H 6250 3400 50  0001 L CNN
F 4 "24-Channel I2C Constant-Current RGB LED Driver" H 6250 3300 50  0001 L CNN "Description"
F 5 "1" H 6250 3200 50  0001 L CNN "Height"
F 6 "Texas Instruments" H 6250 3100 50  0001 L CNN "Manufacturer_Name"
F 7 "LP5024RSMR" H 6250 3000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "595-LP5024RSMR" H 6250 2900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/LP5024RSMR?qs=55YtniHzbhDVcrbfuIdigg%3D%3D" H 6250 2800 50  0001 L CNN "Mouser Price/Stock"
F 10 "LP5024RSMR" H 6250 2700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/lp5024rsmr/texas-instruments" H 6250 2600 50  0001 L CNN "Arrow Price/Stock"
	1    5000 3000
	1    0    0    -1  
$EndComp
Text GLabel 4000 6500 0    50   Input ~ 0
3V3
Text GLabel 1750 1100 0    50   Input ~ 0
V_BATT
Wire Notes Line
	550  550  2450 550 
Wire Notes Line
	2450 550  2450 1500
Wire Notes Line
	2450 1500 550  1500
Wire Notes Line
	550  550  550  1500
Text Notes 1750 700  0    50   ~ 0
Battery_Holder
Wire Wire Line
	1750 1100 1950 1100
Text GLabel 4650 4900 1    50   Input ~ 0
3V3
$Comp
L Jumper:SolderJumper_3_Bridged123 JP1
U 1 1 5FE8631B
P 4650 5100
F 0 "JP1" H 4650 5213 50  0000 C CNN
F 1 "SolderJumper_3_Bridged123" H 5350 5000 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm_NumberLabels" H 4650 5100 50  0001 C CNN
F 3 "~" H 4650 5100 50  0001 C CNN
	1    4650 5100
	1    0    0    1   
$EndComp
Wire Wire Line
	4450 5100 4350 5100
Wire Wire Line
	4350 5100 4350 5200
Wire Wire Line
	4850 5100 4950 5100
Wire Wire Line
	4950 5100 4950 5200
Wire Wire Line
	4650 4950 4650 4900
Wire Wire Line
	4350 5500 4350 5700
Connection ~ 4350 5700
Wire Wire Line
	4350 5700 5700 5700
Wire Wire Line
	4950 5500 4950 5800
Connection ~ 4950 5800
Wire Wire Line
	4950 5800 5700 5800
$Comp
L Device:R R28
U 1 1 5FEF6F2D
P 4500 5950
F 0 "R28" V 4500 5950 50  0000 C CNN
F 1 "150k ohm" V 4400 5950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4430 5950 50  0001 C CNN
F 3 "~" H 4500 5950 50  0001 C CNN
	1    4500 5950
	0    -1   -1   0   
$EndComp
Text GLabel 4950 5950 2    50   Input ~ 0
3V3
Wire Wire Line
	4650 5950 4950 5950
Text GLabel 1750 4850 3    50   Input ~ 0
3V3
Wire Wire Line
	1750 4350 1750 4850
Text GLabel 9950 2000 1    50   Input ~ 0
3V3
Wire Wire Line
	9950 2000 9950 2500
$Comp
L Connector:TestPoint TP29
U 1 1 5FF51967
P 8400 2250
F 0 "TP29" H 8458 2368 50  0000 L CNN
F 1 "TestPoint" H 8458 2277 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8600 2250 50  0001 C CNN
F 3 "~" H 8600 2250 50  0001 C CNN
	1    8400 2250
	1    0    0    -1  
$EndComp
Connection ~ 8400 2250
Wire Wire Line
	8400 2250 8050 2250
$Comp
L Connector:TestPoint TP24
U 1 1 5FF54186
P 8300 2400
F 0 "TP24" H 8358 2518 50  0000 L CNN
F 1 "TestPoint" H 8358 2427 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8500 2400 50  0001 C CNN
F 3 "~" H 8500 2400 50  0001 C CNN
	1    8300 2400
	1    0    0    -1  
$EndComp
Connection ~ 8300 2400
Wire Wire Line
	8300 2400 8050 2400
$Comp
L Connector:TestPoint TP20
U 1 1 5FF54C60
P 8150 2550
F 0 "TP20" H 8208 2668 50  0000 L CNN
F 1 "TestPoint" H 8208 2577 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8350 2550 50  0001 C CNN
F 3 "~" H 8350 2550 50  0001 C CNN
	1    8150 2550
	1    0    0    -1  
$EndComp
Connection ~ 8150 2550
Wire Wire Line
	8150 2550 8050 2550
$Comp
L Connector:TestPoint TP25
U 1 1 5FF55A44
P 8300 3000
F 0 "TP25" H 8358 3118 50  0000 L CNN
F 1 "TestPoint" H 8358 3027 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8500 3000 50  0001 C CNN
F 3 "~" H 8500 3000 50  0001 C CNN
	1    8300 3000
	1    0    0    -1  
$EndComp
Connection ~ 8300 3000
Wire Wire Line
	8300 3000 8050 3000
$Comp
L Connector:TestPoint TP31
U 1 1 5FF564CB
P 8450 3150
F 0 "TP31" H 8508 3268 50  0000 L CNN
F 1 "TestPoint" H 8508 3177 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8650 3150 50  0001 C CNN
F 3 "~" H 8650 3150 50  0001 C CNN
	1    8450 3150
	1    0    0    -1  
$EndComp
Connection ~ 8450 3150
Wire Wire Line
	8450 3150 8050 3150
$Comp
L Connector:TestPoint TP23
U 1 1 5FF5669F
P 8250 3300
F 0 "TP23" H 8308 3418 50  0000 L CNN
F 1 "TestPoint" H 8308 3327 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8450 3300 50  0001 C CNN
F 3 "~" H 8450 3300 50  0001 C CNN
	1    8250 3300
	1    0    0    -1  
$EndComp
Connection ~ 8250 3300
Wire Wire Line
	8250 3300 8050 3300
$Comp
L Connector:TestPoint TP26
U 1 1 5FF56B1D
P 8300 3700
F 0 "TP26" H 8358 3818 50  0000 L CNN
F 1 "TestPoint" H 8358 3727 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8500 3700 50  0001 C CNN
F 3 "~" H 8500 3700 50  0001 C CNN
	1    8300 3700
	1    0    0    -1  
$EndComp
Connection ~ 8300 3700
Wire Wire Line
	8300 3700 8050 3700
$Comp
L Connector:TestPoint TP28
U 1 1 5FF56F59
P 8350 3850
F 0 "TP28" H 8408 3968 50  0000 L CNN
F 1 "TestPoint" H 8408 3877 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8550 3850 50  0001 C CNN
F 3 "~" H 8550 3850 50  0001 C CNN
	1    8350 3850
	1    0    0    -1  
$EndComp
Connection ~ 8350 3850
Wire Wire Line
	8350 3850 8050 3850
$Comp
L Connector:TestPoint TP21
U 1 1 5FF572FE
P 8200 4000
F 0 "TP21" H 8258 4118 50  0000 L CNN
F 1 "TestPoint" H 8258 4027 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8400 4000 50  0001 C CNN
F 3 "~" H 8400 4000 50  0001 C CNN
	1    8200 4000
	1    0    0    -1  
$EndComp
Connection ~ 8200 4000
Wire Wire Line
	8200 4000 8050 4000
$Comp
L Connector:TestPoint TP27
U 1 1 5FF57FD9
P 8300 4300
F 0 "TP27" H 8358 4418 50  0000 L CNN
F 1 "TestPoint" H 8358 4327 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8500 4300 50  0001 C CNN
F 3 "~" H 8500 4300 50  0001 C CNN
	1    8300 4300
	1    0    0    -1  
$EndComp
Connection ~ 8300 4300
Wire Wire Line
	8300 4300 8050 4300
$Comp
L Connector:TestPoint TP30
U 1 1 5FF58317
P 8400 4450
F 0 "TP30" H 8458 4568 50  0000 L CNN
F 1 "TestPoint" H 8458 4477 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8600 4450 50  0001 C CNN
F 3 "~" H 8600 4450 50  0001 C CNN
	1    8400 4450
	1    0    0    -1  
$EndComp
Connection ~ 8400 4450
Wire Wire Line
	8400 4450 8050 4450
$Comp
L Connector:TestPoint TP22
U 1 1 5FF58537
P 8200 4600
F 0 "TP22" H 8258 4718 50  0000 L CNN
F 1 "TestPoint" H 8258 4627 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 8400 4600 50  0001 C CNN
F 3 "~" H 8400 4600 50  0001 C CNN
	1    8200 4600
	1    0    0    -1  
$EndComp
Connection ~ 8200 4600
Wire Wire Line
	8200 4600 8050 4600
$Comp
L Connector:TestPoint TP15
U 1 1 5FF586E5
P 3350 2250
F 0 "TP15" H 3408 2368 50  0000 L CNN
F 1 "TestPoint" H 3408 2277 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3550 2250 50  0001 C CNN
F 3 "~" H 3550 2250 50  0001 C CNN
	1    3350 2250
	1    0    0    -1  
$EndComp
Connection ~ 3350 2250
Wire Wire Line
	3350 2250 3550 2250
$Comp
L Connector:TestPoint TP12
U 1 1 5FF58D94
P 3250 2400
F 0 "TP12" H 3308 2518 50  0000 L CNN
F 1 "TestPoint" H 3308 2427 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3450 2400 50  0001 C CNN
F 3 "~" H 3450 2400 50  0001 C CNN
	1    3250 2400
	1    0    0    -1  
$EndComp
Connection ~ 3250 2400
Wire Wire Line
	3250 2400 3550 2400
$Comp
L Connector:TestPoint TP10
U 1 1 5FF59010
P 3150 2550
F 0 "TP10" H 3208 2668 50  0000 L CNN
F 1 "TestPoint" H 3208 2577 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3350 2550 50  0001 C CNN
F 3 "~" H 3350 2550 50  0001 C CNN
	1    3150 2550
	1    0    0    -1  
$EndComp
Connection ~ 3150 2550
Wire Wire Line
	3150 2550 3550 2550
$Comp
L Connector:TestPoint TP13
U 1 1 5FF59DB6
P 3300 3000
F 0 "TP13" H 3358 3118 50  0000 L CNN
F 1 "TestPoint" H 3358 3027 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3500 3000 50  0001 C CNN
F 3 "~" H 3500 3000 50  0001 C CNN
	1    3300 3000
	1    0    0    -1  
$EndComp
Connection ~ 3300 3000
Wire Wire Line
	3300 3000 3550 3000
$Comp
L Connector:TestPoint TP11
U 1 1 5FF5A119
P 3150 3150
F 0 "TP11" H 3208 3268 50  0000 L CNN
F 1 "TestPoint" H 3208 3177 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3350 3150 50  0001 C CNN
F 3 "~" H 3350 3150 50  0001 C CNN
	1    3150 3150
	1    0    0    -1  
$EndComp
Connection ~ 3150 3150
Wire Wire Line
	3150 3150 3550 3150
$Comp
L Connector:TestPoint TP5
U 1 1 5FF5A2AA
P 3050 3300
F 0 "TP5" H 3108 3418 50  0000 L CNN
F 1 "TestPoint" H 3108 3327 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3250 3300 50  0001 C CNN
F 3 "~" H 3250 3300 50  0001 C CNN
	1    3050 3300
	1    0    0    -1  
$EndComp
Connection ~ 3050 3300
Wire Wire Line
	3050 3300 3550 3300
$Comp
L Connector:TestPoint TP9
U 1 1 5FF5BBD5
P 3100 3750
F 0 "TP9" H 3158 3868 50  0000 L CNN
F 1 "TestPoint" H 3158 3777 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3300 3750 50  0001 C CNN
F 3 "~" H 3300 3750 50  0001 C CNN
	1    3100 3750
	1    0    0    -1  
$EndComp
Connection ~ 3100 3750
Wire Wire Line
	3100 3750 3300 3750
$Comp
L Connector:TestPoint TP16
U 1 1 5FF5C03C
P 3400 3850
F 0 "TP16" H 3458 3968 50  0000 L CNN
F 1 "TestPoint" H 3458 3877 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3600 3850 50  0001 C CNN
F 3 "~" H 3600 3850 50  0001 C CNN
	1    3400 3850
	1    0    0    -1  
$EndComp
Connection ~ 3400 3850
Wire Wire Line
	3400 3850 3550 3850
$Comp
L Connector:TestPoint TP6
U 1 1 5FF5C2FC
P 3050 4000
F 0 "TP6" H 3108 4118 50  0000 L CNN
F 1 "TestPoint" H 3108 4027 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3250 4000 50  0001 C CNN
F 3 "~" H 3250 4000 50  0001 C CNN
	1    3050 4000
	1    0    0    -1  
$EndComp
Connection ~ 3050 4000
Wire Wire Line
	3050 4000 3550 4000
$Comp
L Connector:TestPoint TP7
U 1 1 5FF5CEC0
P 3050 4350
F 0 "TP7" H 3108 4468 50  0000 L CNN
F 1 "TestPoint" H 2900 4550 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3250 4350 50  0001 C CNN
F 3 "~" H 3250 4350 50  0001 C CNN
	1    3050 4350
	1    0    0    -1  
$EndComp
Connection ~ 3050 4350
$Comp
L Connector:TestPoint TP14
U 1 1 5FF5D584
P 3300 4450
F 0 "TP14" H 3358 4568 50  0000 L CNN
F 1 "TestPoint" H 3358 4477 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3500 4450 50  0001 C CNN
F 3 "~" H 3500 4450 50  0001 C CNN
	1    3300 4450
	1    0    0    -1  
$EndComp
Connection ~ 3300 4450
Wire Wire Line
	3300 4450 3550 4450
$Comp
L Connector:TestPoint TP8
U 1 1 5FF5D830
P 3050 4600
F 0 "TP8" H 3108 4718 50  0000 L CNN
F 1 "TestPoint" H 3108 4627 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3250 4600 50  0001 C CNN
F 3 "~" H 3250 4600 50  0001 C CNN
	1    3050 4600
	1    0    0    -1  
$EndComp
Connection ~ 3050 4600
Wire Wire Line
	3050 4600 3550 4600
Wire Notes Line
	2750 650  2750 1550
Wire Notes Line
	2750 1550 5050 1550
Wire Notes Line
	5050 1550 5050 650 
Wire Notes Line
	5050 650  2750 650 
Text Notes 4350 750  0    50   ~ 0
Voltage_Regulator
Text GLabel 3100 1050 0    50   Input ~ 0
V_BATT
$Comp
L SamacSys_Parts:LMS1585AISX-3.3_NO IC2
U 1 1 5FEDB7FE
P 4700 1050
F 0 "IC2" H 5350 1315 50  0000 C CNN
F 1 "LMS1585AISX-3.3_NO" H 5350 1224 50  0000 C CNN
F 2 "SamacSys_Parts:KTT0003B" H 5850 1150 50  0001 L CNN
F 3 "http://www.ti.com/lit/gpn/LMS1585A" H 5850 1050 50  0001 L CNN
F 4 "5A Fixed / Adjustable Output Linear Regulators / LDO" H 5850 950 50  0001 L CNN "Description"
F 5 "" H 5850 850 50  0001 L CNN "Height"
F 6 "595-LMS1585AISX33/NO" H 5850 750 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/LMS1585AISX-33-NO/?qs=Mv7BduZupUgcTszQb%252BDdgQ%3D%3D" H 5850 650 50  0001 L CNN "Mouser Price/Stock"
F 8 "Texas Instruments" H 5850 550 50  0001 L CNN "Manufacturer_Name"
F 9 "LMS1585AISX-3.3/NO" H 5850 450 50  0001 L CNN "Manufacturer_Part_Number"
	1    4700 1050
	-1   0    0    -1  
$EndComp
Text GLabel 3000 1150 0    50   Input ~ 0
3V3
$Comp
L Device:C C3
U 1 1 5FEDBE7B
P 3250 900
F 0 "C3" V 2998 900 50  0000 C CNN
F 1 "10 µF" V 3089 900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3288 750 50  0001 C CNN
F 3 "~" H 3250 900 50  0001 C CNN
	1    3250 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5FEF985A
P 3250 1300
F 0 "C4" V 2998 1300 50  0000 C CNN
F 1 "10 µF" V 3089 1300 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3288 1150 50  0001 C CNN
F 3 "~" H 3250 1300 50  0001 C CNN
	1    3250 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1050 3250 1050
Wire Wire Line
	3250 1050 3400 1050
Connection ~ 3250 1050
Wire Wire Line
	3400 1150 3250 1150
Wire Wire Line
	3000 1150 3250 1150
Connection ~ 3250 1150
Text GLabel 3350 700  2    50   Input ~ 0
GND
Text GLabel 3400 1500 2    50   Input ~ 0
GND
Text GLabel 4800 1050 2    50   Input ~ 0
GND
Wire Wire Line
	4700 1050 4800 1050
Wire Wire Line
	3250 750  3250 700 
Wire Wire Line
	3250 700  3350 700 
Wire Wire Line
	3250 1450 3250 1500
Wire Wire Line
	3250 1500 3400 1500
NoConn ~ 4700 1150
NoConn ~ 4200 6600
NoConn ~ 4200 6800
NoConn ~ 4200 6900
NoConn ~ 4200 7000
NoConn ~ 4200 7100
NoConn ~ 1400 5500
NoConn ~ 1400 5600
NoConn ~ 1400 5700
NoConn ~ 1400 5800
NoConn ~ 1400 5900
NoConn ~ 1400 6000
NoConn ~ 1400 6100
NoConn ~ 2050 5600
NoConn ~ 2050 5700
NoConn ~ 2050 5800
NoConn ~ 2050 5900
NoConn ~ 2050 6000
NoConn ~ 2050 6100
NoConn ~ 2050 6200
NoConn ~ 1400 6400
NoConn ~ 1400 6500
NoConn ~ 1400 6600
NoConn ~ 1400 6700
NoConn ~ 1400 6800
NoConn ~ 1400 6900
NoConn ~ 1400 7000
NoConn ~ 1400 7100
NoConn ~ 1400 7200
NoConn ~ 1400 7300
NoConn ~ 2050 6300
NoConn ~ 2050 6400
NoConn ~ 2050 6500
NoConn ~ 2050 6600
NoConn ~ 2050 6700
NoConn ~ 2050 6900
NoConn ~ 2050 7000
NoConn ~ 2050 7100
NoConn ~ 2050 7200
NoConn ~ 2050 7300
Wire Wire Line
	9750 4550 9950 4550
Wire Wire Line
	9750 3950 9950 3950
Wire Wire Line
	9750 3250 9950 3250
Wire Wire Line
	4050 5950 4350 5950
Wire Wire Line
	4050 5700 4350 5700
Wire Wire Line
	4050 5800 4950 5800
Wire Wire Line
	3850 3850 4400 3850
$Comp
L Device:R R10
U 1 1 5FE9ED7F
P 3700 3850
F 0 "R10" V 3700 3850 50  0000 C CNN
F 1 "1 ohm" V 3650 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 3850 50  0001 C CNN
F 3 "~" H 3700 3850 50  0001 C CNN
	1    3700 3850
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 5FE9ED79
P 3700 3700
F 0 "R9" V 3700 3700 50  0000 C CNN
F 1 "68 ohms" V 3650 4050 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3630 3700 50  0001 C CNN
F 3 "~" H 3700 3700 50  0001 C CNN
	1    3700 3700
	0    1    1    0   
$EndComp
$EndSCHEMATC
