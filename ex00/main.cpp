#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    // --- THE RIGHT WAY (Polymorphism) ---
    std::cout << "--- RIGHT ANIMALS ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    // --- THE WRONG WAY (No Polymorphism) ---
    std::cout << "\n--- WRONG ANIMALS ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); // Will output the WRONG animal sound!
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat; // Notice: Only WrongAnimal destructor will be called!

    return 0;
}