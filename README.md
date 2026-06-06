# Bilirubin Estimation Device

## Project Overview
This project is a non-invasive neonatal jaundice estimation system using optical reflectance sensing. It is designed as a biomedical embedded prototype to reduce the need for blood-based bilirubin testing.

## Objective
To estimate bilirubin levels using sensor-based optical frequency analysis and microcontroller processing.

## Hardware Used
- Arduino / ESP32
- Optical sensor module
- LCD display (16x2)
- Status LED

## Working Principle
- Sensor captures reflected light intensity
- Microcontroller reads frequency signal
- Signal is averaged to reduce noise
- Calibration mapping converts signal into bilirubin estimate
- Output is displayed on LCD

## Output Classification
- Normal
- Mild
- High Risk

## Note
This is a prototype-level system for academic and research demonstration purposes.
