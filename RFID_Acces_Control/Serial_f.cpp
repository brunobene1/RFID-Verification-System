#include "Serial_f.H"
#include "ID_12.h"

void serialf_setup()
{
  Serial.begin(9600);   
}

void serialf_print_tagid(char* id)
{
  Serial.print("The Tag ID is : ");
  Serial.println(id);
}

void serialf_wait_for_serial ()
{
  while(Serial.available() ==0){} //waits until the serial has something
}

void serialf_print_accesgranted()
{
  Serial.print("Acces Granted!");
  Serial.println();
}

void serial_print_accesdenied()
{
  Serial.print("Acces Denied!");
  Serial.println();
}

void serialf_print_waiting_msg()
{
    Serial.println("-----------------------------");
    Serial.println("Selec what you want to do.");
    Serial.println("Waiting...");
    Serial.println();
}

void serialf_print_waiting_door1()
{
  Serial.println("To open door 1 pass the id on the reader.");
  Serial.println("Waiting...");
  Serial.println();
}

void serialf_print_waiting_door2()
{
  Serial.println("To open door 2 pass the id on the reader.");
  Serial.println("Waiting...");
  Serial.println();
}

void serialf_print_waiting_add_tag()
{
  Serial.println("To register a new id, pass the id on the reader.");
  Serial.println("Waiting...");
  Serial.println();
}

void serialf_print_registering_msg(int is_id_registerd)
{
  if(number_of_registered_ids < max_num_ids)
  {
    if(is_id_registerd ==0)
    {
      Serial.print("New id registered!");
      Serial.println();
    }
    else
    {
      Serial.print("The id is already registered!");
      Serial.println();
    }
  }
  else
  {
    Serial.print("Max number of ids registered!");
    Serial.println();
  }
}

void serialf_print_del_tag_msg()
{
  Serial.println("The last tag registered was removed.");
  Serial.println();
}

void serialf_print_indoor_button()
{
  Serial.println("Someone is trying to get out of the room.");
  Serial.println("Unlocking the door.");
  Serial.println();
}

void serialf_print_timeout()
{
  Serial.println("Timeout");
  Serial.println();
}
