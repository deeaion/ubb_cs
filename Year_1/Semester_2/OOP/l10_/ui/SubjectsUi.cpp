//
// Created by Deea on 3/31/2023.
//


#include "SubjectsUi.h"

using std::ws;

void SubjectsUi::UiAdd() {
    cout << "You chose to add a subject:";
    string name;
    string teacher;
    string type;
    int hours;
    cout << "\n\tname: ";
    cin >> name;
    cout << "\thours: ";
    cin >> hours;
    cout << "\tteacher: ";
    cin >> teacher;
    cout << "\ttype: ";
    cin >> type;
    ctr.addSubject(name, hours, teacher, type);

}
void SubjectsUi::Uimapf() {
    const auto &found=ctr.creatingmap();
    for (auto const& [key, val] : found)
    {
        cout<<"TYPE: "<<key<<"\n";
        print_subjects(val);
    }
}
void SubjectsUi::Uidelete() {
    string name, teacher;
    cout << "You chose to delete a subject!\n";
    cout << "name :";
    cin >> name;
    cout << "teacher: ";
    cin >> teacher;
    ctr.deleteSubject(name, teacher);
}
void SubjectsUi::Uifilter() {
    string option;
    cout << "You chose to filter. Please enter your option\n";
    cin >> option;
    if (option == "hours") {
        int hours;
        cout << "\nHours input: ";
        cin >> hours;
        vector<Subject> subjects_filtered = ctr.filterByHours(hours);
        print_subjects(subjects_filtered);
    } else if (option == "teacher") {
        string teacher;
        cout << "\nTeacher input: ";
        cin >> teacher;
        vector<Subject> subjects_filtered = ctr.filterByTeacher(teacher);
        print_subjects(subjects_filtered);
    } else {
        cout << "Invalid input!";
    }

}

void SubjectsUi::Uisearch() {
    string name, teacher;
    cout << "You chose to search for a subject!\n";
    cout << "name :";
    cin >> name;
    cout << "\nteacher: ";
    cin >> teacher;
    Subject to_print = ctr.searchForSubject(name, teacher);
    cout << "\nYour subject is: " << std::endl << to_print.to_string_print() << std::endl;
}

void SubjectsUi::Uiupdate() {
    string name, teacher;
    cout << "You chose to update a subject! Please enter the name and teacher.\n";
    cout << "name :";
    cin >> name;
    cout << "\nteacher: ";
    cin >> teacher;

    int hours;
    string type;
    cout << "\n new/old hours: ";
    cin >> hours;
    cout << "\n new/old type: ";
    cin >> type;
    ctr.updateSubject(name, teacher, hours, type);
    Subject to_print = ctr.searchForSubject(name, teacher);
    cout << "\nYour modified subject is: " << std::endl << to_print.to_string_print() << std::endl;
}

void SubjectsUi::Uisort() {
    cout << "You chose to sort the list\n";
    cout << "Your criteria is: ";
    vector<Subject> sorted_list;
    string criteria;
    cin >> criteria;
    if (criteria == "name") {

        sorted_list = ctr.sortByName();
        print_subjects(sorted_list);

    }
    if (criteria == "hours") {

        sorted_list = ctr.sortByHours();
        print_subjects(sorted_list);

    }
    if (criteria == "teacher+type") {

        sorted_list = ctr.sortByTeacherandType();
        print_subjects(sorted_list);

    }


}

void SubjectsUi::print_subjects(const vector<Subject> &subjects) {
    if (!subjects.empty()) {
        for (const Subject& subject: subjects) {
            cout << subject.to_string_print() << "-----------\n";

        }
    } else {
        cout << "There are no subjects.\n";
    }
}

void SubjectsUi::print_all() {
    cout<<"UH"<<std::endl;
    const vector<Subject> &subjects = ctr.getAll();
    if (!subjects.empty()) {
        cout << "Here is all your subject:\n";
        for (const Subject& subject: subjects) {
            cout << subject.to_string_print() << "\n-----------\n";

        }
        cout << "~~END OF LIST~~\n";
    } else
        cout << "There are no subjects.\n";
}




void SubjectsUi::UiAddToContract() {
    cout<<"You chose to add a subject to a contract\n. Please enter the name";
    string name;
    cin>>name;
    auto found=ctr.filterBySubjectName(name);
    if(found.empty())
        cout<<"There is no subject with that name.\n";
    if(found.size()==1)
    {cout<<"Object Added.";
        ctr.add_to_contract(name,found[0].get_teacher(),found);

    }
    if(found.size()>1)
    {cout<<"There were multiple subjects found with that name. This is the list:\n";
    print_subjects(found);
    string teacher;
    cout<<"Please either enter a certain teacher name or any other input if u want it to be chosen randomly!";
    cin>>teacher;
        ctr.add_to_contract(name,teacher,found);
    }
    cout<<"The size of the contract: "<<ctr.getContractSize()<<std::endl;


}

void SubjectsUi::UiGenerateContract() {
    int nr;
    cout<<"How many subjects should it generate ";
    cin>>nr;
    cout<<std::endl;
    ctr.generateContract(nr);
    cout<<"The size of the contract: "<<ctr.getContractSize()<<std::endl;

}

void SubjectsUi::UiExportContract() {
    cout<<"Give the name of the file ";
    string name;
    cin>>name;
    ctr.exportContract(name);
    cout<<"\nThe size of the contract: "<<ctr.getContractSize()<<std::endl;
}
void SubjectsUi::UiEmptyContract() {
    ctr.emptyContract();
    cout<<"\nThe size of the contract: "<<ctr.getContractSize()<<std::endl;
}




void SubjectsUi::menu() {
    cout << "\n";
    cout << "---------Menu---------\n";
    cout << "||||COMMANDS||||\n";
    cout << "0.End program!\n";
    cout << "1.Add Subject.\n";
    cout << "2.Delete Subject.\n";
    cout << "3.Show all Subjects.\n";
    cout << "4.Update a Subject.\n";
    cout << "5.Search for an object\n";
    cout << "----------------------------------\n";
    cout << "***FILTERS AND SORTING OPERATIONS***\n";
    cout << "6.Filter by: number of hours or teacher\n";
    cout << "7.Sort by name of Subject or number of hours or teacher and type of subject\n";
    cout << "8.Print menu~!\n";
    cout<<"9.Add to Contract!\n";
    cout<<"10.Generate Contract!\n";
    cout<<"11.Export Contract!\n";
    cout<<"12.Empty Contract!\n";
    cout<<"13.Undo!\n";
    cout<<"14.Map filtering!Filter all types\n";
    cout << "\n---------------------------------------------------------------------------------------------------\n";

}

void SubjectsUi::start() {
    int command = -1;
    menu();
    while (true) {

        cout << "Your input is\n";
        cin >> command;
        if (command == 0)
            return;
        if (command == 1) {
            try {
                UiAdd();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
        }
        if (command == 2) {
            try {
                Uidelete();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
        }
        if (command == 3) {
            print_all();
        }
        if (command == 4) {
            try {
                Uiupdate();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
        }
        if (command == 5) {
            try {
                Uisearch();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
        }
        if (command == 6) {
            try {
                Uifilter();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
        }
        if (command == 7) {
            try {
                Uisort();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
        }
        if (command == 8) {
            menu();
        }
        if (command == 9) {
            try {
                UiAddToContract();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
            catch (ContractException &e)
            {
                cout << e.getMessage() << std::endl;
            }
        }
        if (command == 10) {
            try {
                UiGenerateContract();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
            catch (ContractException &e)
            {
                cout << e.getMessage() << std::endl;
            }
        }
        if (command == 11) {
            try {
                UiExportContract();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
            catch (ContractException &e)
            {
                cout << e.getMessage() << std::endl;
            }
        }
        if (command == 12) {
            try {
                UiEmptyContract();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
            catch (ContractException &e)
            {
                cout << e.getMessage() << std::endl;
            }
        }
        if (command == 13) {
            try {
                ctr.Undo();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
            catch (ContractException &e)
            {
                cout << e.getMessage() << std::endl;
            }
        }
        if (command == 14) {
            try {
                Uimapf();
            }
            catch (RepositoryException &e) {
                cout << e.getMessage() << std::endl;
            }
            catch (ValidatorException &ve) {
                cout << ve.getMessage() << std::endl;
            }
            catch (ContractException &e)
            {
                cout << e.getMessage() << std::endl;
            }
        }

    }
}
