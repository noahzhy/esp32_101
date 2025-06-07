#include <WiFi.h>
#include <WiFiUdp.h> // Include WiFiUdp library for UDP functionality

// Use your custom LOW and HIGH definitions
#define LOW 1
#define HIGH 0

// morse code for A-Z and 0-9
const char* morseTable[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", // A-J
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",  // K-T
    "..-", "...-", ".--", "-..-", "-.--", "--..",                        // U-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

// --- Wi-Fi Configuration ---
const char* ssid = "esp32";       // Replace with your Wi-Fi network name
const char* password = "esp32_101"; // Replace with your Wi-Fi password

// --- UDP Configuration ---
// IMPORTANT: Replace with the IP address and port of the receiving device
IPAddress recipientIP(192, 168, 0, 140);
const int udpPort = 3600;
WiFiUDP udp;
char udpBuffer[64]; // buffer for incoming UDP packets

// Function to blink the LED for a specified duration
void blinkLED(int duration) {
    digitalWrite(LED_BUILTIN, HIGH); // Use your defined HIGH
    delay(duration);
    digitalWrite(LED_BUILTIN, LOW);  // Use your defined LOW
}

void setup() {
    // Set the LED pin as an output
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW); // Ensure LED is off initially

    // Initialize Serial communication
    Serial.begin(115200);
    Serial.println();
    Serial.println("Morse Code Blinker");

    // Connect to Wi-Fi
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("");
        Serial.println("WiFi connection failed!");
        // Optionally, blink LED rapidly to indicate failure
        while(true) {
            digitalWrite(LED_BUILTIN, HIGH); // Use your defined HIGH
            delay(100);
            digitalWrite(LED_BUILTIN, LOW);  // Use your defined LOW
            delay(100);
        }
    }

    // 启动UDP监听
    udp.begin(udpPort);
    Serial.print("UDP listening on port ");
    Serial.println(udpPort);
}

void displayMorse(char c) {
    c = toupper(c); // convert to uppercase
    int index = -1;

    if (c >= 'A' && c <= 'Z') {
        index = c - 'A';
    } else if (c >= '0' && c <= '9') {
        index = c - '0' + 26;
    }

    if (index != -1) {
        const char* morseCode = morseTable[index];
        for (int i = 0; morseCode[i] != '\0'; i++) {
            if (morseCode[i] == '.') {
                blinkLED(200); // short blink
            } else if (morseCode[i] == '-') {
                blinkLED(600); // long blink
            }
            delay(200); // dot or dash interval
        }
        delay(800); // character interval
    }
}

void loop() {
    // handle serial input
    if (Serial.available() > 0) {
        char input = Serial.read();
        displayMorse(input);
    }

    // handle UDP input
    int packetSize = udp.parsePacket();
    if (packetSize > 0) {
        int len = udp.read(udpBuffer, sizeof(udpBuffer) - 1);
        if (len > 0) {
            udpBuffer[len] = '\0'; // ensure null-termination
            for (int i = 0; i < len; ++i) {
                displayMorse(udpBuffer[i]);
            }
        }
    }
    // Ensure the LED is off after processing a character or if no character was available
    digitalWrite(LED_BUILTIN, LOW); // Use your defined LOW
}