#include "Student.h"
#include <limits>

int main() {
    Manager m;
    int choice, id;
    string name, dept, topic;
    double gpa;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Graduate Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Search By ID\n";
        cout << "5. Search By Name\n";
        cout << "6. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {

        case 1:
        case 2:
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Department: ";
            getline(cin, dept);

            cout << "Enter GPA (0-4): ";
            cin >> gpa;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (gpa < 0 || gpa > 4) {
                cout << "Invalid GPA!\n";
                break;
            }

            if (choice == 1) {
                m.add(new Student(id, name, dept, gpa));
            }
            else {
                cout << "Research Topic: ";
                getline(cin, topic);

                m.add(new GraduateStudent(
                    id, name, dept, gpa, topic
                ));
            }
            break;

        case 3:
            m.display();
            break;

        case 4:
            cout << "Enter ID: ";
            cin >> id;

            if (m.search(id))
                m.search(id)->display();
            else
                cout << "Student not found!\n";
            break;

        case 5:
            cout << "Enter Name: ";
            getline(cin, name);

            if (m.search(name))
                m.search(name)->display();
            else
                cout << "Student not found!\n";
            break;

        case 6:
            cout << "Enter ID: ";
            cin >> id;
            m.remove(id);
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
