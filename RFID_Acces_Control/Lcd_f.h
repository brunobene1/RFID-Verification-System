#ifndef LCD_F_H
#define LCD_F_H

#include <Arduino.h>
#include <LiquidCrystal.h>

//defining the lcd pins
#define LCD_RS 12
#define LCD_E 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2
#define LCD_V0 6

/**
 * \brief Setup the lcd
 */
void lcd_f_setup();

/**
 * \brief Welcome mensage
 */
void lcd_f_welcome(); 

/**
 * \brief Clear lcd
 */
void lcd_f_clear();

/**
 * \brief Acces granted mensage
 */
void lcd_f_accesgranted();

/**
 * \brief Acces denied mensage
 */
void lcd_f_accesdenied();

/**
 * \brief Waiting for tag mensage
 */
void lcd_f_waiting_door();

/**
 * \brief Waiting to add tag mensage
 */
void lcd_f_waiting_add_tag();

/**
 * \brief Registering response mesage
 * 
 * \param[in] is_id_registered Boolean like variable to check if the id is already registered
 */
void lcd_f_registering_msg(int is_id_registered);

/**
 * \brief Delete tag mensage
 */
void lcd_f_del_tag_msg();

/**
 * \brief Timeout mensage
 */
void lcd_f_timeout_msg();

#endif /* LCD_F_H */
