#ifndef BUTTONS_MANAGER_H
#define BUTTONS_MANAGER_H

#include <Arduino.h>

#define DOOR1_BUTTON 9
#define DOOR2_BUTTON 10
#define ADD_TAG_BUTTON 13
#define DEL_TAG_BUTTON A0

/**
 * \brief Setup the Button pins with a pull-up resistor.
 */
void button_manager_setup();

/**
 * \brief Get the user input
 *
 * \param[in] button_pressed Saves the user input
 *
 */
void button_manager_get_user_input(int* button_pressed);

#endif /* BUTTONS_MANAGER_H */
