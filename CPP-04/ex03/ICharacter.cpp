/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:09:12 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/15 14:27:32 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter created with default constructor" << std::endl;
}

ICharacter::ICharacter(const ICharacter &base) {
	*this = base;
	std::cout << "ICharacter copied" << std::endl;
}

const ICharacter &ICharacter::operator=(const ICharacter &rhs) {

	(void) rhs;
	std::cout << "ICharacter copy assignment called" << std::endl;

	return (*this);

}
