/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:49:43 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 01:49:43 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
    std::cout << "Cure materia created with default constructor" << std::endl;
}

Cure::Cure(const Cure &base): AMateria(base) {
    std::cout << "Cure materia copied" << std::endl;
}

const Cure &Cure::operator=(const Cure &rhs) {
    this->_type = std::string(rhs._type);
    return (*this);
}

Cure::~Cure() {
    std::cout << "Cure materia destroyed" << std::endl;
}

AMateria *Cure::clone() const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
