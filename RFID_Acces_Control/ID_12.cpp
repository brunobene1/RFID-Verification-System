#include "ID_12.h"

char val; // This variable is used to read the Tag ID

void MySetup()
{
  //Initializes the Serial comunication and the LED pins  
  Serial.begin(9600);      
  pinMode(LED_Green, OUTPUT); //The Green Led pin is 12
  pinMode(LED_Red, OUTPUT);   //The Green Led pin is 13
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, LOW);
}


void SerialPrintTagID(void)
{
  /*
   Show the Tag ID on the Serial Monitor
   */
  
  char id [12];
  int counter = 0;
  if(Serial.available() > 0) //checks if there's some data on the Serial
  {
    delay(200);
    while (counter < 12) //loops through each 12 digits of the Tag ID
    {
      val = Serial.read();
      if (isalnum(val)) //only counts if the digit its a number or a letter
      {
          id[counter] = val;
          counter++;
      }
    }
    Serial.print("The Tag ID is : ");
    Serial.print(id);
    Serial.println();
  }
  
}


void TagIDIndentification()
{
  /*
   Verifys if the ID is registered
   */
  //This first part get the Tag ID on a char[]
  char id [12];
  int counter = 0;
  if(Serial.available() > 0) //checks if there's some data on the Serial
  {
    while (counter < 12) //loops through each 12 digits of the Tag ID
    {
      val = Serial.read();
      if (isalnum(val)) //only counts if the digit its a number or a letter
      {
          id[counter] = val;
          counter++;
      }
    }
  }
  //-------------------------------------------------
  if(Serial.available() > 0)// //checks if there's some data on the Serial
  { 
     delay(300);
     if( (!strcmp(id, ID_1)) || (!strcmp(id, ID_2))) //Checks if the ID is on the list
     {
      Serial.print("Acces Granted!");
      Serial.println();
      //Turn on the Green LED
      digitalWrite(LED_Green, HIGH);
      delay(1500);
      digitalWrite(LED_Green, LOW);
     }
     else
     {
       Serial.print("Acces Denied!");
       Serial.println();
       //Turn on the Red LED
       digitalWrite(LED_Red, HIGH);
       delay(1500);
       digitalWrite(LED_Red, LOW);
     }
  }
}



/*
char* GetTagID(void)
{
  char id [12];
  int counter = 0;
  if(Serial.available() > 0) //checks if there's some data on the Serial
  {
    while (counter < 12)
    {
      val = Serial.read();
      if (isalnum(val))
      {
          id[counter] = val;
          //Serial.println(id[counter]);
          counter++;
      }
    }
    //Serial.print("The Tag ID is : ");
    Serial.println(id);
  }
  
  return id;
 
}
*/
