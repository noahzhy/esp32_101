// Xiao esp32s3 has a built-in LED but with LOW = ON and HIGH = OFF
#define LOW 1
#define HIGH 0

// morse code for A-Z and 0-9
const char* morseTable[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", // A-J
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",  // K-T
    "..-", "...-", ".--", "-..-", "-.--", "--..",                        // U-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        char input = Serial.read();
        if (isAlphaNumeric(input)) {
            displayMorse(input);
        }
    }
    digitalWrite(LED_BUILTIN, LOW);
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

void blinkLED(int duration) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(duration);
    digitalWrite(LED_BUILTIN, LOW);
}