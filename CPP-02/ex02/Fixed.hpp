/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:04:22 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 17:54:28 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <string>
# include <iostream>

class Fixed {

	private:
		int _value;
		static const int _fractional_bits = 8;

	public:

		Fixed();
		Fixed(const Fixed &base);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();

		int getRawBits() const;
		void setRawBits(const int raw);

		int toInt() const;
		float toFloat() const;

		static Fixed &min(Fixed &x, Fixed &y);
		static const Fixed &min(const Fixed &x, const Fixed &y);

		static Fixed &max(Fixed &x, Fixed &y);
		static const Fixed &max(const Fixed &x, const Fixed &y);

		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int rhs);
		Fixed operator--(int rhs);

		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);

#endif
