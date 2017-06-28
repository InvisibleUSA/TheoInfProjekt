//
// Created by Erik on 26.06.2017.
//

#include "helper.h"
#include "time.h"
#include "stdlib.h"

int main(int argc, char ** args) {
    srand((unsigned int) time(NULL));
    initialize();
    probe_function = simple_probe;
    hash_function = complex_hash;
    struct s_element k1 = { key : {x: B, y: M, n: n7}, data: 42};
    struct s_element k4 = { key : {x: B, y: M, n: n7}, data: 02};
    struct s_element k2 = { key : {x: F, y: M, n: n1}, data: 19};
    struct s_element k3 = { key : {x: A, y: I, n: n1}, data : 11};
    struct s_element * k, * l;
    int probe = 0;

    for (int i = 0; i < TABLE_LENGTH; i++) {
        k = genKey();
        int res = insert(k);
        if (res == TABLE_KEY_EXISTS) {
           // printf("Key exists\n");
            free(k);
            i--;
            continue;
        }
        probe = lastProbingSteps;

        l = get(k->key);
        printf("%d\t%d", probe, lastProbingSteps);

        if (probe != lastProbingSteps) printf("err\n");
        else printf("\n");

        if (!l)
            printf("duplicate key or error\n");
        else
        if (k != l)
            printf("ERR\n");
    }
  /*  insert(&k1);
    insert(&k2);
    insert(&k3);
    printf("%d\n", lastProbingSteps);
    insert(&k4);

    print_element(get(k1.key));
    print_element(get(k2.key));
    print_element(get(k3.key));
    print_element(get(k4.key));
    */

    print_array(hash_table, TABLE_LENGTH);
    for (int i = 0; i < TABLE_LENGTH; i++) {
        free(hash_table[i]);
    }
    return 0;
}