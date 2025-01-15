/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:06:59 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/12 18:35:18 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {

    this->_hp = 100;
    this->_dmg = 30;
    
	std::cout << "FragTrap \"" << this->_name << "\" "
              << "is being created with default constructor" << std::endl;

}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {

    this->_hp = 100;
    this->_dmg = 30;
    
	std::cout << "FragTrap \"" << this->_name << "\" "
              << "is being created with string overloaded constructor" << std::endl;

}

FragTrap::FragTrap(const FragTrap &base) : ClapTrap(base) {
    std::cout << "FragTrap \"" << this->_name << "\" "
              << "is being created with copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    std::cout << "FragTrap \"" << this->_name << "\" "
              << "is being created with copy assignment operator" << std::endl;
    ClapTrap::operator=(rhs);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap \"" << this->_name << "\" destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {

	if (this->get_hp() <= 0) {
		std::cout << "FragTrap \"" << this->_name << "\" "
			<< "has already died" << std::endl;
	}

	else {
		std::cout << "FragTrap \"" << this->_name << "\" "
			<< "says: High five!" << std::endl;
	}

}
