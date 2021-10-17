#include "ID_12.h"

char id_list [5][13]; //declaring an char array with 5 elements that are 12 bytes longs each
int number_of_registered_ids; //number of registered ids
int id_is_on_the_list; //boolean like variable to check when to stop looping through the array

void id12_setup()
{
  strcpy(id_list[0], ID_1); //Starts the program with ID_1 registered
  strcpy(id_list[1], ID_2); //Starts the program with ID_2 registered
  number_of_registered_ids = 2;
}

void id12_read_id(char* id)
{
  char val; // This variable is used to read the Tag ID
  int counter = 0; //This variable is used in the while loop
  
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
}

void id12_check_id(char* id, int* id_is_on_the_list)
{
  *id_is_on_the_list = 0; //boolean like variable to check when to stop looping through the array
  
  for(int i =0; i < (number_of_registered_ids); i++) 
  {
    if(!strcmp(id, id_list[i])) //checks if theres an id that matches the one that is trying to get acces
    {
      *id_is_on_the_list = 1;
      break;
    }
  }
}

void id12_add_id(char* id, int id_is_on_the_list)
{
  if (id_is_on_the_list == 0)
  {
    strcpy(id_list[number_of_registered_ids], id);
    number_of_registered_ids++;
  }
}

void id12_del_id()
{
  number_of_registered_ids--;
}
