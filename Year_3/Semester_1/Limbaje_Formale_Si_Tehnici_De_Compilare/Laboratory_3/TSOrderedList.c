#include "SortedArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TS Entry structure
typedef struct {
    int codAtom;
    int position;
} TSData;

// Wrapper around the sorted array
typedef struct {
    SortedArray *array;  // Underlying sorted array
    int nextPosition;    // Next position to assign
} TSOrderedList;

// Create a new TSOrderedList
TSOrderedList *createTSOrderedList() {
    TSOrderedList *ts = (TSOrderedList *)malloc(sizeof(TSOrderedList));
    ts->array = createSortedArray();
    ts->nextPosition = 1;
    return ts;
}

// Insert into TSOrderedList
int insertToTSOrderedList(TSOrderedList *ts, const char *key, int codAtom) {
    // Check if the key already exists
    TSData *existing = (TSData *)findInSortedArray(ts->array, key);
    if (existing) {
        return existing->position;  // Return existing position
    }

    // Create a new TSData
    TSData *data = (TSData *)malloc(sizeof(TSData));
    data->codAtom = codAtom;
    data->position = ts->nextPosition++;

    // Insert into the sorted array
    insertToSortedArray(ts->array, key, data);
    return data->position;
}

// Print TSOrderedList (for debugging)
void printTSOrderedList(TSOrderedList *ts) {
    printf("TSOrderedList:\n");
    for (int i = 0; i < ts->array->size; i++) {
        TSData *data = (TSData *)ts->array->elements[i].data;
        printf("Key: %s, CodAtom: %d, Position: %d\n",
               ts->array->elements[i].key, data->codAtom, data->position);
    }
}

// Free TSOrderedList
void freeTSOrderedList(TSOrderedList *ts) {
    for (int i = 0; i < ts->array->size; i++) {
        free(ts->array->elements[i].data);
    }
    freeSortedArray(ts->array);
    free(ts);
}
