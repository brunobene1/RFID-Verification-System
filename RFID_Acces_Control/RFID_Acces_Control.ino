/*
 RFID_Acces_Control
 Author : Bruno Benedetti
 Date : 06/10/2021
 */


#include "ID_12.h"



void setup()
{
  MySetup(); ////Initializes the Serial comunication and the LED pins
}



void loop () 
{  
//SerialPrintTagID();       // Show the Tag ID on the Serial Monitor
TagIDIndentification();     //Verifys if the ID is registered
}
