# Boardoza L9110S DC Motor Driver Breakout Board

The **Boardoza L9110S Breakout Board** is a dual-channel DC motor driver board built around the **L9110S motor driver IC.** It integrates a two-channel push-pull power amplifier in a compact breakout form, enabling bidirectional control of two DC motors through simple logic-level inputs.

The board supports **TTL / CMOS compatible control signals** and features low output saturation voltage along with integrated clamp diodes for inductive load protection. These characteristics make it suitable for low-voltage motor control in **embedded systems, including robotics platforms, educational development boards, small automation projects, and basic stepper motor driving applications** where direct GPIO-based motor control is required.

## [Click here to purchase!](https://www.ozdisan.com/p/arduino-sensorleri-ve-modulleri-613/ozd-arduino-l9110s-motor-driver-603181)
| Front Side | Back Side |
| :---: | :---: |
| ![Front](./assets/L9110S%20Front.png) | ![Back](./assets/L9110S%20Back.png) |

---

## Key Features

- **Dual-Channel DC Motor Driver:** Allows independent forward and reverse control of two DC motors.
- **Wide Operating Voltage Range:** Supports motor supply voltages from **2.5 V to 12 V**.
- **High Current Capability:** Delivers up to **750–800 mA continuous current per channel** with peak currents up to **1.5 -2 A**.
- **TTL / CMOS Compatible Inputs:** Can be directly interfaced with microcontrollers and CPUs without additional level shifting.
- **Low Output Saturation Voltage:** Improves efficiency and reduces power loss during motor operation.
- **Built-in Protection Diodes:** Integrated clamp diodes protect against reverse currents from inductive loads.
- **Low Quiescent Current:** Suitable for power-sensitive and battery-operated applications.

---

## Technical Specifications

**Model:** L9110S  
**Manufacturer:** Boardoza  
**Manufacturer IC:** Generic / Multiple vendors    
**Board Type:** Dual Channel DC Motor Driver Breakout Board  
**Input Voltage Range:** 2.5 V – 12 V  
**Output Current:** 750–800 mA continuous per channel  
**Peak Current:** Up to 1.5 A  
**Logic Level Compatibility:** TTL / CMOS  
**Motor Channels:** 2 (Independent control)  
**Supported Loads:** DC motors, stepper motors, relays, inductive loads  
**Power Input Type:** 2-pin 2.50 mm connector / 2.50 mm pin header  
**Control Interface:** Direct GPIO control (A/B inputs per channel)  
**Operating Temperature:** 0 °C to +80 °C  
**Board Dimensions:** 20 mm × 40 mm

---

## Electrical Characteristics

| Symbol | Parameter            | Min  | Typical | Max  | Unit |
|:-----:|----------------------|:----:|:-------:|:----:|:----:|
| VCC   | Supply Voltage       | 2.5  | 6       | 12   | V    |
| Idd   | Quiescent Current    | —    | 0       | 2    | µA   |
| Iin   | Operating Current    | 200  | 350     | 500  | µA   |
| IC    | Continuous Current   | 750  | 800     | 850  | mA   |
| IMax  | Peak Current         | —    | 1500    | 2000 | mA   |

---

## Logical Control Table – Channel 1 (M1)

| M1_A | M1_B | A | B |
|:----:|:----:|:-:|:-:|
| H    | L    | H | L |
| L    | H    | L | H |
| L    | L    | L | L |
| H    | H    | L | L |

---

## Logical Control Table – Channel 2 (M2)

| M2_A | M2_B | A | B |
|:----:|:----:|:-:|:-:|
| H    | L    | H | L |
| L    | H    | L | H |
| L    | L    | L | L |
| H    | H    | L | L |

## Notes on Logic Levels

- **H (High):** Logic high level (TTL / CMOS compatible)
- **L (Low):** Logic low level  
- Motor direction is determined by the relative logic state of A and B inputs.
- Applying the same logic level to both inputs results in braking behavior.

---

## Board Pinout

### ( J1 ) Control & Power Connector

| Pin Number | Pin Name | Description |
| --- | --- | --- |
| 1 | VCC | Motor voltage positive input |
| 2 | M2_B | Channel 2 control input B |
| 3 | M2_A | Channel 2 control input A |
| 4 | M1_B | Channel 1 control input B |
| 5 | M1_A | Channel 1 control input A |
| 6 | GND | Ground |

### ( J4 ) Control & Power Connector (Parallel to J1)

| Pin Number | Pin Name | Description |
| --- | --- | --- |
| 1 | VCC | Motor voltage positive input |
| 2 | M2_B | Channel 2 control input B |
| 3 | M2_A | Channel 2 control input A |
| 4 | M1_B | Channel 1 control input B |
| 5 | M1_A | Channel 1 control input A |
| 6 | GND | Ground |

### ( J2 ) Motor Output – Channel 1 (M1)

| Pin Number | Pin Name | Description |
| --- | --- | --- |
| 1 | B | Motor output B (Channel 1) |
| 2 | A | Motor output A (Channel 1) |

### ( J3 ) Motor Output – Channel 2 (M2)

| Pin Number | Pin Name | Description |
| --- | --- | --- |
| 1 | B | Motor output B (Channel 2) |
| 2 | A | Motor output A (Channel 2) |

---

## Board Dimensions

<img src="./assets/L9110S Dimensions.png" alt="STM32 Black Pill Board Dimensions" width="450"/>

---

## Step Files

[Boardoza L9110S.step](./assets/L9110S%20Step.step)

---

## Datasheet

[L9110S Datasheet](./assets/L9110S%20Datasheet.pdf)

---

## Version History

- v1.0 – Initial release

---

## Support

- For questions or technical support, please contact **support@boardoza.com**

---

## **License**

This repository contains both hardware and software components:

### **Hardware Design**

[![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

All hardware design files are licensed under [Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

### **Software/Firmware**

[![BSD-3-Clause][bsd-shield]][bsd]

All software and firmware are licensed under [BSD 3-Clause License][bsd].

[bsd]: https://opensource.org/licenses/BSD-3-Clause
[bsd-shield]: https://img.shields.io/badge/License-BSD%203--Clause-blue.svg
