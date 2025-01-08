/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:32:14 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/04 13:00:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "PhoneBook.hpp"

int main() {

	std::string input;
	PhoneBook phonebook;

	while (true) {

		std::cout << "\033[2J\033[H";
		std::cout << "Phonebook Menu\n" << std::endl;
		std::cout << "ADD\t\tcreate a new contact" << std::endl;
		std::cout << "SEARCH\t\tsearch contact from index" << std::endl;
		std::cout << "EXIT\t\texit this program" << std::endl;
		std::cout << "\nAction: ";

		std::getline(std::cin, input);

		if (std::cin.eof()) {
			break;
		}

		if (input.empty()) {
			continue;
		}

		if (input == "ADD") {
			std::cout << "\033[2J\033[H";
			phonebook.add_contact();
		}

		else if (input == "SEARCH") {
			std::cout << "\033[2J\033[H";
			phonebook.show_contact();
			phonebook.search_contact();
		}

		else if (input == "EXIT") {
			break;
		}

		else {
			std::cout << "Error: \"" << input << "\": command not found" << std::endl;
			std::cout << "Press <ENTER> to continue" << std::endl;
			std::cin.get();
		}

	}

}