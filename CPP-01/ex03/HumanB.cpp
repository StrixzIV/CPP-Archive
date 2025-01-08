/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:47 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 16:00:27 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {

	this->_name = name;
	this->_weapon = NULL;

	std::cout << "Human B -> \"" << name
		<< "\" currently welding: nothing" << std::endl;

}

HumanB::~HumanB() {}

void HumanB::attack() {	
	std::cout << this->_name
		<< " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
