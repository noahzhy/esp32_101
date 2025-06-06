# Chapter 1: LED Morse

> Short description: Convert text you sent to Morse code and blink an LED.

Compared with the old-school way of blinking an LED, this project provides a simple way to send Morse code using an LED. It is designed to be beginner-friendly and easy to use.

When you flash the code to your ESP32, it will be ready to blink the LED in Morse code. You can send messages by typing them into the serial monitor. The LED will blink the Morse code for the message you type.

## How It Works

- The code defines a `morseTable` array that stores Morse code representations for A-Z and 0-9.
- When you type a character, the `displayMorse` function looks up the Morse code and blinks the LED accordingly:
  - A dot (`.`) is a short blink (200ms).
  - A dash (`-`) is a long blink (600ms).
  - There is a 200ms pause between dots/dashes, and an 800ms pause between characters.
- The `blinkLED` function turns the LED on for the specified duration, then off.

## Try It Out

- Enter different letters and numbers to see the LED blink different Morse code patterns.
- Try entering your initials or favorite number.
