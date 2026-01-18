#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;

//     return 0;
// }


#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // --- PART 1: The Zoo (Array of Animals) ---
    // This proves polymorphism and that every Brain is deleted correctly.
    std::cout << "--- CREATING ZOO ---" << std::endl;
    const int size = 4;
    Animal* zoo[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }

    std::cout << "\n--- TESTING SOUNDS ---" << std::endl;
    for (int i = 0; i < size; i++) {
        zoo[i]->makeSound();
    }

    std::cout << "\n--- DELETING ZOO ---" << std::endl;
    for (int i = 0; i < size; i++) {
        delete zoo[i];
    }

    std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
    Dog basic;
    {
        std::cout << "\n--- Creating 'tmp' via Copy Constructor ---" << std::endl;
        Dog tmp = basic;
    }
    
    std::cout << "\n--- If you see this, basic is still alive and safe! ---" << std::endl;

    return 0;
}