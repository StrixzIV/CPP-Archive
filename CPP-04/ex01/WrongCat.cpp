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

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->_type = "Cat";
    std::cout << "WrongCat(from WrongAnimal) of type \"" << this->_type << "\" is being created with default constructor." << std::endl;
}

WrongCat::WrongCat(const std::string &cat_type): WrongAnimal(cat_type) {
    this->_type = std::string(cat_type);
    std::cout << "WrongCat(from WrongAnimal) of type \"" << this->_type << "\" is being created with string-overloaded constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat &base): WrongAnimal(base) {
    *this = base;
    std::cout << "WrongCat(from WrongAnimal) of type \"" << this->_type << "\" is being created with copy constructor." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &lhs) {

    WrongAnimal::operator=(lhs);
    std::cout << "WrongCat(from WrongAnimal) of type \"" << this->_type << "\" is being created with copy-assignment constructor." << std::endl;

    return (*this);

}

WrongCat::~WrongCat() {
    std::cout << "WrongCat(from WrongAnimal) of type \"" << this->_type << "\" has bein slained." << std::endl;
}

const std::string &WrongCat::getType() const {
    return (this->_type);
}

void WrongCat::setType(const std::string &cat_type) {
    this->_type = std::string(cat_type);
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat(from WrongAnimal) of type \"" << this->_type << "\" is meowing" << std::endl;
}
