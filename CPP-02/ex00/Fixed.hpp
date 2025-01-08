/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:04:22 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 17:21:16 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed {

	private:
		int _value;
		static const int _fractional_bits = 8;

	public:

		Fixed();
		Fixed(const Fixed &base);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();

		int getRawBits() const;
		void setRawBits(const int raw);

};

#endif
