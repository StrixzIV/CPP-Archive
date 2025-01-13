/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:13:49 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:13:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
    this->_brain = new Brain();
    std::cout << "Dog(from Animal) of type \"" << this->_type << "\" is being created with default constructor." << std::endl;
}

Dog::Dog(const Dog &base): Animal(base) {
    this->_brain = new Brain(*(base._brain));
    std::cout << "Dog(from Animal) of type \"" << this->_type << "\" is being created with copy constructor." << std::endl;
}

Dog &Dog::operator=(const Dog &lhs) {

    if (this == &lhs) {
        return (*this);
    }

    Animal::operator=(lhs);

    delete this->_brain;    
    this->_brain = new Brain(*lhs._brain);

    std::cout << "Dog(from Animal) of type \"" << this->_type << "\" is being created with copy-assignment constructor." << std::endl;

    return (*this);

}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog(from Animal) of type \"" << this->_type << "\" has bein slained." << std::endl;
}

const std::string &Dog::getType() const {
    return (this->_type);
}

Brain &Dog::getBrain() const {
    return (*(this->_brain));
}

void Dog::setType(const std::string &Dog_type) {
    this->_type = std::string(Dog_type);
}

void Dog::setBrain(const Brain &brain) {
    *(this->_brain) = brain;
}

void Dog::makeSound() const {
    std::cout << "Dog(from Animal) of type \"" << this->_type << "\" is woofing" << std::endl;
}
