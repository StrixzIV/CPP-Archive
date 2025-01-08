/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:11:08 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 18:09:17 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->_value = 0;
}

Fixed::Fixed(const Fixed &base) {
	*this = base;
}

Fixed::Fixed(const int value) {
	this->_value = value << this->_fractional_bits;
}

Fixed::Fixed(const float value) {
	this->_value = (int) roundf(value * (1 << this->_fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed() {}

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

Fixed &Fixed::min(Fixed &x, Fixed &y) {

	if (x < y) {
		return x;
	}

	return y;

}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y) {

	if (x < y) {
		return x;
	}

	return y;

}

Fixed &Fixed::max(Fixed &x, Fixed &y) {

	if (x > y) {
		return x;
	}

	return y;

}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y) {

	if (x > y) {
		return x;
	}

	return y;

}

Fixed Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator>(const Fixed &rhs) const {
	return (this->_value > rhs.getRawBits());
}
bool Fixed::operator<(const Fixed &rhs) const {
	return (this->_value < rhs.getRawBits());
}
bool Fixed::operator>=(const Fixed &rhs) const {
	return (this->_value >= rhs.getRawBits());
}
bool Fixed::operator<=(const Fixed &rhs) const {
	return (this->_value <= rhs.getRawBits());
}
bool Fixed::operator==(const Fixed &rhs) const {
	return (this->_value == rhs.getRawBits());
}
bool Fixed::operator!=(const Fixed &rhs) const {
	return (this->_value != rhs.getRawBits());
}

Fixed &Fixed::operator++() {
	this->_value++;
	return (*this);
}

Fixed &Fixed::operator--() {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int rhs) {

	(void) rhs;

	Fixed tmp = *this;
	this->_value++;

	return (tmp);

}

Fixed Fixed::operator--(int rhs) {

	(void) rhs;

	Fixed tmp = *this;
	this->_value--;

	return (tmp);

}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs) {
	lhs << rhs.toFloat();
	return (lhs);
}
