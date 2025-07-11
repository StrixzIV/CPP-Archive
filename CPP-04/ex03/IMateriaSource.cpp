/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:13:25 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/15 14:27:32 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
	std::cout << "IMateriaSource created with default constructor" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &base) {
	*this = base;
	std::cout << "IMateriaSource copied" << std::endl;
}

const IMateriaSource &IMateriaSource::operator=(const IMateriaSource &rhs) {

	(void) rhs;
	std::cout << "IMateriaSource copy assignment called" << std::endl;

	return (*this);

}
