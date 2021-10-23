#include "Buttons_manager.h"

void button_manager_setup()
{
  pinMode(DOOR1_BUTTON, INPUT_PULLUP);
  pinMode(DOOR2_BUTTON, INPUT_PULLUP);
  pinMode(ADD_TAG_BUTTON, INPUT_PULLUP);
  pinMode(DEL_TAG_BUTTON, INPUT_PULLUP);
  pinMode(INDOOR_BUTTON, INPUT_PULLUP);
}

void button_manager_get_user_input(int* button_pressed)
{
  /* MODES :
   *  1 = Trying to open the door 1
   *  2 = Trying to open the door 2
   *  3 = Registering a new tag
   *  4 = Deleting the last tag registered on the list
   *  5 = When someone is already inside and is trying to get out of the room
   */
   *button_pressed = 0;
   
   while(*button_pressed == 0)
   {
     if(digitalRead(DOOR1_BUTTON) == 0) //checks if the button has been pressed
     {
       *button_pressed = 1;
     }
     if(digitalRead(DOOR2_BUTTON) == 0) //checks if the button has been pressed
     {
       *button_pressed = 2;
     }
     if(digitalRead(ADD_TAG_BUTTON) == 0) //checks if the button has been pressed
     {
       *button_pressed = 3;
     }
     if(digitalRead(DEL_TAG_BUTTON) == 0) //checks if the button has been pressed
     {
       *button_pressed = 4;
     }
     if(digitalRead(INDOOR_BUTTON) == 0) //checks if the button has been pressed
     {
       *button_pressed = 5;
     }
   }
}
