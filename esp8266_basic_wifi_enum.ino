#include <ESP8266WiFi.h>

#define ENCRYPTION_THRESHOLD_WEP -50
#define ENCRYPTION_THRESHOLD_WPA2 -60

void startScan() {
    int numNetworks = WiFi.scanNetworks();
    Serial.println("Scan complete. Networks found: " + String(numNetworks));

    for (int i = 0; i < numNetworks; i++) {
        String encryptionInfo = getEncryptionInfo(WiFi.encryptionType(i));
        String ssid = WiFi.SSID(i);
        String bssid = WiFi.BSSIDstr(i);
        int rssi = WiFi.RSSI(i);
        int channel = WiFi.channel(i);

        Serial.println("-----------------------------------------------");
        Serial.print("SSID: ");
        Serial.println(ssid);
        Serial.print("BSSID (MAC): ");
        Serial.println(bssid);
        Serial.print("RSSI: ");
        Serial.println(rssi);
        Serial.print("Channel: ");
        Serial.println(channel);
        Serial.print("Encryption: ");
        Serial.println(encryptionInfo);
        Serial.println("-----------------------------------------------");
    }
}

String getEncryptionInfo(int encryptionType) {
    String encryptionTypeStr;
    String encryptionStrength;

    switch (encryptionType) {
        case 0:  // Open
            encryptionTypeStr = "Open";
            encryptionStrength = "Weak";
            break;
        case 1:  // WEP
            encryptionTypeStr = "WEP";
            encryptionStrength = "Weak";
            break;
        case 2:  // WPA
            encryptionTypeStr = "WPA";
            encryptionStrength = "Moderate";
            break;
        case 3:  // WPA2
            encryptionTypeStr = "WPA2";
            encryptionStrength = "Strong";
            break;
        case 4:  // WPA/WPA2
            encryptionTypeStr = "WPA/WPA2";
            encryptionStrength = "Strong";
            break;
        default:
            encryptionTypeStr = "Unknown";
            encryptionStrength = "Unknown";
            break;
    }

    return encryptionTypeStr + " (" + encryptionStrength + ")";
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(2000);

    Serial.println("===============================================");
    Serial.println("              ,---------------------------,");
    Serial.println("              |  /---------------------\\  |");
    Serial.println("              | |                       | |");
    Serial.println("              | |     Basic             | |");
    Serial.println("              | |          WiFi         | |");
    Serial.println("              | |             Enum      | |");
    Serial.println("              | |                       | |");
    Serial.println("              |  \\_____________________/  |");
    Serial.println("              |___________________________|");
    Serial.println("            ,---\\_____     []     _______/------,");
    Serial.println("          /         /______________\\           /|");
    Serial.println("        /___________________________________ /  | ___");
    Serial.println("        |                                   |   |    )");
    Serial.println("        |  _ _ _                 [-------]  |   |   (");
    Serial.println("        |  o o o                 [-------]  |  /    _) _");
    Serial.println("        |__________________________________ |/     /  /");
    Serial.println("    /-------------------------------------/|      ( )/");
    Serial.println("  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /");
    Serial.println(" /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /");
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    Serial.println("      Developed by Shreyas-Malhotra      ");
    Serial.println("===============================================");
    Serial.println("      Press 's' to start the scan...      ");
    Serial.println("===============================================");
}

void loop() {
    if (Serial.available()) {
        char command = Serial.read();
        if (command == 's') {
            startScan();
        }
    }
}
