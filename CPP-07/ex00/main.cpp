/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:57:23 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 00:24:42 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {

	int value_a = 42;
	int value_b = 1337;

	std::cout << "##### int swap #####" << std::endl;

	std::cout << "----- Before swap ----" << std::endl;
	std::cout << "Value A: " << value_a << std::endl;
	std::cout << "Value B: " << value_b << std::endl;

	::swap(value_a, value_b);
	
	std::cout << "----- After swap ----" << std::endl;
	std::cout << "Value A: " << value_a << std::endl;
	std::cout << "Value B: " << value_b << std::endl;
	
	std::string str_a = "This is string A";
	std::string str_b = "This is string B";

	std::cout << "##### str swap #####" << std::endl;

	std::cout << "----- Before swap ----" << std::endl;
	std::cout << "Value A: " << str_a << std::endl;
	std::cout << "Value B: " << str_b << std::endl;

	::swap(str_a, str_b);
	
	std::cout << "----- After swap ----" << std::endl;
	std::cout << "Value A: " << str_a << std::endl;
	std::cout << "Value B: " << str_b << std::endl;

	std::cout << "##### min-max int #####" << std::endl;
	std::cout << "Min: " << ::min(value_a, value_b) << std::endl;
	std::cout << "Max: " << ::max(value_a, value_b) << std::endl;
	
	std::cout << "##### min-max str #####" << std::endl;
	std::cout << "Min: " << ::min(str_a, str_b) << std::endl;
	std::cout << "Max: " << ::max(str_a, str_b) << std::endl;

}
