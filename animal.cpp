#include "animal.h"
#include <iostream>
#include <cstring>
using namespace std;

AnimalList::AnimalList() // Default Constructor
{
    maxSize = 10;
    currentSize = 0;
    list = new Animal*[10];
}

AnimalList::~AnimalList() // Destructor
{
    for(int i = 0; i < currentSize; i++)  
        delete list[i]; // Brackets dereference this - deleting elements of list
    
    delete [] list; // Deleting whole list
}

void Dog::MakeSound()
{
    cout << "Woof!" << endl;
}

void Cat::MakeSound()
{
    cout << "Meow!" << endl;
}

void Pig::MakeSound()
{
    cout << "Oink!" << endl;
}

void Cow::MakeSound()
{
    cout << "Moo!" << endl;
}

void AnimalList::Add(char c)
{
    c = toupper(c); // Forces c to be uppercase
    
    if(currentSize == maxSize)
        Grow();
    
    if(c == 'D')
    {
        Dog *myDog = new Dog;
        list[currentSize] = myDog;
        currentSize++; // Updating my size with the addition of a new Dog
    }

    if(c == 'C')
    {
        Cat *myCat = new Cat;
        list[currentSize] = myCat;
        currentSize++; // Updating my size with the addition of a new Cat
    }

    if(c == 'P')
    {
        Pig *myPig = new Pig;
        list[currentSize] = myPig;
        currentSize++; // Updating my size with the addition of a new Pig
    }

    if(c == 'W')
    {
        Cow *myCow = new Cow;
        list[currentSize] = myCow;
        currentSize++; // Updating my size with the addition of a new Cow
    }
}

void AnimalList::Show()
{
    for(int i = 0; i < currentSize; i++)
        list[i]->MakeSound(); // Can't do list[i].MakeSound because list is an array of pointers, not an object
}

void AnimalList::Grow()
{
    maxSize = currentSize + 1;
    Animal** newList = new Animal*[maxSize];
    for (int i = 0; i < currentSize; i++)     
        newList[i] = list[i];                 
    
    delete [] list; // Remove the old array
    list = newList; // Point old name to new array
}