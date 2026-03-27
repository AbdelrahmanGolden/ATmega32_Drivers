# ATmega32_Drivers

## 📌 Overview
This repository contains my full implementation of **ATmega32 microcontroller drivers** using **C**, following a layered architecture approach:
* **MCAL (Microcontroller Abstraction Layer)**
* **HAL (Hardware Abstraction Layer)**
* **LIB (Common utilities and macros)**

The goal of this project is to build a **reusable, scalable, and structured embedded systems driver library** that can be used in real-world applications.

## 🧠 Architecture
The project is structured into three main layers:

### 🔹 MCAL (Microcontroller Abstraction Layer)
Handles direct interaction with hardware registers.
Includes drivers such as:
* DIO
* Timers
* Interrupts
* ADC
* UART
* SPI / TWI

### 🔹 HAL (Hardware Abstraction Layer)
Built on top of MCAL to interface with external components.
Examples:
* GPS
* LCD
* Keypad
* Motors

### 🔹 LIB (Libraries)
Contains reusable utilities:
* Bit manipulation macros
* Standard types
* Common helper functions

## ⚙️ Features
✅ Modular and layered design
✅ Register-level programming (no external libraries)
✅ Easy to reuse in other projects
✅ Scalable structure for adding more drivers

## 🛠️ Technologies Used
* Embedded C
* C++
* AVR Architecture
* ATmega32 Microcontroller
* Embedded Systems Concepts (MCAL / HAL layering)

## 🎯 Purpose of the Project
This project is part of my journey in mastering:
* Embedded Systems development
* Writing clean and maintainable drivers
* Understanding low-level hardware interaction
* Building reusable embedded software components

## 👨‍💻 Author
**Abdelrahman Abdelkhaliq**

Embedded Systems & ML Engineer
