/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:55:30 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 11:44:25 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double to_raw_double(const std::string &string_value) {

	if (string_value == "inf"
		|| string_value == "+inf"
		|| string_value == "inff"
		|| string_value == "+inff") {
		return (std::numeric_limits<double>::infinity());
	}

	if (string_value == "-inf" || string_value == "-inff") {
		return (-std::numeric_limits<double>::infinity());
	}
	
	if (string_value == "nan" || string_value == "nanf") {
		return (std::numeric_limits<double>::quiet_NaN());
	}

	std::string copy = string_value;

	if (string_value[string_value.length() - 1] == 'f') {
		copy.erase(string_value.length() - 1);
	}

	double value;
	std::istringstream string_stream(copy);

	string_stream >> value;

	if (string_stream.fail()) {
		std::cerr << "Failed to convert to double" << std::endl;
		exit(1);
	}

	return (value);

}

void display_char(double value) {

	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
		return;
	}

	char character = static_cast<char>(value);

	if (std::isprint(character)) {
		std::cout << "char: '" << character << "'" << std::endl;
		return;
	}

	std::cout << "char: Non displayable" << std::endl;

}

void display_int(double value) {

	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
		return;
	}

	std::cout << "int: " << static_cast<int>(value) << std::endl;

}

void display_float(double value) {

	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "float: " << value << "f" << std::endl;
		return;
	}

	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(value) << "f" << std::endl;

}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &base) {
	*this = base;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	(void) rhs;
	return (*this);
}

void ScalarConverter::convert(std::string string_value) {

	string_value.erase(0, string_value.find_first_not_of(" \n\r\t"));
	string_value.erase(string_value.find_last_not_of(" \n\r\t") + 1);

	double value = to_raw_double(string_value);

	display_char(value);
	display_int(value);
	display_float(value);

	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< value << std::endl;

}
