#include "Doors.h"

void doors_setup()
{
  pinMode(DOOR1, OUTPUT); 
  pinMode(DOOR2, OUTPUT);
  pinMode(LED_DENIED, OUTPUT); 
  digitalWrite(DOOR1, LOW);
  digitalWrite(DOOR2, LOW);
  digitalWrite(LED_DENIED, LOW);
}

void doors_open(int door_num, int* acces)
{
  if(*acces == 1) //Verifys if the acces is granted for that ID
  {
    switch(door_num)
    {
      case 1: // Door1
      //Turn on the Green LED
      digitalWrite(DOOR1, HIGH);
      delay(2500);
      digitalWrite(DOOR1, LOW);
      *acces = 0;
      break;

      case 2: // Door2
      //Turn on the Green LED
      digitalWrite(DOOR2, HIGH);
      delay(2500);
      digitalWrite(DOOR2, LOW);
      *acces = 0;
      break;
    }
  }
  else //If not, than it won't open the door
  {
    //Turn on the Red LED
    digitalWrite(LED_DENIED, HIGH);
    delay(2500);
    digitalWrite(LED_DENIED, LOW);
  }
}

void doors_indoor_button()
{
  digitalWrite(DOOR1, HIGH);
  digitalWrite(DOOR2, HIGH);
  delay(2500);
  digitalWrite(DOOR1, LOW);
  digitalWrite(DOOR2, LOW);
}
