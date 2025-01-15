/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:46:16 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:46:16 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->_type = "unnamed";
    std::cout << "WrongAnimal of type \"" << this->_type << "\" is being created with default constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) {
    this->_type = std::string(type);
    std::cout << "WrongAnimal of type \"" << this->_type << "\" is being created with string-overloaded constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &base) {
    *this = base;
    std::cout << "WrongAnimal of type \"" << this->_type << "\" is being created with copy constructor." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {

    this->_type = std::string(rhs.getType());
    std::cout << "WrongAnimal of type \"" << this->_type << "\" is being created with copy-assignment constructor." << std::endl;

    return (*this);

}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal of type \"" << this->_type << "\" has bein slained." << std::endl;
}

const std::string &WrongAnimal::getType() const {
    return (this->_type);
}

void WrongAnimal::setType(const std::string &type) {
    this->_type = std::string(type);
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal of type \"" << this->_type << "\" is making a sound" << std::endl;
}
