/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:49:43 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 01:49:43 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
    std::cout << "Ice materia created with default constructor" << std::endl;
}

Ice::Ice(const Ice &base): AMateria(base) {
    std::cout << "Ice materia copied" << std::endl;
}

const Ice &Ice::operator=(const Ice &rhs) {
    this->_type = std::string(rhs._type);
    return (*this);
}

Ice::~Ice() {
    std::cout << "Ice materia destroyed" << std::endl;
}

AMateria *Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}
