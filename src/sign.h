#ifndef __VOTE_H
#define __VOTE_H

#include "lib/rsa.h"
#include "lib/types.h"
#include <stdbool.h>


/**
 * @file sign.h
 * @brief header of sign.c
 */

/**
 * A struct for storing a signature
 */
typedef struct _Signature{
    int64* xs; /**< int64* the value of the signature on the heap */
    int len; /**< int the size of the contents ("\n" at the end is not included in the size) */
} Signature;

/**
 * Structure for storing a Protected (declaration).
 */
typedef struct _Protected{
    Key* pKey; /**< Author of the declaration*/
    char* msg; /**< Content of the declaration */
    Signature* sig; /**< Signed message*/
} Protected;

Signature* init_signature_raw(int64* content, int size);
Signature* init_signature(const int64* content, int size);
Signature* copy_signature(const Signature* o);
void free_signature(Signature* sig);
Signature* sign(char* mess, Key* sKey);

char* signature_to_str(const Signature* sgn);
Signature* str_to_signature(const char* str);
Signature* str_to_signature_len(const char* str, size_t len);

Protected* init_protected(Key* pKey, char* mess, Signature* sgn);
Protected* init_protected_raw(Key* pKey, char* mess, Signature* sgn);
void free_protected(Protected* pr);
Protected* copy_protected(const Protected* o);
bool verify(const Protected* pr);
char* protected_to_str(const Protected* prc);
Protected* str_to_protected(const char* str);
Protected* str_to_protected_len(const char* str, size_t slen);

#endif