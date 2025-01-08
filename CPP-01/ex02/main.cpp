/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:58:39 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 15:07:10 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {

	std::string str;
	std::string *str_ptr;

	str = "HI THIS IS BRAIN";
	str_ptr = &str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "str_ptr held address value: " << str_ptr << std::endl;

	std::string &str_ref = str;

	std::cout << "str_ref held address value: " << &str_ref << std::endl;

	std::cout << "str value: " << str << std::endl;
	std::cout << "str_ptr pointed value: " << *str_ptr << std::endl;
	std::cout << "str_ref pointed value: " << str_ref << std::endl;

}
