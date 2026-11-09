#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
using namespace std;

class Student : public Person {
private:
    string department;
    double gpa;

public:
    Student(int i, string n, string d, double g)
        : Person(i, n), department(d), gpa(g) {}

    ~Student() override {}

    double getGpa() const {
        return gpa;
    }

    virtual double tuition() const {
        return 1000;
    }

    void display() const override {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nDepartment: " << department
             << "\nGPA: " << gpa
             << "\nTuition: " << tuition() << endl;
    }
};

class GraduateStudent : public Student {
private:
    string topic;

public:
    GraduateStudent(int i, string n, string d,
                    double g, string t)
        : Student(i, n, d, g), topic(t) {}

    ~GraduateStudent() override {}

    double tuition() const override {
        return 1500;
    }

    void display() const override {
        Student::display();
        cout << "Research Topic: " << topic << endl;
    }
};

class Manager {
private:
    vector<Person*> students;

public:
    ~Manager() {
        for (Person* s : students)
            delete s;
    }

    void add(Person* s) {
        if (search(s->getId())) {
            cout << "ID already exists!\n";
            delete s;
            return;
        }
        students.push_back(s);
        cout << "Added successfully!\n";
    }

    Person* search(int id) const {
        for (Person* s : students)
            if (s->getId() == id) return s;
        return nullptr;
    }

    Person* search(string name) const {
        for (Person* s : students)
            if (s->getName() == name) return s;
        return nullptr;
    }

    void display() const {
        if (students.empty())
            cout << "No students found!\n";

        for (Person* s : students)
            s->display();
    }

    void remove(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->getId() == id) {
                delete students[i];
                students.erase(students.begin() + i);
                cout << "Deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }
};

#endif
