/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:47 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 16:00:38 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon) {

	this->_name = name;

	std::cout << "Human A -> \"" << name
		<< "\" currently welding: " << weapon.getType() << std::endl;

}

HumanA::~HumanA() {}

void HumanA::attack() {	
	std::cout << this->_name
		<< " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}
