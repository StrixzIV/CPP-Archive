/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:13:49 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:13:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    this->_type = "unnamed";
    std::cout << "Animal of type \"" << this->_type << "\" is being created with default constructor." << std::endl;
}

Animal::Animal(const std::string &animal_type) {
    this->_type = std::string(animal_type);
    std::cout << "Animal of type \"" << this->_type << "\" is being created with string-overloaded constructor." << std::endl;
}

Animal::Animal(const Animal &base) {
    *this = base;
    std::cout << "Animal of type \"" << this->_type << "\" is being created with copy constructor." << std::endl;
}

Animal &Animal::operator=(const Animal &lhs) {

    this->_type = std::string(lhs.getType());
    std::cout << "Animal of type \"" << this->_type << "\" is being created with copy-assignment constructor." << std::endl;

    return (*this);

}

Animal::~Animal() {
    std::cout << "Animal of type \"" << this->_type << "\" has bein slained." << std::endl;
}

const std::string &Animal::getType() const {
    return (this->_type);
}

void Animal::setType(const std::string &animal_type) {
    this->_type = std::string(animal_type);
}

void Animal::makeSound() const {
    std::cout << "Animal of type \"" << this->_type << "\" is making a sound" << std::endl;
}
