//
// Created by erik on 27.06.17.
//

#ifndef THEOINF_HELPER_H
#define THEOINF_HELPER_H

#include "stdio.h"
#include "hashing.h"

int simple_hash(const struct s_key k);
struct s_key simple_probe(struct s_key k, int i);
void print_element(const struct s_element * el);

#endif //THEOINF_HELPER_H
