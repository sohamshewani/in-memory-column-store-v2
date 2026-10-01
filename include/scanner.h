#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <stdlib.h>

void scanner_init(VectorizedScanner* scanner, Column* column, Dictionary* dictionary);
void scanner_scan(VectorizedScanner* scanner, size_t start, size_t end);
const void* scanner_get(VectorizedScanner* scanner, size_t index);

#endif // SCANNER_H