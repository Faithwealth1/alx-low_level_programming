#include <stdlib.h>
#include "hash_table.h"

hash_table_t *hash_table_create(unsigned long int size) {
    // Allocate memory for the hash table
    hash_table_t *table = malloc(sizeof(hash_table_t));
    if (table == NULL) {
        // Failed to allocate memory
        return NULL;
    }

    // Allocate memory for the array of buckets
    table->buckets = malloc(size * sizeof(bucket_t));
    if (table->buckets == NULL) {
        // Failed to allocate memory
        free(table);
        return NULL;
    }

    // Initialize the buckets
    for (unsigned long int i = 0; i < size; i++) {
        table->buckets[i].head = NULL;
    }

    // Set the size of the hash table
    table->size = size;

    return table;
}
