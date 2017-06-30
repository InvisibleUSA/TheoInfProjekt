//
// Created by Erik on 26.06.2017.
//

#include "hashing.h"

int (*hash_function)(const struct s_key) = NULL;
int (*probe_function)(int, int) = NULL;

int insert(struct s_element * element) {
    int errCode = checkHashAndProbeFunction();
    if (errCode) return errCode;

    int res = 0;
    element->removed = 0;

    int pos = 0, pos1;
    int probeStep = 0;
    pos = hash_function(element->key);
    do {
        pos1 = probe_function(pos, probeStep++);
        if (hash_table[pos1])
            if (!hash_table[pos1]->removed)
                if (compare(hash_table[pos1]->key, element->key)) {
                    res = TABLE_KEY_EXISTS;
                    break;
                }
        if (probeStep >= TABLE_LENGTH) {
            res = TABLE_FULL;
            break;
        }
    } while (hash_table[pos1]);
    lastProbingSteps = probeStep - 1;
    if (!res)
        hash_table[pos1] = element;
    return res;
}


int rem(struct s_key key) {
    int errCode = checkHashAndProbeFunction();
    if (errCode) return errCode;

    struct s_element *k = get(key);
    if (!k)
        return TABLE_KEY_NOT_FOUND;
    k->removed = 1;
    return 0;
}

struct s_element * get(struct s_key key) {
    if (checkHashAndProbeFunction()) return NULL;
    int pos = 0, pos1;
    int probeStep = 0;
    int found = 0;
    struct s_element * res = NULL;
    pos = hash_function(key);
    do {
        pos1 = probe_function(pos, probeStep++);
        if (compare(hash_table[pos1]->key, key)) {
            if (hash_table[pos1]->removed)
                break;
            found = 1;
        }
        if (probeStep >= TABLE_LENGTH)
            break;
    } while (!found);
    lastProbingSteps = probeStep - 1;
    if (found)
        res = hash_table[pos1];
    return res;
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