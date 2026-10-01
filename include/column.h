#ifndef COLUMN_H
#define COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Column Column;

Column* column_create(size_t size);
void column_destroy(Column* column);
void column_push_back(Column* column, const void* value);
const void* column_get(Column* column, size_t index);
size_t column_size(Column* column);

#endif // COLUMN_H