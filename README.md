# Basic WiFi Enum

**Basic WiFi Enum** is a lightweight tool for scanning and enumerating nearby WiFi networks using an ESP8266/ESP32 module. It provides detailed information about each detected network. The results are displayed on the serial monitor.

## Features

- Scans for visible WiFi networks.
- Displays detailed network information: 
  - **SSID**
  - **BSSID**
  - **RSSI** (signal strength)
  - **Channel**
  - **Encryption Type**
- Uses an ESP8266 module for lightweight operation.
- Output is displayed on the serial monitor for easy review.

## Requirements

- An **ESP8266** module.
- **Arduino IDE** (with ESP8266 board package installed).
- A USB cable to connect the module to the PC.

## Usage

1. **Set up the tool**:
   - Install the necessary libraries and board package for your ESP8266 in the Arduino IDE.
   - Open the provided `.ino` file in the Arduino IDE.
   - Select the correct board type (generally NodeMCU 1.0).
   - Upload the code to your ESP module.

2. **Using the tool**:
   - Open the **Serial Monitor** in the Arduino IDE (set to 115200 baud rate).
   - After the module starts, press the `s` key to start the WiFi scan.
   - The serial monitor will display a list of detected networks with the following details:
     - SSID
     - BSSID (MAC address)
     - RSSI (signal strength)
     - Channel
     - Encryption type (WEP, WPA, WPA2, etc.)

3. **Interpreting the results**:
   - The tool will show information for all visible networks.
   - Hidden networks are **not detected** as of now.

## Example Output

```plaintext
===============================================
              ,---------------------------,
              |  /---------------------\  |
              | |                       | |
              | |     Simple            | |
              | |          WiFi         | |
              | |             Enum      | |
              | |                       | |
              |  \_____________________/  |
              |___________________________|
            ,---\_____     []     _______/------,
          /         /______________\           /|
        /___________________________________ /  | ___
        |                                   |   |    )
        |  _ _ _                 [-------]  |   |   (
        |  o o o                 [-------]  |  /    _)_
        |__________________________________ |/     /  /
    /-------------------------------------/|      ( )/
  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /
/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      Developed by Shreyas-Malhotra      
===============================================
      Press 's' to start the scan...      
===============================================
Scan complete. Networks found: 3
-----------------------------------------------
SSID: Network_1
BSSID (MAC): 00:14:22:01:23:45
RSSI: -40
Channel: 6
Encryption: WPA2 (Strong)
-----------------------------------------------
SSID: Network_2
BSSID (MAC): 00:14:22:67:89:01
RSSI: -60
Channel: 11
Encryption: WPA2 (Strong)
-----------------------------------------------
SSID: Network_3
BSSID (MAC): 00:14:22:98:76:54
RSSI: -75
Channel: 1
Encryption: WEP (Weak)
-----------------------------------------------
