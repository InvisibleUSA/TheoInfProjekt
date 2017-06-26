//
// Created by Erik on 26.06.2017.
//

#include "declaration.h"


#ifndef THEOINFPROJEKT_HASHING_H
#define THEOINFPROJEKT_HASHING_H

#define TABLE_LENGTH 1312

struct s_element * hash_table[TABLE_LENGTH];

/**
 * Pointer to hash-function
 * It must return an array index between 0 and TABLE_LENGTH in any case
 */
int (*hash_function)(const struct s_key);

/**
 * Contains the number of probing steps that were necessary for last call of insert, remove, get
 */
int g_lastProbingSteps;

/**
 * Puts the given element in the hash_table. hash_table may not contain an element with the same key or else, 1 is returned.
 * @param element pointer to element, that should be inserted
 * @return 0 on success, 1 if key already exists within hash_table.
 */
int insert(struct s_element * element);

/**
 * Deletes element with same key as key given as parameter.
 * @param key key to element which should be deleted
 * @return 0 on success, 1 if not found
 */
int remove(struct s_key key);

/**
 * Searches for the element with key key.
 * @param key
 * @return pointer to element on success, NULL otherwise
 */
struct s_element * get(struct s_key key);

#endif //THEOINFPROJEKT_HASHING_H
