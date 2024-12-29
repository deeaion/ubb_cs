#ifndef TS_ORDERED_LIST_H
#define TS_ORDERED_LIST_H

#include "SortedArray.h"

typedef struct {
    SortedArray *array;
    int nextPosition;
} TSOrderedList;

TSOrderedList *createTSOrderedList();
int insertToTSOrderedList(TSOrderedList *ts, const char *key, int codAtom);
void printTSOrderedList(TSOrderedList *ts);
void freeTSOrderedList(TSOrderedList *ts);

#endif
