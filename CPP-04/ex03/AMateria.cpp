/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:52:32 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/13 23:59:23 by jikaewsi         ###   ########.fr       */
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

const AMateria &AMateria::operator=(const AMateria &lhs) {
	this->_type = std::string(lhs._type);
	std::cout << "AMateria copy assignment called" << std::endl;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria destroyed" << std::endl;
}

const std::string &AMateria::getType() const {
	return (this->_type);
}
