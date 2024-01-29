#include <iostream>
using namespace std;

class Animal // Abstract Base Class
{
    public:
    virtual void MakeSound() = 0; // Purely virtual function
};

// 4 Derived Classes
class Dog: public Animal
{
    public:
    void MakeSound();
};

class Cat: public Animal
{
    public:
    void MakeSound();
};

class Pig: public Animal
{
    public:
    void MakeSound();
};

class Cow: public Animal
{
    public:
    void MakeSound();
};

class AnimalList
{
    private:
    Animal** list; // Array of pointers to Animal pointers
    int currentSize;
    int maxSize;

    public:
    AnimalList(); // Default Constructor
    ~AnimalList(); // Destructor
    void Show();
    void Grow();
    void Add(char);
};