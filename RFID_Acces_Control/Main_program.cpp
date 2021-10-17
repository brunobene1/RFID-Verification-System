#include "Main_program.h"

char tag_id[13]; //saves the id read by the serial
int id_on_the_list ; //boolean like variable to check if the id is registered
int user_input; //saves the user input
int door_number; //what door the user is trying to open

void main_program_setup()
{
  button_manager_setup();
  serialf_setup(); //Initializes the Serial comunication 
  id12_setup();
  doors_setup();
  user_input =0;
}

void main_program_loop()
{
  delay(100);
  serialf_print_waiting_msg();
  button_manager_get_user_input(&user_input);
  switch(user_input)
  {
    //------------------------------------------------------------
    case 1: // Trying to acces door 1
    
    door_number = 1;
    serialf_print_waiting_door1();
    serialf_wait_for_serial ();
    id12_read_id(tag_id);
    id12_check_id(tag_id, &id_on_the_list);
    if (id_on_the_list)
    {
      serialf_print_accesgranted();
    }
    else
    {
      serial_print_accesdenied();
    }
    doors_open(door_number ,&id_on_the_list);
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    case 2: // Trying to acces door 2
    
    door_number = 2;
    serialf_print_waiting_door2();
    serialf_wait_for_serial ();
    id12_read_id(tag_id);
    id12_check_id(tag_id, &id_on_the_list);
    if (id_on_the_list)
    {
      serialf_print_accesgranted();
    }
    else
    {
      serial_print_accesdenied();
    }
    doors_open(door_number ,&id_on_the_list);
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    case 3: // Registering a new id on the list

    serialf_print_waiting_add_tag();
    serialf_wait_for_serial ();
    id12_read_id(tag_id);
    id12_check_id(tag_id, &id_on_the_list);
    id12_add_id(tag_id, id_on_the_list);
    serialf_print_registering_msg(id_on_the_list);
    delay(2000);
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    case 4: // Deleting the last id on the list (highest index)

    serialf_print_del_tag_msg();
    id12_del_id();
    delay(2000);
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    default:
    break;
  }
  
}
