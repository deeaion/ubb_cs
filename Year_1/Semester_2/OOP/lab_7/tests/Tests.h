//
// Created by Deea on 4/1/2023.
//

#ifndef LAB_6_TESTS_H
#define LAB_6_TESTS_H
#include "../service/SubjectsService.h"
#include "../repository/SubjectsRepo.h"
#include "../domain/Subject.h"
#include "../Exceptions/Exceptions.h"
#include <assert.h>

class Tests {
    void testDomain();
    static void testConstructorsandgetters();
    static void testCopyConstructor();
    static void testSetters();
    void testtoString();
    void testOperators();
    void testComparators();


    void testRepository();
    void testStoreAdd_Search();
    void testUpdate_Remove();
    void testGetters();

    void testValidators();

    void testService();
    void testAdd_SearchService();
    void testDeleteandUpdateService();
    void testSortService();
    void testDynamicVector();

public:
    Tests(){};
    void testAll();
    ~Tests(){

    };
};


#endif //LAB_6_TESTS_H
