# Smart-home-by-Bluetooth
Arduino project Smart Home Control via Bluetooth . This innovative system utilizes a Bluetooth connection for wireless control of home lighting and fans. Designed for easy interaction, it supports both direct command inputs and voice commands for a hands-free experience. video link⬇️
https://fb.watch/rdOdpgcTuE/?mibextid=Nif5oz


This Arduino sketch provides a way to control lights and a fan using both Bluetooth and serial voice commands. The code sets up a simple home automation system where devices (a light and a fan) can be turned on or off based on commands received over Bluetooth or through voice input via a serial connection. Here's a breakdown of how it works:

- **Setup:** The `setup()` function initializes serial communication at 9600 bps for both the USB and the Bluetooth connections. It also configures the relay control pins for the light and fan as outputs and initially sets them to HIGH (typically off for a relay).

- **Bluetooth Command Processing:** The `loop()` function checks for data availability on the Bluetooth serial port. If a command is available, it reads a single character and matches it to predefined commands ('1' for light on, '2' for light off, etc.). Based on the command, it controls the relays connected to the light and the fan and sends a confirmation message back over Bluetooth.

- **Voice Command Processing:** Additionally, the loop function collects characters from the USB serial port into a string until it encounters a '#' character, marking the end of a voice command. It then compares the accumulated string to predefined voice commands (like "*turn on light"). If a match is found, it performs the corresponding action and sends a confirmation message over Bluetooth.

- **Action Commands:** The actions include turning the light or fan on or off individually, or controlling both together. This is done by writing LOW (on) or HIGH (off) to the respective relay control pins.

This code effectively demonstrates how to use both Bluetooth and serial inputs to control physical devices, making it a good starting point for various home automation projects. If you're looking to extend this project, consider adding more devices or implementing a more sophisticated command parser for additional functionalities.
