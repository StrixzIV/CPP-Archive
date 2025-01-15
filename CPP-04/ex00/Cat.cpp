/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:13:49 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:13:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
    std::cout << "Cat(from Animal) of type \"" << this->_type << "\" is being created with default constructor." << std::endl;
}

Cat::Cat(const std::string &cat_type): Animal(cat_type) {
    this->_type = std::string(cat_type);
    std::cout << "Cat(from Animal) of type \"" << this->_type << "\" is being created with string-overloaded constructor." << std::endl;
}

Cat::Cat(const Cat &base): Animal(base) {
    *this = base;
    std::cout << "Cat(from Animal) of type \"" << this->_type << "\" is being created with copy constructor." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {

    Animal::operator=(rhs);
    std::cout << "Cat(from Animal) of type \"" << this->_type << "\" is being created with copy-assignment constructor." << std::endl;

    return (*this);

}

Cat::~Cat() {
    std::cout << "Cat(from Animal) of type \"" << this->_type << "\" has bein slained." << std::endl;
}

const std::string &Cat::getType() const {
    return (this->_type);
}

void Cat::setType(const std::string &cat_type) {
    this->_type = std::string(cat_type);
}

void Cat::makeSound() const {
    std::cout << "Cat(from Animal) of type \"" << this->_type << "\" is meowing" << std::endl;
}
