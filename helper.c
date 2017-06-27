//
// Created by Erik on 26.06.2017.
//

#include "helper.h"

int simple_hash(const struct s_key k) {
    int nr = k.n;
    nr |= k.y << 4;
    nr |=  k.x << 4+5;
    return nr % TABLE_LENGTH;
}

struct s_key simple_probe(struct s_key k, int i) {
    k.x = (k.x + i) % (26*26*10);
    k.y = (k.y + i) % (26*10);
    k.n = (k.n + i) % 10;

    return k;
}

void print_element(const struct s_element * el) {
    printf("Key: %d%d%d%d%d, data: %d\n", el->key.x, el->key.y, el->key.n, el->key.n, el->key.n, el->data);
}