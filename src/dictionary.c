#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>

Dictionary* dictionary_create(void) {
    Dictionary* dictionary = (Dictionary*)malloc(sizeof(Dictionary));
    if (dictionary == NULL) {
        handle_error("Failed to allocate memory for dictionary");
        return NULL;
    }
    dictionary->count = 0;
    dictionary->entries = NULL;
    return dictionary;
}

void dictionary_destroy(Dictionary* dictionary) {
    if (dictionary->entries != NULL) {
        for (size_t i = 0; i < dictionary->count; ++i) {
            free(dictionary->entries[i].key);
            free(dictionary->entries[i].value);
        }
        free(dictionary->entries);
    }
    free(dictionary);
}

int dictionary_add(Dictionary* dictionary, const void* key, void* value) {
    for (size_t i = 0; i < dictionary->count; ++i) {
        if (memcmp(key, dictionary->entries[i].key, sizeof(void*)) == 0) {
            // Key already exists, replace the value
            free(dictionary->entries[i].value);
            dictionary->entries[i].value = (void*)malloc(sizeof(void*));
            if (dictionary->entries[i].value == NULL) {
                handle_error("Failed to allocate memory for dictionary entry");
                return 0;
            }
            memcpy(dictionary->entries[i].value, value, sizeof(void*));
            return 1;
        }
    }
    // Key does not exist, add new entry
    dictionary->entries = (DictionaryEntry*)realloc(dictionary->entries, (dictionary->count + 1) * sizeof(DictionaryEntry));
    if (dictionary->entries == NULL) {
        handle_error("Failed to reallocate memory for dictionary entries");
        return 0;
    }
    dictionary->entries[dictionary->count].key = (void*)malloc(sizeof(void*));
    if (dictionary->entries[dictionary->entries->count].key == NULL) {
        handle_error("Failed to allocate memory for dictionary entry key");
        return 0;
    }
    dictionary->entries[dictionary->entries->count].value = (void*)malloc(sizeof(void*));
    if (dictionary->entries[dictionary->entries->count].value == NULL) {
        handle_error("Failed to allocate memory for dictionary entry value");
        return 0;
    }
    memcpy(dictionary->entries[dictionary->entries->count].key, key, sizeof(void*));
    memcpy(dictionary->entries[dictionary->entries->count].value, value, sizeof(void*));
    dictionary->count++;
    return 1;
}

void* dictionary_get(Dictionary* dictionary, const void* key) {
    for (size_t i = 0; i < dictionary->count; ++i) {
        if (memcmp(key, dictionary->entries[i].key, sizeof(void*)) == 0) {
            return dictionary->entries[i].value;
        }
    }
    return NULL;
}