/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:57:01 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 14:04:37 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	this->_name = "unnamed";
}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << "<" << this->_name << "> " << "Gharrrgl..." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->_name = name;
}

void Zombie::announce() {
	std::cout << "<" << this->_name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
