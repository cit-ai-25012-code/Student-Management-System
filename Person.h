#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;

public:
    Person(int i, string n) : id(i), name(n) {}

    virtual ~Person() {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    virtual void display() const = 0;
};

#endif
