//
// Created by Deea on 3/11/2023.
//
#include "../model/electronic.h"
//type->laptop,frigider,televizor,altele
int validate(Electronic* electronic)
{
    if(electronic->id<0)
        return 1;
    int ok=-1;
    if(strcmp(electronic->type, "laptop") == 0 ||
       strcmp(electronic->type, "frigider") == 0 ||
       strcmp(electronic->type, "televizor") == 0 ||
       strcmp(electronic->type, "altele") == 0)
        ok=1;
    if(ok==-1)
        return 2;
    if(strlen(electronic->producer)==0)
        return 3;
    if(strlen(electronic->model)==0)
        return 4;
    if(electronic->price<0)
        return 5;
    if(electronic->quantity<0)
        return 6;
    return 0;
}