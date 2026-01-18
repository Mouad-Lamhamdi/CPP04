#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->_type = "Cat";
    std::cout << "WrongCat default constructor called." << std::endl;  
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    std::cout << "WrongCat copy assignment operator calle." << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat sound!!" << std::endl;
}