/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:10:09 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 17:52:46 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int map_complain_level(std::string level) {

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int idx = 0; idx < 4; idx++) {
		if (levels[idx] == level) {
			return idx;
		}
	}

	return -1;

}

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level) {

	int complain_level = map_complain_level(level);

	while (complain_level < 4) {

		switch (complain_level) {

			case DEBUG:
				Harl::debug();
				break;

			case INFO:
				Harl::info();
				break;

			case WARNING:
				Harl::warning();
				break;

			case ERROR:
				Harl::error();
				break;

			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				return;
				
		}

		complain_level++;
		
	}

}
