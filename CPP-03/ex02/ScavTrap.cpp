/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:06:59 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/12 18:41:09 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {

    this->_hp = 100;
    this->_mp = 50;
    this->_dmg = 20;
    
	std::cout << "ScavTrap \"" << this->_name << "\" "
              << "is being created with default constructor" << std::endl;

}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {

    this->_hp = 100;
    this->_mp = 50;
    this->_dmg = 20;
    
	std::cout << "ScavTrap \"" << this->_name << "\" "
              << "is being created with string overloaded constructor" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &base) : ClapTrap(base) {
    std::cout << "ScavTrap \"" << this->_name << "\" "
              << "is being created with copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    ClapTrap::operator=(rhs);
    std::cout << "ScavTrap \"" << this->_name << "\" "
              << "is being created with copy assignment operator" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap \"" << this->_name << "\" destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {

	if (this->get_mp() > 0 && this->get_hp() > 0) {

		std::cout << "ScavTrap \"" << this->_name << "\" "
			<< "attacked " << target
			<< ", causing " << this->get_dmg() << " point(s) of damage!" << std::endl;
	
		this->_mp--;

	}

	if (this->get_hp() <= 0) {
		std::cout << "ScavTrap \"" << this->_name << "\" is dead!" << std::endl;
	}

	else if (this->get_mp() == 0) {
		std::cout << "ScavTrap \"" << this->_name << "\" is is out of energy points!" << std::endl;
	} 

}

void ScavTrap::guardGate() {

	if (this->get_hp() <= 0) {
		std::cout << "ScavTrap \"" << this->_name << "\" "
			<< "has already died" << std::endl;
	}

	else {
		std::cout << "ScavTrap \"" << this->_name << "\" "
			<< "has entered Gate Keeper mode!" << std::endl;
	}

}
