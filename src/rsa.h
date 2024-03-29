#ifndef __RSA_H
#define __RSA_H

#include "lib/security.h"
#include "lib/types.h"
#include <stdbool.h>

/**
 * @file rsa.h
 * @brief header of rsa.c
 */

/**
 * A struct for storing a key
 */
typedef struct _Key{
    int64 v, n; /**< int64 (v, n) the value of the key */
} Key;

void init_key(Key* key, int64 val, int64 n);
Key* copy_key(const Key* o);
char* key_to_str(const Key* key); 
Key* str_to_key(const char* str);
void init_pair_keys(Key* pKey, Key* sKey, int low_size, int up_size);

bool generate_key_values(int64 p, int64 q, int64* n, int64* s, int64* u);
int64* encrypt(const char* chaine, int64 s, int64 n);
char* decrypt(const int64* crypted, int size, int64 u, int64 n);

#endif