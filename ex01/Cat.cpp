#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(){
    std::cout << "Cat default constructor called." << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat copy constructor called." << std::endl;
    this->_brain = new Brain();

    if (other._brain)
        *(this->_brain) = *(other._brain);
}

Cat& Cat::operator=(const Cat& other){
    std::cout << "Cat copy assignment operator called." << std::endl;
    if (this != &other){
        this->_type = other._type;

        if (this->_brain && other._brain)
            *(this->_brain) = *(other._brain);
    }
    
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat destructor called." << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const{
    std::cout << "Meow!" << std::endl;
}