//
// Created by Erik on 26.06.2017.
//

#include "helper.h"
#include "time.h"

int main(int argc, char ** args) {
    srand((unsigned int) time(NULL));
    initialize();
    probe_function = simple_probe;
    hash_function = simple_hash;

    struct s_element * k, * l;
    int probe = 0, maxprobesteps = 0;

    for (int i = 0; i < TABLE_LENGTH + 10; i++) {
        k = genKey();
        int res = insert(k);
        if (res == TABLE_KEY_EXISTS) {
           // printf("Key exists\nr1");
            free(k);
            i--;
            continue;
        }
        if (res == TABLE_FULL) {
            printf("Table full!");
            //TODO: expand hash table when full
            break;
        }
        probe = lastProbingSteps;
        if (maxprobesteps < lastProbingSteps) maxprobesteps = lastProbingSteps;

        l = get(k->key);
        /*printf("%d\t%d", probe, lastProbingSteps);

        if (probe != lastProbingSteps) printf("err\nr1");
        else printf("\nr1");*/

        if (!l)
            printf("duplicate key or error\n");
        else
        if (k != l)
            printf("ERR\n");
    }

    print_array(hash_table, TABLE_LENGTH);
    printf("max probe: %d\n", maxprobesteps);
    for (int i = 0; i < TABLE_LENGTH; i++) {
        free(hash_table[i]);
    }
    return 0;
}