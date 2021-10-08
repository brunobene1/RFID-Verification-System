#ifndef ID_12_h
#define ID_12_h

// Register you Tag ID manually
#define ID_1   "4F0088EFD8F0"
#define ID_2   "3B008EBC5C55"
#define ID_3   "4F0088D84956"
//--------------------------------------------

#include <Arduino.h>
#include <string.h>

#define LED_Green 12
#define LED_Red 13

void MySetup();
void SerialPrintTagID();
void TagIDIndentification();

#endif 
