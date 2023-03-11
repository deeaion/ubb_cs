//
// Created by Deea on 3/11/2023.
//
#include "../model/electronic.h"
Electronic* createElectronic(int id,char* type,char* producer, char* model,float price,int quantity)
{
    Electronic* electronic=(Electronic*)malloc(sizeof(Electronic));
    electronic->id=id;
    electronic->type=(char*)malloc(sizeof (char)*(strlen(type)+1));
    strcpy(electronic->type,type);
    electronic->producer=(char*)malloc(sizeof (char)*(strlen(producer)+1));
    strcpy(electronic->producer,producer);
    electronic->model=(char*)malloc(sizeof (char)*(strlen(model)+1));
    electronic->price=price;
    electronic->quantity=quantity;
    return electronic;


}

int get_id_electronic(Electronic *e)
{
    return e->id;
}

char* get_producer_electronic(Electronic *e)
{
    return e->producer;
}

char* get_model_electronic(Electronic *e)
{
    return e->model;
}

float get_price_electronic(Electronic *e)
{
    return e->price;
}

int get_quantity_electronic(Electronic *e)
{
    return e->quantity;
}
void toString(Electronic* print_e,char stringToConcatenate[])
{
    char auxiliary[41];
    char num[10],price_s[20];
    int count;
    count=((print_e->price)==0)?1:log10(print_e->price)+1;
    sprintf(num, "%d", print_e->id);
    gcvt (print_e->price, count, price_s);

    strcpy(auxiliary,num);
    strcat(auxiliary,", ");
    strcat(auxiliary,print_e->type);
    strcat(auxiliary,", ");
    strcat(auxiliary,print_e->producer);
    strcat(auxiliary,", ");
    strcat(auxiliary,print_e->model);
    strcat(auxiliary,", ");
    strcat(auxiliary,price_s );
    strcat(auxiliary,", ");
    strcat(auxiliary,num);
}