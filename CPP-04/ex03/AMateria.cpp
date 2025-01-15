/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:52:32 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/15 14:27:32 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) {
	this->_type = type;
	std::cout << "New AMateria Created" << std::endl;
}

AMateria::AMateria(const AMateria &base) {
	*this = base;
	std::cout << "AMateria copied" << std::endl;
}

const AMateria &AMateria::operator=(const AMateria &rhs) {
	this->_type = std::string(rhs._type);
	std::cout << "AMateria copy assignment called" << std::endl;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria destroyed" << std::endl;
}

const std::string &AMateria::getType() const {
	return (this->_type);
}
