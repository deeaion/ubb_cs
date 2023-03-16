//
// Created by Deea on 3/11/2023.
//
#include "../ui/ui.h"
#include <stdio.h>
/*
 * Commands!
 */
void ui_print_menu()
{
    printf("******** MENU ********\n");
    printf("\nPlease enter one of the numbers coressponding to the option you want!\n");
    printf("\t1. Add Electronic product!\n");
    printf("\t2. Modify Electronic product:\n\t\t1.Modify price.\n\t\t2.Modify quantity.\n");
    printf("\t3. Delete Electronic product by id. \n");
    printf("\t4. Sort by price, quantity. (if the price is equal the quantity will be the one that determines the order!)\n");
    printf("\t5. Filter by a criteria. \n \t\t Choices are:\n\t\t\t1.By producer's name.\n\t\t\t2.By price\n\t\t\t3.By quantity\n");
    printf("\t0.Exit\n");
    printf("****************************************************************************");
    printf("\n");
}
void ui_add_electronic(MyList* store)
{   int id_electronic,quantity,success;
    double price;
    char type[21],producer[22],model[23];
    printf("You chose to add and electronic. Please enter your data\n");
    printf("id=\n");
    scanf_s("%d",&id_electronic);
    printf("type=\n");
    scanf_s("%s",type);
    printf("producer=\n");
    scanf_s("%s",producer);
    printf("model=\n");
    scanf_s("%s",model);
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

void ui_delete_electronic(MyList* store)
{   int id,success;
    printf("Delete electronic. Please enter id\n");
    printf("id= ");
    scanf_s("%d",&id);
    success=delete_product_by_id(store,id);
    if(success==1)
        printf(" Action has been done successfully!");
    else
        printf("An error has occurred!");
}
void ui_filter_by_criterea(MyList* store)
{   MyList* filtered;
    int type;
    char name[30];
    strcpy(name,"");
    int quantity=-1;
    double price=-1;
    printf("Filter by:\n choice=");
    scanf_s("%d",&type);
    if(type==1)
    {
        printf("\nname=");
        scanf_s("%s",&name);
    }
    if(type==2)
    {
        printf("\nprice=");
        scanf_s("%lf",&price);
    }
    if(type==3)
    {
        printf("\nquantity=");
        scanf_s("%d",&quantity);
    }

    filtered= filter_by_criteria(store,type,name,price,quantity);
    print_all(filtered);
    destroy(filtered);
}
void print_all(MyList* store)
{
    for(int i=0;i<store->size;i++)
    {char stringToConcatenate[100];
        toString(store->elems[i],stringToConcatenate);
        printf_s(stringToConcatenate);
        printf("\n");
    }
}

void ui_modify_electronic(MyList* store)
{   int id;
    int success=-1;
    double price;
    int quantity;
    int opt;
    printf("You chose to modify an electronics's price or quantity. Please know that you can only modify one or the other!\n");
    printf("Please enter \"1\" for modifying the price\n\t\"2\" for modifying the quantity");
    scanf_s("%d",&opt);
    printf("id=");
    scanf_s("%d",&id);

    if (opt==1)
    {    printf("new price= ");
        scanf_s("%lf",&price);
        success=modify_electronic_price_by_id(store,id,price);
    }
    if(opt==2)
    {
        printf("new quantity= ");
        scanf_s("%d",&quantity);
        success=modify_electronic_quantity_by_id(store,id,quantity);
    }
    if(success==1)
        printf(" Action has been done successfully!");
    else
        printf("An error has occurred!");
}

void ui_sort_by_price_and_quantity(MyList* store)
{   int opt;
    MyList* to_sort;
    printf("Do you want to see the list sorted in descending order or ascending order\n1- ascending, 2-descending\n");
    scanf_s("%d",&opt);
    if(opt==1)
    {
        to_sort=sort_in_stock_electronics(store,opt);
    } else if (opt==2)
    {
        opt=-1;
        to_sort=sort_in_stock_electronics(store,opt);
    } else
    {
        printf("Invalid option");
        return;
    }
    print_all(to_sort);
    destroy(to_sort);
}
void runConsole(MyList* store)
{  while(1) {
        ui_print_menu();
        print_all(store);
        int command = 0;
        scanf_s("%d",&command);
        //adding
        if(command==1)
        {
            ui_add_electronic(store);


        }
        else if(command==3)
        {
            ui_delete_electronic(store);
        }
        else if(command==2)
        {
            ui_modify_electronic(store);
        }
        else if(command==4)
        {
            ui_sort_by_price_and_quantity(store);
        }
        else if(command==5)
        {
            ui_filter_by_criterea(store);
        }
        else if (command==0)
        {   destroy(store);
            printf("Program will now end!\n");
            return;
        } else
        {
            printf("Invalid command\n");
        }
    }


}