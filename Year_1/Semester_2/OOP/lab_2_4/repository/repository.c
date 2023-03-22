//
// Created by Deea on 3/11/2023.
//
#include "../repository/repository.h"

int addElectronic(MyList *store, Electronic *electronic, int position) {
    if (position == -1)
        {addToList(store, electronic);}
    return 0;

}

int deleteElectronic(int id, MyList *electronic_store) {
    int index;
    index = searchElectronic(id, electronic_store);
    int i;
    if (index == -1)
        return -1;
    destroyElectronic(electronic_store->elems[index]);
    for (i = index; i < electronic_store->size - 1; i++) {
        electronic_store->elems[i] = electronic_store->elems[i + 1];

    }

    electronic_store->size--;

    return 1;
}

int searchElectronic(int id, MyList *electronic_store) {
    int size;
    size = electronic_store->size;
    for (int i = 0; i < size; i++) {
        if (get_id_electronic(electronic_store->elems[i]) == id)
            return i;
    }
    return -1;
}

int modifyElectronic(int index, Electronic *modified_electronic, MyList *store) {
    destroyElectronic(store->elems[index]);
    store->elems[index] = copyElectronic(modified_electronic);
    destroyElectronic(modified_electronic);
    return 1;
}

MyList * get_all_electronics(MyList *electronic_store) {
    return electronic_store;
}