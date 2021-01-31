#include <iostream>
using namespace std;

class Animal
{
    static int number;
public:
    friend void print();
    Animal(){++number;}
    virtual ~Animal() {--number;}
};
class Dog:public Animal
{
    static int number;
public:
    friend void print();
    Dog(){++number;}
    virtual ~Dog() {--number;}
};
class Cat:public Animal
{
    static int number;
public:
    friend void print();
    Cat(){++number;}
    virtual ~Cat() {--number;}
};
int Animal::number = 0;
int Dog::number = 0;
int Cat::number = 0;
void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}