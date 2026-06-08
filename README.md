# Non-Invasive Neonatal Bilirubin Estimation System

## Project Overview
Neonatal jaundice is a common condition in newborns caused by elevated bilirubin levels. Traditional bilirubin testing methods are invasive and require blood samples.

This project presents a **Portable optical reflectance device for rapid bilirubin estimation in infants** that estimates bilirubin levels using reflected light analysis, reducing discomfort and enabling faster screening.

## Objective
To design a low-cost, non-invasive biomedical device for early detection of neonatal jaundice using optical reflectance and embedded processing.
## System Architecture

![System Architecture](system_architecture.png)

The system consists of:
- Optical sensing module (LED + photodiode / RGB sensor)
- Arduino microcontroller for signal processing
- Display unit for bilirubin output
- Alert system (buzzer for high levels)

## System Workflow
![Flow Chart](Flow_chart.png)

### Working Steps:
1. System initialization (Arduino, sensors, LCD)
2. LED light is emitted onto skin
3. Reflected light is captured using sensor
4. Arduino processes raw signal data
5. Bilirubin level is estimated using algorithm
6. Output is displayed on LCD
7. Buzzer activates if level is HIGH

## Circuit Diagram

![Circuit Diagram](circuit_diagram.jpeg)

This shows the hardware connections between:
- Arduino Uno
- Color sensor / photodiode
- LCD display module
- Buzzer alarm system
- Power supply unit

## Technologies Used
- Arduino Uno / ESP32
- Optical Sensor (Photodiode / RGB sensor)
- Embedded C (Arduino Programming)
- Basic signal processing techniques


## Repository Structure

---

## Key Features
- Non-invasive bilirubin estimation
- Real-time processing
- Portable and low-cost design
- Suitable for neonatal screening applications

---

## Author
**Abitha Ganesan**  
B.E. Biomedical Engineering Student  
Interested in biomedical signal processing and non-invasive medical devices  
GitHub: https://github.com/abithaganesan

## Note
This project is a prototype-level biomedical engineering system designed for academic and internship demonstration purposes.
