/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:46:34 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 20:54:33 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point &base): _x(base._x), _y(base._y) {}

Point &Point::operator=(const Point &lhs) {
	(void) lhs;
	return (*this);
}

Point::~Point() {}

Fixed Point::get_x() const {
	return this->_x;
}

Fixed Point::get_y() const {
	return this->_y;
}
