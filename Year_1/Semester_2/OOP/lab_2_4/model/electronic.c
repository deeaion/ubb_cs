//
// Created by Deea on 3/11/2023.
//
#include "../model/electronic.h"

int equal_floats(double a,double b)
    { double epsilon=0.000001;
        if(fabs(a-b)< epsilon)
            return 1;
        return 0;
    }
Electronic* createElectronic(int id,char* type,char* producer, char* model,double price,int quantity)
{
    Electronic* electronic=(Electronic*)malloc(sizeof(Electronic));
    electronic->id=id;
    electronic->type=(char*)malloc(sizeof (char)*(strlen(type)+1));
    strcpy(electronic->type,type);
    electronic->producer=(char*)malloc(sizeof (char)*(strlen(producer)+1));
    strcpy(electronic->producer,producer);
    electronic->model=(char*)malloc(sizeof (char)*(strlen(model)+1));
    strcpy(electronic->model,model);
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
char* get_type_electronic(Electronic *e)
{
    return e->type;
}
char* get_model_electronic(Electronic *e)
{
    return e->model;
}

double get_price_electronic(Electronic *e)
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
    count=(int)(((print_e->price)==0)?1:log10(print_e->price)+1);
    sprintf(num, "%d", print_e->id);
    gcvt (print_e->price, count, price_s);
    char q[10];
    sprintf(q,"%d",print_e->quantity);
    strcpy(auxiliary,num);
    strcpy(stringToConcatenate,auxiliary);
    strcat(stringToConcatenate,", ");
    strcat(stringToConcatenate,print_e->type);
    strcat(stringToConcatenate,", ");
    strcat(stringToConcatenate,print_e->producer);
    strcat(stringToConcatenate,", ");
    strcat(stringToConcatenate,print_e->model);
    strcat(stringToConcatenate,", ");
    strcat(stringToConcatenate,price_s );
    strcat(stringToConcatenate,", ");
    strcat(stringToConcatenate,q);
}
Electronic* copyElectronic(Electronic* e)
{
    Electronic* copy=(Electronic*)malloc(sizeof(Electronic));
    copy->id=e->id;
    copy->type=(char*)malloc(sizeof(char)*(strlen(e->type)+1));
    strcpy(copy->type,e->type);
    copy->producer=(char*)malloc(sizeof(char)*(strlen(e->producer)+1));
    strcpy(copy->producer,e->producer);
    copy->model=(char*)malloc(sizeof(char)*(strlen(e->model)+1));
    strcpy(copy->model,e->model);
    copy->price=e->price;
    copy->quantity=e->quantity;
    return copy;
}
int equality(Electronic* first_electronic, Electronic* second_electronic)
{
    if (get_id_electronic(first_electronic)== get_id_electronic(second_electronic))
        if(strcmp(get_type_electronic(first_electronic),get_type_electronic(second_electronic))==0)
            if(strcmp(get_producer_electronic(first_electronic), get_producer_electronic(second_electronic))==0)
                if(strcmp(get_model_electronic(first_electronic), get_model_electronic(second_electronic))==0)
                    if(equal_floats(get_price_electronic(first_electronic), get_price_electronic(second_electronic)))
                        if(get_quantity_electronic(first_electronic)== get_quantity_electronic(second_electronic))
                            return 1;
    return 0;
}
void destroyElectronic(Electronic* e)
{   if(e==NULL)
        return;
    free(e->type);
    free(e->producer);
    free(e->model);
    //free(e);
}