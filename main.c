//
// Created by Erik on 26.06.2017.
//

#include "helper.h"

int main(int argc, char ** args) {
    initialize();
    probe_function = simple_probe;
    hash_function = simple_hash;
    struct s_element k1 = { key : {x: B, y: M, n: n7}, data: 42};
    struct s_element k2 = { key : {x: F, y: M, n: n1}, data: 19};
    struct s_element k3 = { key : {x: B, y: I, n: n7}, data : 11};

    insert(&k1);
    insert(&k2);
    insert(&k3);
    print_element(get(k1.key));
    print_element(get(k2.key));
    print_element(get(k3.key));

    return 0;
}