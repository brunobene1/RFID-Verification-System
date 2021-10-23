#ifndef DOORS_H
#define DOORS_H

#include <Arduino.h>

#define DOOR1 7
#define DOOR2 8
#define LED_DENIED A1

/**
 * \brief Setup the Doors pins.
 */
void doors_setup();

/**
 * \brief Unlock the deisnated door if the user has acces.
 *
 * \param[in] door_num Verifys which door the user is trying to get acces.
 *
 * \param[in] acces Boolean like variable that verifys if the acces was granted 
 */
void doors_open(int door_num, int* acces);

/**
 * \brief Unlock all doors if you want to open from inside
 */
void doors_indoor_button();

#endif /* DOORS_H */
