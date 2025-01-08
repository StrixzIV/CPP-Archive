/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:59:27 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/04 12:13:56 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void read_input(std::string prompt, std::string &ref) {

	do {

		std::cout << prompt;
		std::getline(std::cin, ref);
	
		if (std::cin.eof())
			exit(0);
	
	} while (ref.empty());

}

PhoneBook::PhoneBook(): _contact_size(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact() {
	
	std::string name;
	std::string lastname;
	std::string nickname;
	std::string phone_number;
	std::string secret;

	ContactInfo contact_info;

	read_input("Enter your first name: ", name);
	read_input("Enter your last name: ", lastname);
	read_input("Enter your nickname: ", nickname);
	read_input("Enter your phone number: ", phone_number);
	read_input("Enter your deep dark secret: ", secret);

	contact_info.set_name(name);
	contact_info.set_lastname(lastname);
	contact_info.set_nickname(nickname);
	contact_info.set_phone_number(phone_number);
	contact_info.set_secret(secret);

	this->_contact_list[this->_contact_size % 8] = contact_info;
	this->_contact_size++;

}

void PhoneBook::show_contact() const {

	std::string name;
	std::string lastname;
	std::string nickname;
	ContactInfo contact_info;

	size_t max_size = this->_contact_size < 8 ? this->_contact_size : 8;

	std::cout << std::setw(5) << "Index" << " | ";
	std::cout << std::setw(10) << "Firstname" << " | ";
	std::cout << std::setw(10) << "Lastname" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (size_t idx = 0; idx < max_size; idx++) {

		std::cout << std::setw(5) << idx << " | ";
		
		contact_info = this->_contact_list[idx];

		name = contact_info.get_name();
		lastname = contact_info.get_lastname();
		nickname = contact_info.get_nickname();
		
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		
		if (lastname.length() > 9)
			lastname = lastname.substr(0, 9) + ".";
		
		if (nickname.length() > 9)
			nickname = nickname.substr(0, 9) + ".";
		
		std::cout << std::setw(10) << name << " | ";
		std::cout << std::setw(10) << lastname << " | ";
		std::cout << std::setw(10) << nickname << std::endl;
	
	}

}

void PhoneBook::search_contact() const {

	size_t idx;
	std::string input;

	if (this->_contact_size == 0) {
		std::cout << "Error: no contact stored in this phonebook." << std::endl;
		std::cout << "Press <ENTER> to continue" << std::endl;
		std::cin.get();
		return;
	}

	while (true) {

		read_input("Enter target index: ", input);

		if (std::cin.eof())
			break;

		if (input.empty())
			continue;

		std::istringstream string_stream(input);

		if (!(string_stream >> idx) || !string_stream.eof() || idx < 0 || idx >= _contact_size || idx >= 8)
		{
			std::cout << "Error: index not found." << std::endl;
			continue;
		}

		else {

			std::cout << "Firstname: " << this->_contact_list[idx].get_name() << std::endl;
			std::cout << "Lastname: " << this->_contact_list[idx].get_lastname() << std::endl;
			std::cout << "Nickname: " << this->_contact_list[idx].get_nickname() << std::endl;
			std::cout << "Phone number: " << this->_contact_list[idx].get_phone_number() << std::endl;
			std::cout << "Darkest secret: " << this->_contact_list[idx].get_secret() << std::endl;

			std::cout << "Press <ENTER> to continue" << std::endl;
			std::cin.get();
		
			break;
		
		}
		
	}

}
