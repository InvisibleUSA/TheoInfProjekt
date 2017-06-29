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

int complex_hash(const struct s_key k) {
    int nr = k.n * 950;
    nr |= k.y * 950 << 4;
    nr |=  k.x  * 950 << 4+5;
    return nr % TABLE_LENGTH;
}

int simple_probe(int hash, int i) {
    return (hash + i) % TABLE_LENGTH;
}

void print_element(const struct s_element * el) {
    if (el)
        printf("Key: %c%c%d%d%d, data: %d, rem: %d\n", el->key.x + 'A', el->key.y + 'A', el->key.n, el->key.n, el->key.n, el->data, el->removed);
}

void print_array(struct s_element * * ar, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", i);
        if (ar[i]) {
            print_element(ar[i]);
        }
        else
            printf("NULL\n");
    }
}

struct s_element * genKey() {
    struct s_element * key = malloc(sizeof(struct s_element));
    key->data = rand();
    key->key.n = (enum Enumber) (rand() % 10);
    key->key.x = (enum Eletter) (rand() % 26);
    key->key.y = (enum Eletter) (rand() % 26);
    key->removed = 0;
    return key;
}