//
// Created by Deea on 3/11/2023.
//
#include "../service/service.h"

int add_electronic_service(MyList* store, int id, char*type, char*producer, char*model, double price, int quantity)
{
    int position;
    Electronic* e= createElectronic(id,type,producer,model,price,quantity);
    if(validate(e)!=0)
    {   destroyElectronic(e);
        return -1;}
    position= searchElectronic(id,store);
    if(position==-1)
        addElectronic(store,e,position);
    else
    {
        modify_electronic_quantity_by_id(store,id, get_quantity_electronic(store->elems[searchElectronic(id,store)])+quantity);
        destroyElectronic(e);
    }

    return 1;
}
int delete_product_by_id(MyList* store, int id)
{
    return deleteElectronic(id,store);
}

MyList* get_all_service(MyList* store)
{
    return get_all_electronics(store);

}
int modify_electronic_price_by_id(MyList* store,int id, double price)
{
    int position;
    position= searchElectronic(id,store);
    if(position==-1)
        return -1;
    Electronic* modified_electronic= createElectronic(get_id_electronic(store->elems[position]),
                                                      get_type_electronic(store->elems[position]), get_producer_electronic(store->elems[position]), get_model_electronic(store->elems[position]),price, get_quantity_electronic(store->elems[position]));
    if(validate(modified_electronic))
    {destroyElectronic(modified_electronic);
        return -1;
        }
    modifyElectronic(position,modified_electronic,store);
    return 1;
}
int modify_electronic_quantity_by_id(MyList* store,int id, int quantity)
{
    int position;
    position= searchElectronic(id,store);
    if(position==-1)
        return -1;
    Electronic* modified_electronic= createElectronic(get_id_electronic(store->elems[position]),
                                                      get_type_electronic(store->elems[position]), get_producer_electronic(store->elems[position]), get_model_electronic(store->elems[position]),
                                                      get_price_electronic(store->elems[position]), quantity);
    if(validate(modified_electronic))
    {
        destroyElectronic(modified_electronic);
        return -1;
    }
    modifyElectronic(position,modified_electronic,store);
    return 1;
}
void swap(MyList* list,int index1,int index2)
{
    Electronic* temp=list->elems[index1];
    list->elems[index1]=list->elems[index2];
    list->elems[index2]=temp;
}
MyList* sort_in_stock_electronics(MyList* store, int way)
{
    MyList* copy_store= copyList(store);
    for(int i=0;i< copy_store->size-1;i++)
    {
        for(int j=i+1; j<copy_store->size;j++)
        {
            if(way==1)
            {
                if(get_price_electronic(copy_store->elems[i])>get_price_electronic(copy_store->elems[j]))
                {
                    swap(copy_store,i,j);
                }
                if(equal_floats(get_price_electronic(copy_store->elems[i]),get_price_electronic(copy_store->elems[j])))
                {   if(get_quantity_electronic(copy_store->elems[i])>get_quantity_electronic(copy_store->elems[j]))
                    {swap(copy_store,i,j);
                }}

            }
            if(way==-1)
            {
                if(get_price_electronic(copy_store->elems[i])<get_price_electronic(copy_store->elems[j]))
                {
                    swap(copy_store,i,j);
                }
                if(equal_floats(get_price_electronic(copy_store->elems[i]),get_price_electronic(copy_store->elems[j])))
                {   if(get_quantity_electronic(copy_store->elems[i])<get_quantity_electronic(copy_store->elems[j]))
                    {swap(copy_store,i,j);
                    }}
            }
        }
    }
    return copy_store;

}
MyList* filter_by_criteria(MyList* store, int criteria,char name[],double price,int quantity) {
    MyList* new_list= createList(1);
    for(int i=0;i<store->size;i++)
    {
        if(criteria==1)
        {
            if(!strcmp(get_producer_electronic(store->elems[i]),name))
            {Electronic* copy= copyElectronic(store->elems[i]);
                addToList(new_list,copy);
                                                             }
        }
        else if(criteria==2)
        {
            if(equal_floats(get_price_electronic(store->elems[i]),price))
            {
                Electronic* copy= copyElectronic(store->elems[i]);
                addToList(new_list,copy);
            }

        }
        else if(criteria==3)
        {
            if(get_quantity_electronic(store->elems[i])==quantity)
            {
                Electronic* copy= copyElectronic(store->elems[i]);
                addToList(new_list,copy);
            }
        }


    }
    return new_list;
}