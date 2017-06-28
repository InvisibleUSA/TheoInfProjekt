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
    struct s_element k4 = { key : {x: B, y: M, n: n7}, data: 02};
    struct s_element k2 = { key : {x: F, y: M, n: n1}, data: 19};
    struct s_element k3 = { key : {x: A, y: I, n: n1}, data : 11};

    insert(&k1);
    insert(&k2);
    insert(&k3);
    printf("%d\n", lastProbingSteps);
    insert(&k4);

    print_element(get(k1.key));
    print_element(get(k2.key));
    print_element(get(k3.key));
    print_element(get(k4.key));

    print_array(hash_table, TABLE_LENGTH);
    return 0;
}