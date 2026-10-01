#include "scanner.h"
#include "column.h"
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>

void scanner_init(VectorizedScanner* scanner, Column* column, Dictionary* dictionary) {
    scanner->column = column;
    scanner->dictionary = dictionary;
    scanner->index = 0;
}

void scanner_scan(VectorizedScanner* scanner, size_t start, size_t end) {
    for (size_t i = start; i < end; ++i) {
        const void* value = column_get(scanner->column, i);
        if (value != NULL) {
            void* dict_value = dictionary_get(scanner->dictionary, value);
            if (dict_value != NULL) {
                // Perform some operation with the dictionary value
                printf("Value: %s, Dictionary Value: %s\n", (char*)value, (char*)dict_value);
            }
        }
    }
}

const void* scanner_get(VectorizedScanner* scanner, size_t index) {
    if (index >= column_size(scanner->column)) {
        return NULL;
    }
    return column_get(scanner->column, index);
}