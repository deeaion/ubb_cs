//
// Created by Deea on 3/31/2023.
//


#include "SubjectsUi.h"

using std::ws;

void SubjectsUi::UiAdd() {
    cout << "You chose to add a subject:\n";
    string name;
    string teacher;
    string type;
    int hours;
    cout << "\n\tname: ";
    cin >> name;
    cout << "\n\thours: ";
    cin >> hours;
    cout << "\n\tteacher: ";
    cin >> teacher;
    cout << "\n\ttype: ";
    cin >> type;
    ctr.addSubject(name, hours, teacher, type);

}

void SubjectsUi::Uidelete() {
    string name, teacher;
    cout << "You chose to delete a subject!\n";
    cout << "name :";
    cin >> name;
    cout << "\nteacher: ";
    cin >> teacher;
    ctr.deleteSubject(name, teacher);
}

void SubjectsUi::Uifilter() {
    string option;
    cout << "You chose to filter. Please enter your option";
    cin >> option;
    if (option == "hours") {
        int hours;
        cout << "\nHours input: ";
        cin >> hours;
        DynamicVector<Subject> subjects_filtered = ctr.filterByHours(hours);
        print_subjects(subjects_filtered);
    } else if (option == "teacher") {
        string teacher;
        cout << "\nTeacher input: ";
        cin >> teacher;
        const DynamicVector<Subject>& subjects_filtered = ctr.filterByTeacher(teacher);
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
    DynamicVector<Subject> sorted_list;
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

void SubjectsUi::print_subjects(const DynamicVector<Subject> &subjects) {
    if (!subjects.empty()) {
        for (auto subject: subjects) {
            cout << subject.to_string_print() << "\n";

        }
    } else {
        cout << "There are no subjects.\n";
    }
}

void SubjectsUi::print_all() {
    const DynamicVector<Subject> &subjects = ctr.getAll();
    if (!subjects.empty()) {
        cout << "Here is all your subject:\n";
        for (Subject subject: subjects) {
            cout << subject.to_string_print() << "\n";

        }
        cout << "~~END OF LIST~~\n";
    } else
        cout << "There are no subjects.\n";
}

void SubjectsUi::menu() {
    cout << "\n";
    cout << "---------Menu---------\n";
    cout << "||||COMMANDS||||\n";
    cout << "\t0.End program!\n";
    cout << "\t1.Add Subject.\n";
    cout << "\t2.Delete Subject.\n";
    cout << "\t3.Show all Subjects.\n";
    cout << "\t4.Update a Subject.\n";
    cout << "\t5.Search for an object\n";
    cout << "\t----------------------------------\n";
    cout << "\t\tFILTERS AND SORTING OPERATIONS\n";
    cout << "\t\t\t6.Filter by: number of hours or teacher\n";
    cout
            << "\t\t\t7.Sort by name of Subject or number of hours or teacher and type of subject\n";
    cout << "Print menu~!\n";
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
    }
}
