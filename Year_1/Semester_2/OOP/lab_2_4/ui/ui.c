//
// Created by Deea on 3/11/2023.
//
#include "../ui/ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Commands!
 */

void ui_add_electronic(MyList* store)
{   int id_electronic,quantity,success;
    double price;
    char type[21],producer[22],model[23];
    printf("You chose to add and electronic. Please enter your data\n");
    printf("id=\n");
    scanf_s("%d",&id_electronic);
    printf("type=\n");
    scanf_s("%s",&type);
    printf("producer=\n");
    scanf_s("%s",&producer);
    printf("model=\n");
    scanf_s("%s",&model);
    printf("price=\n");
    scanf_s("%lf",&price);
    printf("quantity=\n");
    scanf_s("%d",&quantity);
    success=add_electronic_service(store,id_electronic,type,producer,model,price,quantity);
    if(success==1)
        printf(" Action has been done successfully!");
    else
        printf("An error has occurred!");

}
void runConsole(MyList* store)
{  while(1) {
        int command = 0;
        int valid = -1;
        scanf_s("%d",&command);
        //adding
        if(command==1)
        {
            ui_add_electronic(store);


        }
        else if (command==0)
        {   destroy(store);
            printf("Program will now end!\n");
            return;
        }
    }


}