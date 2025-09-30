# ESP32 101
A beginner-friendly library that makes learning ESP32 fun and easy.

This library helps beginners learn about the ESP32 microcontroller and its capabilities. It includes simple projects that demonstrate how to use the ESP32 for various tasks, such as blinking an LED, reading sensors, and connecting to Wi-Fi.

There are four parts in this library:

1. **Introduction**: Explains why to choose the ESP32 for learning, and how to set up the development environment and tools.
2. **Getting Started**: Provides simple projects to help you get familiar with the ESP32, such as blinking an LED, connecting to Wi-Fi, reading sensor data, controlling motors, and using sensors.
3. **Advanced Projects**: Allows you to explore more advanced projects such as TinyML applications, or chatting with GPT or Google Gemini.
4. **Optional Projects**: Once you know the basics, you can explore more advanced projects that involve connecting to the internet, using cloud services, and building IoT applications via MQTT and HTTP, or using cloud services like Blynk, Adafruit IO, and ThingSpeak.

## Getting Started

### Prerequisites
- ESP32 development board (ESP32-WROOM-32, ESP32-S3, or similar)
- Arduino IDE or Platform IO
- USB cable for programming
- Basic understanding of C/C++ programming (helpful but not required)

### Quick Start
1. Clone this repository: `git clone https://github.com/noahzhy/esp32_101.git`
2. Set up your ESP32 development environment following [Chapter 1: Introduction](docs/C1_Introduction/)
3. Start with [Chapter 2: Getting Started](docs/C2_Getting_Started/) projects
4. Upload the code to your ESP32 and have fun learning!

## Contents
| Chapter                       | Section                   | Description                                                   |
|-------------------------------|---------------------------|---------------------------------------------------------------|
| Chapter 1: Introduction       | Section 1: [Why ESP32?](docs/C1_Introduction/S1_Why_Esp32.md)     | Overview of why the ESP32 is a great choice for learning.     |
|                               | Section 2: Setting Up     | Guide to setting up the ESP32 development environment.        |
|                               | Section 3: Basic Structure| Introduction to code structure and basic concepts.            |
| Chapter 2: Getting Started    | Section 1: [LED Morse](docs/C2_Getting_Started/S1_LED_Morse.md)      | Learn how to use the ESP32 to blink an LED in Morse code.     |
|                               | Section 2: [WiFi LED Morse](docs/C2_Getting_Started/S2_Wifi_LED_Morse.md) | Integrate Wi-Fi functionality to control the LED via UDP.     |
|                               | Section 3: [WiFi Thermal](code/c2s3/wifi_thermal)   | Build a thermal imaging camera using WiFi and MLX90640 sensor.|

> **Note**: Chapters 3 and 4 (Advanced Projects and Optional Projects) are planned for future releases.

## Q & A
<details>
<summary>What's the 101 in ESP32 101?
</summary>

The number "101" is often used to indicate a basic or foundational level of understanding, similar to how college courses are numbered (e.g., "Introduction to Psychology 101"). This library aims to provide a simple and accessible way for newcomers to learn about the ESP32 and its capabilities.

</details>

<details>
<summary>What's different from other ESP32 libraries?</summary>

Well, there are many ESP32 libraries out there, but they often get started with an unappealing IDE, boring examples, and uncreative projects. Many don't even teach you why you need to learn through engaging examples. This library is designed to be beginner-friendly, with a focus on fun and engaging projects that help you learn the basics of the ESP32 in a simple way. It also provides clear explanations and step-by-step instructions to make learning easy and enjoyable.
</details>

<details>
<summary>How can I contribute to this library?</summary>
You can contribute by creating new projects, improving existing ones, or providing feedback on the library. If you have a fun and creative project idea that uses the ESP32, feel free to share it! You can also help by reporting issues or suggesting improvements to the documentation.
</details>

<details>
<summary>How can I get help if I have questions or issues?</summary>
You can ask questions or report issues on the library's GitHub repository. The community is always ready to help, and you can also find answers to common questions in the documentation.
</details>

## Contributing

We welcome contributions! Here are ways you can help:
- **Add new projects**: Share your creative ESP32 projects
- **Improve documentation**: Fix typos, add explanations, or create tutorials
- **Report issues**: Found a bug or have a suggestion? Let us know!
- **Share feedback**: Help us make this library better for beginners

Please feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.