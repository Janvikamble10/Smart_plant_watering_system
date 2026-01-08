# Smart Plant Watering System (Embedded Systems)

## Overview
This project is an embedded system that monitors soil moisture and automatically controls a water pump to irrigate plants when the soil becomes dry.  
The system is implemented and tested using simulation tools and demonstrates core embedded concepts used in real-world control systems.

## Why This Project
This project was built to practice and demonstrate:
- Analog sensor interfacing (ADC)
- Decision-making logic using thresholds and hysteresis
- GPIO-based actuator control using a relay
- End-to-end embedded system design thinking

## System Architecture
Soil Moisture Sensor → ADC (Arduino) → Control Logic → Relay → Water Pump

## Hardware (Simulated)
- Arduino UNO
- Soil moisture sensor (analog output)
- SPDT relay
- DC motor (water pump)
- External power source for pump

## Software
- Language: C/C++
- Platform: Arduino (simulated in Tinkercad)
- Firmware located in `code/irrigation_system.ino`

## Control Logic
- If soil moisture drops below a defined dry threshold, watering starts
- If soil moisture rises above a wet threshold, watering stops
- Hysteresis is used to prevent rapid ON/OFF switching near threshold values

## Safety and Design Notes
- The pump is connected using the normally-open (NO) relay contact so it remains OFF by default
- In simulation, the relay coil is driven directly from a GPIO pin for simplicity
- In real hardware, a transistor driver and flyback diode would be used to protect the microcontroller

## Project Status
- Fully functional in simulation
- Ready for extension to real hardware or IoT-based monitoring
