# RFID-Verification-System
This project uses the Arduino and the ID-12 RFID reader for RFID Verification.  
You can add/remove a new tag id at real time execution on the volatile memory, there are two green LEDs that simulate the door's eletronic locks and a red LED that indicates if your access was denied.  
There is a button that simulates a button that would be inside of the access area, so you would not need to pass the tag on the reader, since you can´t fisically reach it, to unlock the door.  
The project has a limit of 5 tags to be registered (it can be changed on the code) and a timeout system for more software reliability/security.  
The project was made for learning purposes, but it was designed to work on a real RFID verification system.  
![CaixaPronta](https://user-images.githubusercontent.com/85142097/148553242-84ea566a-6f86-47dc-b9c9-b46d38019f8d.jpg)   
# Youtube video  
https://youtu.be/VXtu8wE-xIc 
# Wiring Diagram
![FullWiringDiagram](https://user-images.githubusercontent.com/85142097/148553423-296a7e76-3fd7-4fde-910e-cfb8c00e3da8.png)  
# ID-12 pin-out
![ID-12 Pinagem](https://user-images.githubusercontent.com/85142097/136481995-7a224311-261f-4f90-9b78-6ac30aea9cd1.png)
We are going to use the pins :  
**1** - GND   
**2** - RST  
**7** - Format Selector   
**9** - D0 (Data pin 0)  
**11** - +5V  
