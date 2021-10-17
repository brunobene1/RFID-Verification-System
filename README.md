# RFID-Verification-System
This project uses the Arduino and the ID-12 RFID reader for RFID Verification.  
You can Read the Tag ID on the Serial Monitor via function and then hard-code it to register the tag on another function.
![ImagemLendo](https://user-images.githubusercontent.com/85142097/136483616-a216d69f-0ec5-42de-8935-02fb87507300.jpg)
# ID-12 pin-out
![ID-12 Pinagem](https://user-images.githubusercontent.com/85142097/136481995-7a224311-261f-4f90-9b78-6ac30aea9cd1.png)
We are going to use the pins :  
**1** - GND   
**2** - RST  
**7** - Format Selector   
**9** - D0 (Data pin 0)  
**11** - +5V  
# Wiring Diagram
![WiringDiagram](https://user-images.githubusercontent.com/85142097/136482023-c1fb5bb3-6602-4dd6-8cec-a6af763b4847.png)
Here's the circuit diagram.  
Pins 2 and 11 connected to the +5V of the Arduino.  
Pins 1 and 7 to the Arduino GND.  
Pin 9 (data) conected on the RX for Serial data.  
The two LEDs output can be changed on the code.  
