# Li-Fi Based Text Communication between Two Arduino

![Li-Fi based Text Communication between Multiple Arduino](https://circuitdigest.com/sites/default/files/projectimage_mic/Li-Fi-based-Text-Communication-between-Multiple-Arduino.jpg)

## Project Overview

This project demonstrates [Li-Fi (Light Fidelity) communication between two Arduino boards](https://circuitdigest.com/microcontroller-projects/li-fi-communication-between-two-arduino)
 using visible light for data transmission. Text data is transmitted using an LED and a 4x4 keypad on the transmitter side and decoded on the receiver side using an LDR (Light Dependent Resistor). Li-Fi communication can be up to 100 times faster than traditional Wi-Fi.

## Table of Contents

- [Features](#features)
- [Components Required](#components-required)
- [What is Li-Fi?](#what-is-li-fi)
- [Circuit Diagram](#circuit-diagram)
- [Pin Configuration](#pin-configuration)
- [Installation](#installation)
- [Code Explanation](#code-explanation)
- [How It Works](#how-it-works)
- [Usage Instructions](#usage-instructions)
- [Troubleshooting](#troubleshooting)
- [Future Enhancements](#future-enhancements)

## Features

- Wireless data transmission using visible light
- 16 different character transmission (0-9, *, #, A-D)
- Real-time text communication between two Arduino boards
- [LCD display](https://circuitdigest.com/microcontroller-projects/how-to-interface-16x2-lcd-with-tiva-c-series-tm4c123g-launchpad)for received data visualisation
- Simple keypad interface for input
- No radio frequency interference

## Components Required

### Transmitter Side
- Arduino UNO/Nano (1x)
- 4x4 Matrix Keypad (1x)
- 5mm [LED](https://circuitdigest.com/microcontroller-projects/interfacing-max7219-led-dot-matrix-display-with-arduino) (1x)
- 220Ω Resistor (1x)
- Breadboard
- Connecting Jumper Wires

### Receiver Side
- Arduino UNO (1x)
- LDR Sensor (1x)
- 10kΩ Resistor (1x)
- 16x2 Alphanumeric LCD Display (1x)
- I2C Interface Module for LCD (1x)
- Breadboard
- Connecting Jumper Wires

## What is Li-Fi?

Li-Fi (Light Fidelity) is an advanced wireless communication technology that uses visible light for data transmission instead of radio waves. Key advantages include:

- **High Speed:** Can be up to 100 times faster than Wi-Fi
- **Security:** Light cannot pass through walls, providing inherent security
- **No Radio Interference:** Safe for use in sensitive environments
- **Energy Efficient:** Can use existing LED lighting infrastructure

The technology works by modulating light pulses at extremely high speeds (invisible to the human eye) to encode data, which is then decoded by light-sensitive receivers like photodiodes or LDRs.

## Circuit Diagram

### Transmitter Section

**Keypad Connection:**
- Rows: A5, A4, A3, A2
- Columns: A1, A0, 12, 11

**LED Connection:**
- LED Anode → Pin 8 (through 220Ω resistor)
- LED Cathode → GND

### Receiver Section

**LDR Connection:**
- LDR Pin 1 → 5V
- LDR Pin 2 → Pin 8 (Analog Input) and 10kΩ resistor to GND

**I2C LCD Connection:**
- SDA → A4
- SCL → A5
- VCC → 5V
- GND → GND

## Pin Configuration

### Transmitter Arduino
| Component | Arduino Pin |
|-----------|-------------|
| Keypad R1 | A5 |
| Keypad R2 | A4 |
| Keypad R3 | A3 |
| Keypad R4 | A2 |
| Keypad C1 | A1 |
| Keypad C2 | A0 |
| Keypad C3 | 12 |
| Keypad C4 | 11 |
| LED (+) | 8 |

### Receiver Arduino
| Component | Arduino Pin |
|-----------|-------------|
| LDR Signal | 8 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## Installation

### Step 1: Install Required Libraries

#### For Transmitter:
1. Open Arduino IDE
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for "Keypad" and install the Keypad library by Mark Stanley and Alexander Brevig
   - Or download from: [Arduino Keypad Library](https://playground.arduino.cc/Code/Keypad/)

#### For Receiver:
1. Install **Wire.h** (Usually pre-installed with Arduino IDE)
2. Install **LiquidCrystal_I2C.h** library:
   - Go to **Sketch → Include Library → Manage Libraries**
   - Search for "LiquidCrystal I2C" and install

### Step 2: Hardware Assembly

#### Transmitter Setup:
1. Connect the 4x4 keypad to Arduino Nano/UNO as per pin configuration
2. Connect LED to pin 8 through a 220Ω current-limiting resistor
3. Ensure proper power connections (5V and GND)

#### Receiver Setup:
1. Connect LDR in series with 10kΩ resistor (voltage divider circuit)
2. Connect the junction point to Arduino pin 8
3. Connect I2C LCD module (SDA to A4, SCL to A5)
4. Power the LCD and Arduino properly

### Step 3: Upload Code
1. Open transmitter code in Arduino IDE
2. Select correct board and COM port
3. Upload to transmitter Arduino
4. Repeat for receiver Arduino with receiver code

## Code Explanation

### Transmitter Code Logic

The transmitter code uses unique pulse durations for each key:
- Key '1': 10ms HIGH pulse
- Key '2': 20ms HIGH pulse
- Key '3': 30ms HIGH pulse
- ... and so on up to Key 'D': 160ms HIGH pulse

When a key is pressed, the Arduino sends a HIGH pulse to the LED for a specific duration, followed by LOW state.

### Receiver Code Logic

The receiver continuously monitors the LDR using the `pulseIn()` function to measure the duration of received light pulses. Based on the pulse duration, it identifies which key was pressed and displays it on the LCD.

Pulse duration ranges:
- 10,000-17,000 µs → Key '1'
- 20,000-27,000 µs → Key '2'
- And so on...

## How It Works

### Transmission Process:
1. User presses a key on the 4x4 keypad
2. Arduino reads the keypress
3. Arduino generates a unique HIGH pulse duration on pin 8
4. LED emits light pulses corresponding to the data
5. Light travels through air to the receiver

### Reception Process:
1. LDR detects the light pulses from transmitter LED
2. LDR converts light intensity changes to voltage variations
3. Arduino measures the pulse duration using `pulseIn()` function
4. Arduino decodes the pulse duration to identify the character
5. Character is displayed on the 16x2 LCD

## Usage Instructions

1. **Power On:** Connect both Arduino boards to power supply
2. **Wait for Initialization:** Receiver LCD will show "WELCOME TO CIRCUIT DIGEST"
3. **Position LEDs:** Place the transmitter LED and receiver LDR facing each other at a distance of 5-30 cm
4. **Avoid Ambient Light:** For best results, minimize ambient light interference
5. **Press Keys:** Press any key on the transmitter keypad
6. **View Output:** The corresponding character will appear on the receiver LCD as "Received: X"

### Tips for Better Performance:
- Keep the LED and LDR aligned properly
- Use in a moderately dark environment
- Maintain appropriate distance (not too close, not too far)
- Ensure stable power supply to both circuits

## Troubleshooting

### No Output on LCD
- Check I2C address (try 0x27 or 0x3F)
- Verify LCD connections (SDA, SCL, VCC, GND)
- Test LCD separately with I2C scanner sketch

### Incorrect Character Display
- Adjust pulse duration ranges in receiver code
- Check ambient light conditions
- Verify LDR and resistor values
- Use Serial Monitor to debug pulse durations

### Intermittent Communication
- Check LED brightness and LDR sensitivity
- Reduce distance between transmitter and receiver
- Shield from external light sources
- Ensure stable power supply

### No Response from Keypad
- Verify keypad connections to Arduino pins
- Test keypad separately
- Check if Keypad library is properly installed

## Future Enhancements

- **Increased Data Rate:** Implement faster modulation techniques
- **Bidirectional Communication:** Add reverse channel for acknowledgments
- **Error Detection:** Implement CRC or checksum for data integrity
- **Multiple Channels:** Use different colored LEDs for parallel communication
- **Extended Range:** Use high-power LEDs and photodiodes instead of LDR
- **Full Text Messages:** Store and transmit complete sentences
- **Audio Transmission:** Extend to voice or audio data transfer
- **Internet Integration:** Connect to IoT platforms for remote monitoring

## Project Files

### Transmitter Code
The transmitter code initialises the keypad, reads key presses, and sends unique pulse patterns through the LED.

### Receiver Code
The receiver code uses the `pulseIn()` function to measure light pulse duration and decode the transmitted data.

Both complete code files are available in the project repository.

## Credits

- **Project Source:** [Circuit Digest](https://circuitdigest.com)
- **Tutorial Link:** [Li-Fi Communication between Two Arduino](https://circuitdigest.com/microcontroller-projects/li-fi-communication-between-two-arduino)
- **Arduino**[Arduino Projects](https://circuitdigest.com/arduino-projects)

## License

This project is for educational purposes. Please refer to the original tutorial for licensing information.

## Support

For questions and discussions, visit the [Circuit Digest Forums](https://circuitdigest.com/forum)

---

**Happy Making! 🔦✨**
