/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:06:59 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 21:36:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():  ScavTrap(), FragTrap() {

	ClapTrap::_name = "not set_clap_name";
    
	std::cout << "DiamondTrap \"" << this->_name << "\" "
              << "is being created with default constructor" << std::endl;

}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {

	this->_name = std::string(name);
    
	std::cout << "DiamondTrap \"" << this->_name << "\" "
              << "is being created with string overloaded constructor" << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &base) : ScavTrap(base), FragTrap(base) {
	
	this->_name = base.get_name();

	std::cout << "DiamondTrap \"" << this->_name << "\" "
              << "is being created with copy constructor" << std::endl;

}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
    FragTrap::operator=(rhs);
    std::cout << "DiamondTrap \"" << this->_name << "\" "
              << "is being created with copy assignment operator" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap \"" << this->_name << "\" destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {

	if (this->get_hp() <= 0) {
		std::cout << "DiamondTrap \"" << this->_name << "\" "
			<< "has already died" << std::endl;
	}

	else {
		std::cout << "DiamondTrap's name \"" << this->_name << "\" " << std::endl;
		std::cout << "ClapTrap's name \"" << ClapTrap::_name << "\" " << std::endl;
	}

}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

const std::string &DiamondTrap::get_name() const {
	return this->_name;
}

void DiamondTrap::set_name(const std::string &name) {
	this->_name = name;
}
