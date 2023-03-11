#include <iostream>
#include <vector>

using namespace std;

// Klasa bazowa
class Animal {
public:
    // Metoda wirtualna
    virtual void makeSound() {
        cout << "Animal sound\n";
    }
};

// Klasa pochodna
class Cat : public Animal {
public:
    // Nadpisanie metody wirtualnej
    void makeSound() override {
        cout << "Meow\n";
    }
};

// Klasa pochodna
class Dog : public Animal {
public:
    // Nadpisanie metody wirtualnej
    void makeSound() override {
        cout << "Woof\n";
    }
};

int main() {
    // Polimorfizm dynamiczny
    Animal* animalPtr;
    Cat cat;
    Dog dog;

    animalPtr = &cat;
    animalPtr->makeSound(); // wywołanie metody z klasy Cat

    animalPtr = &dog;
    animalPtr->makeSound(); // wywołanie metody z klasy Dog

    // Polimorfizm statyczny
    vector<Animal*> animals;
    animals.push_back(new Cat);
    animals.push_back(new Dog);

    for (auto animal : animals) {
        animal->makeSound(); // wywołanie odpowiedniej metody wirtualnej
    }

    // Zwolnienie pamięci
    for (auto animal : animals) {
        delete animal;
    }

    return 0;
}