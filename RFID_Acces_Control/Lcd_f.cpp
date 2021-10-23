#include "Lcd_f.h"
#include "ID_12.h"

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7); //Initialies the lcd object

void lcd_f_setup()
{
 lcd.begin(16, 2); //Initiales a 16x2 matrix
 pinMode(LCD_V0,OUTPUT); 
 analogWrite(LCD_V0,50); //Adjust the lcd contrast
}

void lcd_f_welcome() 
{
 lcd.setCursor(0,0);  
 lcd.print("Seja bem vindo!"); 
 lcd.setCursor(0,1); 
 lcd.print("Esperando..."); 
}

void lcd_f_clear()
{
  lcd.clear();
}

void lcd_f_accesgranted()
{
  lcd.setCursor(0,0);  
  lcd.print("Acesso liberado!"); 
}

void lcd_f_accesdenied()
{
  lcd.setCursor(0,0);  
  lcd.print("Acesso negado!"); 
}

void lcd_f_waiting_door()
{
  lcd.setCursor(0,0);  
  lcd.print("Passe a tag no"); 
  lcd.setCursor(0,1); 
  lcd.print("leitor...");
}

void lcd_f_waiting_add_tag()
{
  lcd.setCursor(0,0);  
  lcd.print("Para registrar,"); 
  lcd.setCursor(0,1); 
  lcd.print("passe a tag...");
}

void lcd_f_registering_msg(int is_id_registered)
{
  if(number_of_registered_ids < max_num_ids)
  {
    if(is_id_registered ==0)
    {
      lcd.setCursor(0,0);  
      lcd.print("Id registrado"); 
      lcd.setCursor(0,1); 
      lcd.print("com sucesso!");
    }
    else
    {
      lcd.setCursor(0,0);  
      lcd.print("Este id ja foi"); 
      lcd.setCursor(0,1); 
      lcd.print("registrado!");
    }
  }
  else
  {
    lcd.setCursor(0,0);  
    lcd.print("Num max de"); 
    lcd.setCursor(0,1); 
    lcd.print("ids atingido!");
  }
}

void lcd_f_del_tag_msg()
{
  lcd.setCursor(0,0);  
  lcd.print("Ultimo id da"); 
  lcd.setCursor(0,1); 
  lcd.print("lista deletado.");
}

//-------------------------------------------------------------------------------------
