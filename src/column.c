#include "column.h"
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>

Column* column_create(size_t size) {
    Column* column = (Column*)malloc(sizeof(Column));
    if (column == NULL) {
        handle_error("Failed to allocate memory for column");
        return NULL;
    }
    column->data = (void**)malloc(size * sizeof(void*));
    if (column->data == NULL) {
        handle_error("Failed to allocate memory for column data");
        free(column);
        return NULL;
    }
    column->size = 0;
    column->capacity = size;
    return column;
}

void column_destroy(Column* column) {
    for (size_t i = 0; i < column->size; ++i) {
        free(column->data[i]);
    }
    free(column->data);
    free(column);
}

void column_push_back(Column* column, const void* value) {
    if (column->size == column->capacity) {
        column->capacity *= 2;
        column->data = (void**)realloc(column->data, column->capacity * sizeof(void*));
        if (column->data == NULL) {
            handle_error("Failed to reallocate memory for column data");
            return;
        }
    }
    column->data[column->size] = (void*)malloc(sizeof(void*));
    if (column->data[column->size] == NULL) {
        handle_error("Failed to allocate memory for column data");
        return;
    }
    memcpy(column->data[column->size], value, sizeof(void*));
    column->size++;
}

const void* column_get(Column* column, size_t index) {
    if (index >= column->size) {
        return NULL;
    }
    return column->data[index];
}

size_t column_size(Column* column) {
    return column->size;
}