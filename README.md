# RFID-Verification-System
This project uses the Arduino and the ID-12 RFID reader for RFID Verification.  
You can Read the Tag ID on the Serial Monitor via function and then hard-code it to register the tag on another function.
# ID-12 pin-out
We are going to use the pins :  
**1** - GND   
**2** - RST  
**7** - Format Selector   
**9** - D0 (Data pin 0)  
**11** - +5V  
# Wiring Diagram
Here's the circuit diagram.  
Pins 2 and 11 connected to the +5V of the Arduino.  
Pins 1 and 7 to the Arduino GND.  
Pin 9 (data) conected on the RX for Serial data.  
The two LEDs output can be changed on the code.  
