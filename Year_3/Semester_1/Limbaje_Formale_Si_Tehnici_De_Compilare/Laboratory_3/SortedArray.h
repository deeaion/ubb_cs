#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

// Generic element in the sorted array
typedef struct {
    char key[100];
    void *data;
} SortedArrayElement;

// Sorted Array structure
typedef struct {
    SortedArrayElement *elements;
    int size;
    int capacity;
} SortedArray;

// Function prototypes
SortedArray *createSortedArray();
void freeSortedArray(SortedArray *array);
int binarySearchInsertPosition(SortedArray *array, const char *key);
int insertToSortedArray(SortedArray *array, const char *key, void *data);
void *findInSortedArray(SortedArray *array, const char *key);
void resizeSortedArray(SortedArray *array);

#endif
