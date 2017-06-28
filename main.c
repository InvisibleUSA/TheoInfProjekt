//
// Created by Erik on 26.06.2017.
//

#include "helper.h"
#include "time.h"
#include "stdlib.h"

int main(int argc, char ** args) {
    srand(time(NULL));
    initialize();
    probe_function = simple_probe;
    hash_function = simple_hash;
    struct s_element k1 = { key : {x: B, y: M, n: n7}, data: 42};
    struct s_element k2 = { key : {x: F, y: M, n: n1}, data: 19};
    struct s_element k3 = { key : {x: B, y: I, n: n7}, data : 11};
    struct s_element * k, * l;

    for (int i = 0; i < 1000; i++) {
        k = genKey();
        int res = insert(k);
        if (res == TABLE_KEY_EXISTS) {
            printf("Key exists\n");
            free(k);
            continue;
        }

        l = get(k->key);
        if (!l)
            printf("duplicate key or error\n");
        else
            if (k != l)
                printf("ERR\n");
    }
    /*insert(&k1);
    insert(&k2);
    insert(&k3);

    print_element(get(k1.key));
    print_element(get(k2.key));
    print_element(get(k3.key));*/

    print_array(hash_table, TABLE_LENGTH);
    for (int i = 0; i < TABLE_LENGTH; i++) {
        free(hash_table + i);
    }
    return 0;
}