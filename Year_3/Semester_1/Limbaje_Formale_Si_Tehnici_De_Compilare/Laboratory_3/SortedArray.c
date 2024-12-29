#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generic element in the sorted array
typedef struct {
    char key[100];  // The key to sort by (e.g., symbol name)
    void *data;     // Pointer to additional data
} SortedArrayElement;

// Sorted Array structure
typedef struct {
    SortedArrayElement *elements;  // Dynamic array of elements
    int size;                      // Current size
    int capacity;                  // Allocated capacity
} SortedArray;

// Function prototypes
SortedArray *createSortedArray();
void freeSortedArray(SortedArray *array);
int binarySearchInsertPosition(SortedArray *array, const char *key);
int insertToSortedArray(SortedArray *array, const char *key, void *data);
void *findInSortedArray(SortedArray *array, const char *key);
void resizeSortedArray(SortedArray *array);

// Create a new sorted array
SortedArray *createSortedArray() {
    SortedArray *array = (SortedArray *)malloc(sizeof(SortedArray));
    array->size = 0;
    array->capacity = 10;  // Initial capacity
    array->elements = (SortedArrayElement *)malloc(array->capacity * sizeof(SortedArrayElement));
    return array;
}

// Free a sorted array
void freeSortedArray(SortedArray *array) {
    free(array->elements);
    free(array);
}

// Binary search to find the insert position
int binarySearchInsertPosition(SortedArray *array, const char *key) {
    int low = 0, high = array->size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(array->elements[mid].key, key);
        if (cmp < 0) {
            low = mid + 1;
        } else if (cmp > 0) {
            high = mid - 1;
        } else {
            return mid;  // Key already exists
        }
    }
    return low;  // Position to insert
}

// Insert into the sorted array
int insertToSortedArray(SortedArray *array, const char *key, void *data) {
    int pos = binarySearchInsertPosition(array, key);

    // Check if the key already exists
    if (pos < array->size && strcmp(array->elements[pos].key, key) == 0) {
        return pos;  // Return existing position
    }

    // Resize if necessary
    if (array->size == array->capacity) {
        resizeSortedArray(array);
    }

    // Shift elements to make room for the new element
    for (int i = array->size; i > pos; i--) {
        array->elements[i] = array->elements[i - 1];
    }

    // Insert the new element
    strcpy(array->elements[pos].key, key);
    array->elements[pos].data = data;
    array->size++;
    return pos;
}

// Find an element in the sorted array
void *findInSortedArray(SortedArray *array, const char *key) {
    int low = 0, high = array->size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(array->elements[mid].key, key);
        if (cmp < 0) {
            low = mid + 1;
        } else if (cmp > 0) {
            high = mid - 1;
        } else {
            return array->elements[mid].data;  // Found
        }
    }
    return NULL;  // Not found
}

// Resize the sorted array
void resizeSortedArray(SortedArray *array) {
    array->capacity *= 2;
    array->elements = (SortedArrayElement *)realloc(array->elements, array->capacity * sizeof(SortedArrayElement));
}
