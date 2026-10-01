#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dictionary Dictionary;

Dictionary* dictionary_create(void);
void dictionary_destroy(Dictionary* dictionary);
int dictionary_add(Dictionary* dictionary, const void* key, void* value);
void* dictionary_get(Dictionary* dictionary, const void* key);

#endif // DICTIONARY_H