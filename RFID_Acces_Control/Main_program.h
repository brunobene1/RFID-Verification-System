#ifndef MAIN_PROGRAM_H
#define MAIN_PROGRAM_H

#include <Arduino.h>
#include <Wire.h>
#include "ID_12.h"
#include "Serial_f.h"
#include "Doors.h"
#include "Buttons_manager.h"
#include "Lcd_f.h"

/**
 * \brief Has all the setup functions 
 */
void main_program_setup();

/**
 * \brief Has the mais program loop that runs forever
 */
void main_program_loop();


#endif /* MAIN_PROGRAM_H */
