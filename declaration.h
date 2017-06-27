//
// Created by Erik on 26.06.2017.
//

#ifndef THEOINFPROJEKT_DECLARATION_H
#define THEOINFPROJEKT_DECLARATION_H
#include "stddef.h"

enum Eletter { A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
enum Enumber { n0 = 0, n1, n2, n3, n4, n5, n6, n7, n8, n9};
struct s_key {
    enum Eletter x;
    enum Eletter y;
    enum Enumber n;
};

struct s_element {
    struct s_key key;
    int data;
};

/**
 * Checks two keys for equality.
 * @param k1 first key
 * @param k2 second key
 * @return 1 if equal, 0 if unequal
 */
int compare(struct s_key k1, struct s_key k2);

const int TABLE_KEY_NOT_FOUND;
const int TABLE_KEY_EXISTS;
const int TABLE_NO_HASH_FUNC;
const int TABLE_NO_PROBE_FUNC;
const int TABLE_FULL;

#endif //THEOINFPROJEKT_DECLARATION_H
