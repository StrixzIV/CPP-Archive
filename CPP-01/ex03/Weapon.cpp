/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:14 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 15:57:08 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) {
	this->_weapon_type = weapon_type;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType() {
	return (this->_weapon_type);
}

void Weapon::setType(std::string weapon_type) {
	this->_weapon_type = weapon_type;
}
