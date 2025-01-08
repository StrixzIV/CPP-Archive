/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:11:08 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 17:47:02 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &base) {
	std::cout << "Copy constructor called" << std::endl;
	*this = base;
}

Fixed::Fixed(const int value) {
	this->_value = value << this->_fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
	this->_value = (int) roundf(value * (1 << this->_fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return (this->_value);
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

int Fixed::toInt() const {
	return (this->_value >> this->_fractional_bits);
}

float Fixed::toFloat() const {
	return (((float)(this->_value)) / (1 << this->_fractional_bits));
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs) {
	lhs << rhs.toFloat();
	return (lhs);
}
