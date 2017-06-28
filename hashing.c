//
// Created by Erik on 26.06.2017.
//

#include "hashing.h"

int (*hash_function)(const struct s_key) = NULL;
struct s_key (*probe_function)(struct s_key, int) = NULL;

int insert(struct s_element * element) {
    int errCode = checkHashAndProbeFunction();
    if (errCode) return errCode;

    int pos = 0;
    int probeStep = 0;
    struct s_key key;
    do {
        key = probe_function(element->key, probeStep++);
        pos = hash_function(key);
        if (hash_table[pos])
            if (compare(hash_table[pos]->key, element->key))
                return TABLE_KEY_EXISTS;
        if (probeStep >= TABLE_LENGTH)
            return TABLE_FULL;
    } while (hash_table[pos]);
    lastProbingSteps = probeStep - 1;
    hash_table[pos] = element;
    return 0;
}


int rem(struct s_key key) {
    int errCode = checkHashAndProbeFunction();
    if (errCode) return errCode;


}

struct s_element * get(struct s_key key) {
    if (checkHashAndProbeFunction()) return NULL;
    int pos = 0;
    struct s_key k;
    int probeStep = 0;
    int found = 0;
    do {
        k = probe_function(key, probeStep++);
        pos = hash_function(k);
        if (compare(hash_table[pos]->key, k))
            found = 1;
        if (probeStep >= TABLE_LENGTH)
            return NULL;
    } while (!found);
    lastProbingSteps = probeStep - 1;
    return hash_table[pos];
}

void initialize() {
    for (int i = 0; i < TABLE_LENGTH; i++)
        hash_table[i] = NULL;
}

int checkHashAndProbeFunction() {
    if (!probe_function)
        return TABLE_NO_PROBE_FUNC;
    if (!hash_function)
        return TABLE_NO_HASH_FUNC;
    return 0;
}