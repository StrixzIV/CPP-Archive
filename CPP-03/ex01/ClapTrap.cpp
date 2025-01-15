/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:57:09 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/12 18:43:08 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

	this->_name = "not set";
	this->_hp = 10;
	this->_mp = 10;
	this->_dmg = 0;

	std::cout << "ClapTrap \"" << this->_name << "\" "
		<< "is being created with default constructor" << std::endl;

}

ClapTrap::ClapTrap(const std::string &name) {

	this->_name = name;
	this->_hp = 10;
	this->_mp = 10;
	this->_dmg = 0;

	std::cout << "ClapTrap \"" << this->_name << "\" "
		<< "is being created with string overloaded constructor" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &base) {

	*this  = base;

	std::cout << "ClapTrap \"" << this->_name << "\" "
		<< "is being created with copy constructor" << std::endl;

}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)  {

	this->_name = rhs.get_name();
	this->_hp = rhs.get_hp();
	this->_mp = rhs.get_mp();
	this->_dmg = rhs.get_dmg();
	
	std::cout << "ClapTrap \"" << this->_name << "\" "
		<< "is being created with copy assignment constructor" << std::endl;

	return (*this);

}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap \"" << this->_name << "\" destroyed" << std::endl;
}

const std::string &ClapTrap::get_name() const {
	return this->_name;
}

const int &ClapTrap::get_hp() const {
	return this->_hp;
}

const int &ClapTrap::get_mp() const {
	return this->_mp;
}

const int &ClapTrap::get_dmg() const {
	return this->_dmg;
}

void ClapTrap::set_name(const std::string &name) {
	this->_name = name;
}

void ClapTrap::set_hp(const int &value) {
	this->_hp = value;
}

void ClapTrap::set_mp(const int &value) {
	this->_mp = value;
}

void ClapTrap::set_dmg(const int &value) {
	this->_dmg = value;
}

void ClapTrap::attack(const std::string &target) {

	if (this->_mp > 0 && this->_hp > 0) {

		std::cout << "ClapTrap \"" << this->_name << "\" "
			<< "attacked " << target
			<< ", causing " << this->_dmg << " point(s) of damage!" << std::endl;
	
		this->_mp--;

	}

	if (this->_hp <= 0) {
		std::cout << "ClapTrap \"" << this->_name << "\" is dead!" << std::endl;
	}

	else if (this->_mp == 0) {
		std::cout << "ClapTrap \"" << this->_name << "\" is is out of energy points!" << std::endl;
	} 

}

void ClapTrap::takeDamage(unsigned int n_damage) {

	if (this->_hp > 0) {

		std::cout << "ClapTrap \"" << this->_name << "\" "
			<< "took " << n_damage << " point(s) of damage!" << std::endl;
	
		this->_hp -= n_damage;

	}

	else {
		std::cout << "ClapTrap \"" << this->_name << "\" "
			<< "has already died" << std::endl;
	}

	if (this->_hp < 0) {
		this->_hp = 0;
	}

}

void ClapTrap::beRepaired(unsigned int n_heal) {

	if (this->_hp > 0 && this->_mp > 0) {

		std::cout << "ClapTrap \"" << this->_name << "\" "
			<< "healing itself for " << n_heal << " point(s)!" << std::endl;
	
		this->_hp += n_heal;
		this->_mp--;
	
	} 

	if (this->_hp <= 0) {
		std::cout << "ClapTrap \"" << this->_name << "\" "
			<< "has already died before getting heal" << std::endl;
	}

	else if (this->_mp == 0) {
		std::cout << "ClapTrap \"" << this->_name << "\" is is out of energy points!" << std::endl;
	}

}
