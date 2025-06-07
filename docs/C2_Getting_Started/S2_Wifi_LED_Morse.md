# WiFi LED Morse Code Tutorial

In this section, we’ll build on the previous chapter where we learned about LED Morse code. Now, we’ll take it a step further by integrating WiFi functionality into the ESP32.

You’ll learn how to connect the ESP32 to a WiFi network, send data through a browser, and watch the LED on the ESP32 flash Morse code messages while connected to the same network. This tutorial will guide you through the process step by step, helping you seamlessly combine LED control and WiFi for an exciting project!

## How It Works

- The ESP32 connects to your WiFi network and listens for UDP messages on a specific port.
- To send a message, you need to use the provided Python script (`send_message.py`) on your computer.
- The Python script starts a simple web server on your computer. You can open the web page in your browser, enter a message, and submit it.
- When you submit a message, the script sends it to the ESP32 via UDP.
- The ESP32 receives the message, converts it to Morse code, and blinks the LED.
- All communication between your computer and the ESP32 happens over your local WiFi network using UDP.

## Try It Out

- Modify the `ssid` and `password` variables in the code then flash the code to your ESP32. It will connect to your WiFi network, the connection status will be printed to the serial monitor, and the ESP32 will start listening for UDP messages.
- Open the serial monitor to find out the ESP32’s IP address and UDP port.
- On your computer (connected to the same WiFi), run the provided `send_message.py` script or use any UDP client to send messages.
- Open your browser and go to `http://localhost:8000` to access the web page if you are using the Python script.
- Enter a message and click send. The script will send your message to the ESP32 via UDP.
- Watch the LED on the ESP32 blink your message in Morse code.
