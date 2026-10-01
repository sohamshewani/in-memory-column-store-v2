#include <stdio.h>
#include "column.h"
#include "dictionary.h"
#include "scanner.h"

int main() {
    Column* column = column_create(10);
    Dictionary* dictionary = dictionary_create();

    column_push_back(column, (void*)"apple");
    column_push_back(column, (void*)"banana");
    column_push_back(column, (void*)"cherry");

    dictionary_add(dictionary, (void*)"apple", (void*)"fruit");
    dictionary_add(dictionary, (void*)"banana", (void*)"fruit");
    dictionary_add(dictionary, (void*)"cherry", (void*)"fruit");
    dictionary_add(dictionary, (void*)"dog", (void*)"animal");

    VectorizedScanner scanner;
    scanner_init(&scanner, column, dictionary);
    scanner_scan(&scanner, 0, 3);

    column_destroy(column);
    dictionary_destroy(dictionary);

    return 0;
}