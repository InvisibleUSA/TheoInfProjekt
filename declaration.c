//
// Created by Erik on 26.06.2017.
//

#include "declaration.h"

int compare(struct s_key k1, struct s_key k2) {
    return (k1.nr1 == k2.nr1) && (k1.nr3 == k2.nr3) && (k1.nr2 == k2.nr2) && (k1.x == k2.x) && (k1.y == k2.y);
}

const int TABLE_KEY_EXISTS    = 1;
const int TABLE_NO_HASH_FUNC  = 2;
const int TABLE_NO_PROBE_FUNC = 3;
const int TABLE_FULL          = 4;
const int TABLE_KEY_NOT_FOUND = 5;
