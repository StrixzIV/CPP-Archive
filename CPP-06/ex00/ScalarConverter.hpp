/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:46:08 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 11:43:59 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <cmath>
# include <string>
# include <limits>
# include <cctype>
# include <sstream>
# include <iomanip>
# include <iostream>

class ScalarConverter {

	private:
		ScalarConverter();

	public:

		ScalarConverter(const ScalarConverter &base);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();

		static void convert(std::string string_value);

};

#endif
