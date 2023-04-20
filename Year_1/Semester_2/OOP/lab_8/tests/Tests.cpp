////
//// Created by Deea on 4/1/2023.
////
//
//#include "Tests.h"
//void Tests::testAll() {
//    testDomain();
//    testRepository();
//    testValidators();
//    testService();
//}
//void Tests::testDomain() {
//    testConstructorsandgetters();
//    testCopyConstructor();
//    testtoString();
//    testOperators();
//    testComparators();
//    testSetters();
//}
//
//void Tests::testConstructorsandgetters() {
//    Subject testsubject{"1",1,"1","1"};
//    assert(testsubject.get_type()=="1");
//    assert(testsubject.get_teacher()=="1");
//    assert(testsubject.get_hours()==1);
//    assert(testsubject.get_name()=="1");
//    Subject testimplicit{};
//    assert(testimplicit.get_type().empty());
//    assert(testimplicit.get_teacher().empty());
//    assert(testimplicit.get_hours()==-1);
//    assert(testimplicit.get_name().empty());
////    std::cout<<std::endl<<"THESE ARE FROM CREATING^"<<std::endl;
//
//}
//void Tests::testCopyConstructor() {
//    Subject testsubject{"1",1,"1","1"};
//    Subject testcopySubject(testsubject);
//    assert(testcopySubject.get_type()=="1");
//    assert(testcopySubject.get_teacher()=="1");
//    assert(testcopySubject.get_hours()==1);
//    assert(testcopySubject.get_name()=="1");
////    std::cout<<std::endl<<"THESE ARE FROM COPY CONSTRUCTOR^"<<std::endl;
//
//
//}
//void Tests::testSetters() {
//    Subject testsubject{"1",1,"1","1"};
//    testsubject.set_type("new");
//    assert(testsubject.get_type()=="new");
//    testsubject.set_hours(3);
//    assert(testsubject.get_hours()==3);
////    std::cout<<std::endl<<"THESE ARE FROM SETTERS^"<<std::endl;
//}
//void Tests::testtoString() {
//    Subject testsubject{"1",1,"1","1"};
//    assert(testsubject.to_string_print()=="\tSubject 1\n\tHours: 1\n\tType: 1\n\tTeacher: 1");
////    std::cout<<std::endl<<"THESE ARE FROM TO STRING^"<<std::endl;
//
//}
//void Tests::testOperators() {
//    Subject test1{"1",1,"1","1"};
//    assert(test1.operator==(test1));
//    Subject test2=test1;
//    assert(test2.get_type()=="1");
//    assert(test2.get_teacher()=="1");
//    assert(test2.get_hours()==1);
//    assert(test2.get_name()=="1");
////    std::cout<<std::endl<<"THESE ARE FROM OPERATORS^"<<std::endl;
//
//}
//void Tests::testComparators() {
//    Subject test1{"1",1,"1","1"};
//    Subject test2{"2",2,"2","2"};
//    assert(cmpName(test1,test2)== true);
//    assert(cmpName(test2,test1)== false);
//    assert(cmpHours(test1,test2)== true);
//    assert(cmpHours(test2,test1)== false);
//    assert(cmpTeacher(test1,test2)== true);
//    assert(cmpTeacher(test2,test1)== false);
//    assert(cmpType(test1,test2)== true);
//    assert(cmpType(test2,test1)== false);
//    assert(cmpTeacherandType(test1,test2)==true);
//    assert(cmpTeacherandType(test2,test1)==false);
//    Subject test3{"2",1,"2","1"};
//    assert(cmpTeacherandType(test1,test3)==true);
//    assert(cmpTeacherandType(test1,test3)==true);
//    assert(cmpTeacherandType(test3,test1)==false);
//    assert(cmpTeacherandType(test1,test1)==false);
//    Subject sbj1("Math", 4, "Mr. Jk", "History");
//    Subject sbj2("English", 3, "Mr. Jones", "History");
//    assert(cmpTeacherandType(sbj1,sbj2)== true);
//    Subject test4{"2",1,"1","2"};
//    assert(cmpTeacherandType(test3,test4)== true);
//    assert(cmpTeacherandType(test4,test3)== false);
//    assert(cmpTeacherandType(test3,test3)== false);
////    std::cout<<"THESE ARE FROM COMPARATORS^"<<std::endl;
//}
//
//void Tests::testRepository() {
//    testStoreAdd_Search();
//    testUpdate_Remove();
////    std::cout<<std::endl<<"THESE ARE FROM CREATING REPO^"<<std::endl;
//}
//
//void Tests::testStoreAdd_Search() {
//    SubjectsRepo repo;
//    Subject testsubject{"1", 1, "1", "1"};
//    repo.store(testsubject);
//    try {
//        repo.store(testsubject);
//    }
//    catch (RepositoryException &mes) {
//        assert(mes.getMessage() == "Subject already exists\n");
//    }
//    assert(repo.searchForSubject("1","1") != -1);
//    Subject test2{"2",2,"2","2"};
//    assert(repo.searchForSubject("2","2") == -1);
//    const Subject& testequality=repo.getSubject("1","1");
//    assert(testsubject.operator==(testequality));
//    try{
//        repo.getSubject("3","3");
//    }
//    catch (RepositoryException &mes)
//    {
//        assert(mes.getMessage()=="Subject does not exist!");
//    }
////    std::cout<<std::endl<<"THESE ARE FROM REPO STORE AND SEARCH^"<<std::endl;
//}
//
//void Tests::testUpdate_Remove() {
//    SubjectsRepo repo;
//    Subject testsubject{"1", 1, "1", "1"};
//    repo.store(testsubject);
//    const vector<Subject>& uh= repo.getAll();
//    assert(uh.size()==1);
////    std::cout<<"\nADDED IN REPO\n";
//    Subject update{"1",2,"2","1"};
//    repo.updateSubjectRepo(update);
////    std::cout<<"\nUPDATED IN REPO\n";
//    try{
//        repo.updateSubjectRepo(Subject{"2",2,"2","2"});
//    }
//    catch(RepositoryException &mes)
//    {
//        assert(mes.getMessage()=="Subject does not exist!");
//    }
//    repo.removeSubjectRepo("1","1");
//    try{
//        repo.removeSubjectRepo("1","1");
//    }
//    catch (RepositoryException &mes)
//    {
//        assert(mes.getMessage()=="Subject does not exist!");
//    }
////    std::cout<<std::endl<<"THESE ARE FROM UPDATE STORE AND REMOVE^"<<std::endl;
//}
//
//void Tests::testValidators() {
//    ValidatorSubject val;
//    Subject testsubject{"1", 1, "1", "1"};
//    Subject wrong{};
//    val.validateSubject(testsubject);
//    try{
//    val.validateSubject(wrong);}
//    catch(ValidatorException &val)
//    {
//        assert(val.getMessage()=="\nInvalid name \n Invalid number of hours.\nInvalid teacher.\nInvalid type ");
//
//    }
////    std::cout<<std::endl<<"THESE ARE FROM VALIDATORS^"<<std::endl;
//}
//
//void Tests::testService() {
//    testAdd_SearchService();
//    testDeleteandUpdateService();
//    testSortService();
//    //testFilterService();
//}
//
//void Tests::testAdd_SearchService() {
////    std::cout<<"\nSERVICE ADD\n";
//    SubjectsRepo repo;
//    ValidatorSubject val;
//    ContractRepo contract;
//    SubjectsService serv(repo,val,contract);
//    Subject ver{"1",1,"1","1"};
//    serv.addSubject("1",1,"1","1");
////    std::cout<<"\nADDED IN SERVICE\n";
//    const vector<Subject>& sbjs= serv.getAll();
////    std::cout<<"\nGET ALL SERVICE\n";
//    assert(sbjs.size()==1);
//    try{
//        serv.addSubject("1",1,"1","1");
//    }
//    catch (RepositoryException &mes)
//    {
//        assert(mes.getMessage()=="Subject already exists\n");
//    }
//    assert(ver.operator==(serv.searchForSubject("1","1")));
////    std::cout<<"\nTHESE WERE FROM ADD AND SEARCH\n";
//}
//
//void Tests::testDeleteandUpdateService() {
//
//    SubjectsRepo repo;
//    ValidatorSubject val;
//    SubjectsService serv(repo,val);
//    Subject ver{"1",1,"1","1"};
//    serv.addSubject("1",1,"1","1");
////    std::cout<<"\nADDED SERVICE\n";
//    serv.updateSubject("1","1",2,"2");
////    std::cout<<"\nUPDATE SERVICE\n";
//    try {
//        serv.updateSubject("2","2",1,"1");
//
//    }
//    catch (RepositoryException &mes)
//    {
//        assert(mes.getMessage()=="Subject does not exist!");
//    }
//    serv.deleteSubject("1","1");
//    try {
//        serv.deleteSubject("1","1");
//
//    }
//    catch (RepositoryException &mes)
//    {
//        assert(mes.getMessage()=="Subject does not exist!");
//    }
////    std::cout<<"\nTHESE ARE FROM UPDATE AND REMOVE\n";
//}
//
//void Tests::testSortService() {
////    std::cout<<"\nSORT\n";
//    SubjectsRepo repo;
//    ValidatorSubject val;
//    SubjectsService serv(repo,val);
//    Subject ver2{"1",1,"1","1"};
//    Subject ver1{"2",2,"2","2"};
//    serv.addSubject("2",2,"2","2");
//    serv.addSubject("1",1,"1","1");
////    std::cout<<"\nSORT BY NAME\n";
//    vector<Subject> sn=serv.sortByName();
////    std::cout<<"\nTHOSE ARE THE COPIES\n";
//    assert(ver1.operator==(sn[1]));
//    assert(ver2.operator==(sn[0]));
//    vector<Subject> sh=serv.sortByHours();
//    assert(ver1.operator==(sh[1]));
//    assert(ver2.operator==(sh[0]));
//    vector<Subject> stt=serv.sortByTeacherandType();
//    assert(ver1.operator==(stt[1]));
//    assert(ver2.operator==(stt[0]));
////    std::cout<<"\nFINISHED SORT\n";
//    vector<Subject> fh=serv.filterByHours(2);
//    assert(ver1.operator==(fh[0]));
//    vector<Subject> ft=serv.filterByTeacher("2");
//    assert(ver1.operator==(ft[0]));
//    serv.deleteSubject("1","1");
//
//    vector<Subject> s=serv.sortByName();
//    assert(ver1.operator==(s[0]));
//    serv.deleteSubject("2","2");
//
//}