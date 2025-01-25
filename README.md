# Home-Automation-System

## Project Overview  
This project simulates an IoT-based home automation system using Tinkercad, integrating virtual sensors and actuators for real-time control. The system automates the operation of a fan (DC motor) based on temperature changes and a light (LED) based on motion detection, while also providing manual control via a slide switch and remote IoT control through Serial Monitor commands.  

## Features  
✅ Automatic Fan Control – The DC motor (fan) turns ON when the temperature (TMP36 sensor) exceeds 25°C and turns OFF otherwise.  
✅ Motion-Activated Light – The LED turns ON when the PIR sensor detects motion and turns OFF when no movement is detected.  
✅ Manual Override – A slide switch allows manual activation of the fan and light.  
✅ IoT-Based Control – Users can remotely control the fan and light using Serial Monitor commands (`FAN ON`, `FAN OFF`, `LIGHT ON`, `LIGHT OFF`) in Tinkercad.  

## Technologies Used  
- Tinkercad – Online simulation platform for Arduino projects  
- Arduino IDE – Used for coding and logic implementation  
- TMP36 Temperature Sensor – For automatic fan control  
- DC Motor (Fan) without Driver – Used for cooling automation  
- PIR Sensor – For motion-based light activation  
- LED Light – Automated lighting system  
- Slide Switch – Manual ON/OFF control  
- Serial Communication – Simulated IoT dashboard for remote control  

## Circuit Components & Connections
| Component | Pin Connections |
|---------------|------------------|
| Arduino Uno | Microcontroller |
| TMP36 Sensor | VCC → 5V, GND → GND, OUT → A0 |
| PIR Sensor | VCC → 5V, GND → GND, OUT → D2 |
| LED Light | Positive Leg → D3, Negative Leg → GND |
| DC Motor (Fan) | Positive → D5, Negative → GND |
| Slide Switch | Pin 1 → 5V, Pin 2 → D6, Pin 3 → GND |

## Code Implementation 
The Arduino code reads temperature from the TMP36 sensor and motion detection from the PIR sensor, automatically activating the fan and light as needed. It also listens for manual switch toggles and Serial Monitor commands for remote IoT control.

## Setup & Simulation Steps in Tinkercad  
1. Create a new Tinkercad circuit.  
2. Add the required components: Arduino Uno, TMP36, PIR Sensor, LED, DC Motor, Slide Switch.  
3. Make the necessary connections as per the circuit diagram.  
4. Upload the Arduino code in Tinkercad’s code editor.  
5. Run the simulation and observe the automatic and manual control mechanisms.  

## How to Use IoT Control (Serial Monitor)
- Open the **Serial Monitor** in Tinkercad.  
- Enter the following commands to control devices remotely:  
  - `"FAN ON"` → Turns ON the fan  
  - `"FAN OFF"` → Turns OFF the fan  
  - `"LIGHT ON"` → Turns ON the LED  
  - `"LIGHT OFF"` → Turns OFF the LED  

## Future Enhancements
🔹 Add Wi-Fi connectivity using an ESP8266/NodeMCU for real IoT implementation.  
🔹 Integrate a mobile app for remote control instead of Serial Monitor.  
🔹 Use a relay module to control real AC appliances instead of just virtual components.  

