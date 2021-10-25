#ifndef ID_12_H
#define ID_12_H

// IDs that are already registered
#define ID_1   "4F0088EFD8F0"
#define ID_2   "3B008EBC5C55"
#define ID_3   "4F0088D84956"
//--------------------------------------------

#include <Arduino.h>
#include <string.h>

extern int max_num_ids; //max number of ifs that can be registered
extern int number_of_registered_ids; //number of registered ids

/**
 * \brief Starts the program with some ids already registered
 *
 */
void id12_setup();

/**
 * \brief Read the data from the serial and stores on the id char array parameter
 *
 * \param[in] id Gets the id read from the serial
 * 
 * \param[out] timeout_counter Necessary for the timeout logic
 */
void id12_read_id(char* id, int& timeout_counter);

/**
 * \brief Checks if the id is registered on the array
 *
 * \param[in] id Gets the id read from the serial
 *
 * \param[out] id_is_on_the_list Boolean like variable to check to check if the id is registered
 */
void id12_check_id(char* id, int* id_is_on_the_list);

/**
 * \brief Register another id to the array
 *
 * \param[in] id Gets the id read from the serial
 *
 * \param[in] id_is_on_the_list Boolean like variable to check to check if the id is registered
 */
void id12_add_id(char* id, int id_is_on_the_list);

/**
 * \brief Deletes the last id on the list, the one with the higher index
 *
 */
void id12_del_id();


#endif /* ID_12_H */
