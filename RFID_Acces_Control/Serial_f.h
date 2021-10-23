#ifndef SERIAL_F_H
#define SERIAL_F_H

#include <Arduino.h>

/**
 * \brief Initializes the Serial comunication 
 */
void serialf_setup();

/**
 * \brief Prints on the serial monitor the tag id
 *
 * \param[out] id Prints the id on the serial monitor
 */
void serialf_print_tagid(char* id);

/**
 * \brief Waits until the serial has something
 */
void serialf_wait_for_serial ();

/**
 * \brief Prints on the serial monitor "Acces Granted"
 */
void serialf_print_accesgranted();

/**
 * \brief Prints on the serial monitor "Acces Denied"
 */
void serial_print_accesdenied();

/**
 * \brief Prints on the serial monitor a waiting message
 */
void serialf_print_waiting_msg();

/**
 * \brief Prints on the serial monitor a waiting message for door 1
 */
void serialf_print_waiting_door1();

/**
 * \brief Prints on the serial monitor a waiting message for door 2
 */
void serialf_print_waiting_door2();

/**
 * \brief Prints on the serial monitor a waiting message for registering a new tag
 */
void serialf_print_waiting_add_tag();

/**
 * \brief Prints on the serial monitor if the tag was registered or not
 *
 * \param[in] is_id_registerd Boolean like variable to check if the id is already registered
 */
void serialf_print_registering_msg(int is_id_registerd);

/**
 * \brief Prints on the serial monitor that the last tag was removed
 */
void serialf_print_del_tag_msg();

/**
 * \brief Prints on the serial monitor that the doors are beign unlock from inside
 */
void serialf_print_indoor_button();

/**
 * \brief Prints on the serial monitor the timeout mensage
 */
void serialf_print_timeout();

#endif /* SERIAL_F_H */
