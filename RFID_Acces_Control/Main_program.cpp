#include "Main_program.h"

char tag_id[13]; //saves the id read by the serial
int id_on_the_list ; //boolean like variable to check if the id is registered
int user_input; //saves the user input
int door_number; //what door the user is trying to open
int is_serial_working;
// Timeout system variables ---------------------------------
unsigned long currentMillis;
unsigned long previousMillis;
unsigned long interval;
// ----------------------------------------------------------

void main_program_setup()
{
  button_manager_setup();
  serialf_setup(); //Initializes the Serial comunication 
  id12_setup();
  doors_setup();
  user_input =0;
  lcd_f_setup();
  Wire.setClock(20000);
  previousMillis=0;
  interval=10000; // 10 seconds is the timeout time
  is_serial_working =0;
}

void main_program_loop()
{
  if(Serial.available() != 0)
      {
        Serial.println("Ola 1");
      }
  is_serial_working =0;
  currentMillis = millis();
  lcd_f_clear();
  delay(100);
  lcd_f_welcome();
  serialf_print_waiting_msg();
  button_manager_get_user_input(&user_input);
  switch(user_input)
  {
    //------------------------------------------------------------
    case 1: // Trying to acces door 1

    if(Serial.available() != 0)
      {
        Serial.println("Ola 2");
      }
    lcd_f_clear();
    door_number = 1;
    lcd_f_waiting_door();
    serialf_print_waiting_door1();
    currentMillis = millis();
    previousMillis = currentMillis;
    //Serial.println("serial");
    //Serial.println(is_serial_working);
    if(Serial.available() != 0)
      {
        Serial.println("Ola 3");
      }
    while(((unsigned long)(currentMillis - previousMillis) <= interval) && is_serial_working == 0) //timeout system, if the user takes more than 10 seconds to pass the id, the program restarts
    {
      currentMillis = millis();
      //Serial.println("atual :");
     // Serial.println(currentMillis);
      //Serial.println("Previo");
      //Serial.println(previousMillis);
      //Serial.println("serial");
      //Serial.println(is_serial_working);
      if(isalnum(Serial.read()))
      {
        is_serial_working = 1;
      }
      //Serial.println("serial");
      //Serial.println(is_serial_working);
    }
    if((unsigned long)(currentMillis - previousMillis) >= interval)
    {
      serialf_print_timeout();
      delay(1000);
      break;
    }
    
    Serial.println("aq em cima ainda");
    id12_read_id(tag_id);
    Serial.println("passei");
    id12_check_id(tag_id, &id_on_the_list);
    lcd_f_clear();
    if (id_on_the_list)
    {
      serialf_print_accesgranted();
      lcd_f_accesgranted();
    }
    else
    {
      serial_print_accesdenied();
      lcd_f_accesdenied();
    }
    doors_open(door_number ,&id_on_the_list);
    if(Serial.available() != 0)
      {
        Serial.println("Ola 4");
      }
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    case 2: // Trying to acces door 2

    if(Serial.available() != 0)
      {
        Serial.println("Ola 2");
      }
    lcd_f_clear();
    door_number = 2;
    lcd_f_waiting_door();
    serialf_print_waiting_door2();
    serialf_wait_for_serial ();
    if(Serial.available() != 0)
      {
        Serial.println("Ola 3");
      }
    id12_read_id(tag_id);
    id12_check_id(tag_id, &id_on_the_list);
    lcd_f_clear();
    if (id_on_the_list)
    {
      serialf_print_accesgranted();
      lcd_f_accesgranted();
    }
    else
    {
      serial_print_accesdenied();
      lcd_f_accesdenied();
    }
    doors_open(door_number ,&id_on_the_list);
    if(Serial.available() != 0)
      {
        Serial.println("Ola 4");
      }
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    case 3: // Registering a new id on the list

    lcd_f_clear();
    lcd_f_waiting_add_tag();
    serialf_print_waiting_add_tag();
    serialf_wait_for_serial ();
    id12_read_id(tag_id);
    id12_check_id(tag_id, &id_on_the_list);
    serialf_print_registering_msg(id_on_the_list);
    lcd_f_clear();
    lcd_f_registering_msg(id_on_the_list);
    id12_add_id(tag_id, id_on_the_list);
    delay(2000);
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    case 4: // Deleting the last id on the list (highest index)

    lcd_f_clear();
    lcd_f_del_tag_msg();
    serialf_print_del_tag_msg();
    id12_del_id();
    delay(2000);
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    case 5: // When someone is already inside and is trying to get out of the room

    lcd_f_clear();
    lcd_f_accesgranted();
    serialf_print_indoor_button();
    doors_indoor_button();
    break;
    //------------------------------------------------------------
    //------------------------------------------------------------
    default:
    break;
  }
  
}

void main_program_timeout_waiting_for_serial()
{
  
}
