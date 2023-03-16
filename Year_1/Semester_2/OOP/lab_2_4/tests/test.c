//
// Created by Deea on 3/14/2023.
//
#include "test.h"

void test_all()
{
    test_electronic();
    test_validate();
    test_my_list();
    test_repo();
    test_service();
}

void test_my_list()
{
    MyList* test_list= createList(1);
    assert(test_list->capacity==1);
    assert(test_list->size==0);
    int id=1;
    char type[]="laptop";
    char producer[]="heh";
    char model[]="1";
    double price=3;
    int quantity=100;
    Electronic *test_electronic=createElectronic(id,type,producer,model,price,quantity);
    addToList(test_list,test_electronic);
    assert(test_list->capacity==1);
    assert(test_list->size==1);
    assert(size(test_list)==1);
    MyList* copy_list= copyList(test_list);
    assert(copy_list->capacity==1);
    assert(copy_list->size==1);
    //trying to add more ->rezise no
    // Adding another element to the list that requires resizing
    int id2 = 2;
    char type2[] = "smartphone";
    char producer2[] = "hmm";
    char model2[] = "2";
    double price2 = 5;
    int quantity2 = 50;
    Electronic *test_electronic3 = createElectronic(id2, type2, producer2, model2, price2, quantity2);
    addToList(test_list, test_electronic3);
    assert(test_list->capacity == 11);
    assert(test_list->size == 2);
    //destroy
    MyList* test_null=NULL;
    assert(destroy(test_null)==1);
    assert(destroy(test_list)==0);
    destroy(copy_list);
    //resize
    MyList* test_resize= createList(1);
    Electronic *test_electronic_2=createElectronic(id,type,producer,model,price,quantity);
    addToList(test_resize,test_electronic_2);
    resize(test_resize);
    assert(test_resize->capacity==11);

    assert(test_resize->size==1);
    destroy(test_resize);

}

void test_electronic()
{   //Electronic* createElectronic(int id,char* type,char* producer, char* model,double price,int quantity)
    int id=1;
    char type[]="laptop";
    char producer[]="heh";
    char model[]="1";
    double price=3;
    int quantity=100;
    Electronic *test_electronic=createElectronic(id,type,producer,model,price,quantity);
    assert(get_id_electronic(test_electronic)==id);
    assert(strcmp(get_type_electronic(test_electronic),type)==0);
    assert(strcmp(get_producer_electronic(test_electronic),producer)==0);
    assert(strcmp(get_model_electronic(test_electronic),model)==0);
    assert(equal_floats(get_price_electronic(test_electronic),price)==1);
    assert(quantity== get_quantity_electronic(test_electronic));
    int id_2=1;
    char type_2[]="laptop";
    char producer_2[]="heh";
    char model_2[]="1";
    double price_2=3;
    int quantity_2=300;
    Electronic *test_electronic_2=createElectronic(id_2,type_2,producer_2,model_2,price_2,quantity_2);
    assert(equality(test_electronic,test_electronic_2));


    assert(equal_floats(2.9,2.1)==0);
    Electronic *test_null=NULL;
    assert(destroyElectronic(test_null)==1);
    //test_electronic
    Electronic *test_electronic_3=createElectronic(2,type_2,producer_2,model_2,price_2,quantity_2);

    assert(equality(test_electronic,test_electronic_3)==0);
    assert(destroyElectronic(test_electronic)==0);
//test to string
    char stringToConcatenate[100];
    toString(test_electronic_2,stringToConcatenate);
    assert(strcmp(stringToConcatenate,"1, laptop, heh, 1, 3.00, 300")==0);
    destroyElectronic(test_electronic_2);
    destroyElectronic(test_electronic_3);
}

void test_repo()
{//add
    MyList* test_list= createList(1);
    int id=1;
    char type[]="laptop";
    char producer[]="heh";
    char model[]="1";
    double price=3;
    int quantity=100;
    Electronic *test_electronic=createElectronic(id,type,producer,model,price,quantity);
    addElectronic(test_list,test_electronic,-1);
    assert(test_list->size==1);

    Electronic *add_equal= createElectronic(id,type,producer,model,price,quantity);
    addElectronic(test_list,add_equal,0);
    //search
    int position;
    position=(searchElectronic(1,test_list));
    assert(position==0);
    assert(searchElectronic(4,test_list)==-1);
    //modify
    int id_2=1;
    char type_2[]="laptop";
    char producer_2[]="heh";
    char model_2[]="1";
    double price_2=3;
    int quantity_2=300;
    Electronic *test_modified=createElectronic(id_2,type_2,producer_2,model_2,price_2,quantity_2);
    Electronic *save_data= copyElectronic(test_modified);
    modifyElectronic(position,test_modified,test_list);
    assert(get_id_electronic(save_data)==id_2);
    assert(strcmp(get_type_electronic(save_data),type_2)==0);
    assert(strcmp(get_producer_electronic(save_data),producer_2)==0);
    assert(strcmp(get_model_electronic(save_data),model_2)==0);
    assert(equal_floats(get_price_electronic(save_data),price_2)==1);
    //getall
    assert(test_list== get_all_electronics(test_list));
    assert(quantity_2== save_data->quantity);
    destroyElectronic(save_data);
    //delete
    //mai adaug
    int id2 = 2;
    char type2[] = "smartphone";
    char producer2[] = "hmm";
    char model2[] = "2";
    double price2 = 5;
    int quantity2 = 50;
    Electronic *test_electronic3 = createElectronic(id2, type2, producer2, model2, price2, quantity2);
    Electronic *pastrare_copie= copyElectronic(test_electronic3);//eu eliberEZ MEMORIA !!!! DECI NU MAI GASESC VALORIILE DUPA!
    addElectronic(test_list,test_electronic3,-1);

    assert(deleteElectronic(5,test_list)==-1);
    assert(deleteElectronic(1,test_list)==1);
    assert(test_list->size==1);
    assert(equality(test_list->elems[0],pastrare_copie));
    destroyElectronic(pastrare_copie);
    destroy(test_list);
    destroyElectronic(add_equal);
}

void test_validate()
{
    int id=1;
    char type[]="laptop";
    char producer[]="heh";
    char model[]="1";
    double price=3;
    int quantity=100;
    Electronic *test_electronic=createElectronic(id,type,producer,model,price,quantity);
    assert(validate(test_electronic)==0);
    destroyElectronic(test_electronic);
    Electronic *test_electronic_1= createElectronic(-2,type,producer,model,price,quantity);
    assert(validate(test_electronic_1)==1);
    destroyElectronic(test_electronic_1);
    Electronic *test_electronic_2= createElectronic(id,"1",producer,model,price,quantity);
    assert(validate(test_electronic_2)==2);
    destroyElectronic(test_electronic_2);
    Electronic *test_electronic_3= createElectronic(id,type,"",model,price,quantity);
    assert(validate(test_electronic_3)==3);
    destroyElectronic(test_electronic_3);
    Electronic *test_electronic_4= createElectronic(id,type,producer,"",price,quantity);
    assert(validate(test_electronic_4)==4);
    destroyElectronic(test_electronic_4);
    Electronic *test_electronic_5= createElectronic(id,type,producer,model,-2,quantity);
    assert(validate(test_electronic_5)==5);
    destroyElectronic(test_electronic_5);
    Electronic *test_electronic_6= createElectronic(id,type,producer,model,price,-100);
    assert(validate(test_electronic_6)==6);
    destroyElectronic(test_electronic_6);

}

void test_service()
{
    MyList* test_list= createList(1);
    assert(test_list->capacity==1);
    assert(test_list->size==0);
    int id=1;
    char type[]="laptop";
    char producer[]="heh";
    char model[]="1";
    double price=3;
    int quantity=100;
    assert(add_electronic_service(test_list,id,type,producer,model,price,quantity)==1);
    assert(add_electronic_service(test_list,id,type,producer,model,price,quantity)==1);
    assert(get_id_electronic(test_list->elems[0])==id);
    assert(strcmp(get_type_electronic(test_list->elems[0]),type)==0);
    assert(strcmp(get_producer_electronic(test_list->elems[0]),producer)==0);
    assert(strcmp(get_model_electronic(test_list->elems[0]),model)==0);
    assert(equal_floats(get_price_electronic(test_list->elems[0]),price)==1);
    assert(200== get_quantity_electronic(test_list->elems[0]));
    assert(add_electronic_service(test_list,-5,type,producer,model,price,quantity)==-1);
    assert(test_list== get_all_service(test_list));
    //modifyprice
    assert(modify_electronic_price_by_id(test_list,id,5)==1);
    assert(equal_floats(get_price_electronic(test_list->elems[0]),5)==1);
    assert(modify_electronic_price_by_id(test_list,10,201)==-1);
    assert(modify_electronic_price_by_id(test_list,1,-5)==-1);
    assert(modify_electronic_quantity_by_id(test_list,1,-100)==-1);
//modify id
    assert(modify_electronic_quantity_by_id(test_list,10,100)==-1);
    assert(modify_electronic_quantity_by_id(test_list,1,200)==1);
    assert(get_quantity_electronic(test_list->elems[0])==200);
    //swap
    add_electronic_service(test_list,3,type,producer,model,price,quantity);
    swap(test_list,0,1);
    assert(get_id_electronic(test_list->elems[1])==id);
    assert(strcmp(get_type_electronic(test_list->elems[1]),type)==0);
    assert(strcmp(get_producer_electronic(test_list->elems[1]),producer)==0);
    assert(strcmp(get_model_electronic(test_list->elems[1]),model)==0);
    assert(equal_floats(get_price_electronic(test_list->elems[1]),5)==1);
    assert(200== get_quantity_electronic(test_list->elems[1]));
    assert(delete_product_by_id(test_list,1)==1);
    //sort in stock electronics
    MyList* sorted_1;
    add_electronic_service(test_list,5,type,producer,model,2.1,51);
    add_electronic_service(test_list,6,type,producer,model,2.1,50);
    sorted_1= sort_in_stock_electronics(test_list,1);
    assert(equality(sorted_1->elems[1],test_list->elems[1])==1);
    assert(equality(sorted_1->elems[0],test_list->elems[2])==1);
    destroy(sorted_1);

    //sort descendingly
    add_electronic_service(test_list,7,type,producer,model,2.1,100);
    add_electronic_service(test_list,10,type,producer,model,500,100);
    MyList* sorted_2;
    sorted_2= sort_in_stock_electronics(test_list,-1);
    assert(equality(sorted_2->elems[0],test_list->elems[4]));
    assert(equality(sorted_2->elems[1],test_list->elems[0]));
    assert(equality(sorted_2->elems[2],test_list->elems[3]));
    assert(equality(sorted_2->elems[3],test_list->elems[1]));
    assert(equality(sorted_2->elems[4],test_list->elems[2]));
    destroy(sorted_2);
    //filtered
    MyList* filter_name;
    filter_name= filter_by_criteria(test_list,1,"heh",-1,-1);
    for(int i=0;i<filter_name->size;i++)
        assert(equality(filter_name->elems[i],test_list->elems[i]));

    destroy(filter_name);
    MyList * filter_price;

    filter_price= filter_by_criteria(test_list,2,"",2.1,-1);

    assert(equality(filter_price->elems[0],test_list->elems[1])==1);

    destroy(filter_price);

    //criteria==3

    MyList* filter_quantity;
    filter_quantity= filter_by_criteria(test_list,3,"",-1,51);
    assert(equality(test_list->elems[1],filter_quantity->elems[0]));
    //delete
    destroy(filter_quantity);
    assert(delete_product_by_id(test_list,100)==-1);

    delete_product_by_id(test_list,3);
    destroy(test_list);


}

