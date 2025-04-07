/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:12:26 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/07 17:30:22 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "A new intern has enter the office!" << std::endl;
}

Intern::Intern(const Intern &base) {
	*this = base;
}

Intern &Intern::operator=(const Intern &rhs) {
	(void) rhs;
	return *this;
}

Intern::~Intern() {
	std::cout << "An intern has quit from this unpaid internship!" << std::endl;
}

static AForm *request_robotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *request_presidential(std::string target) {
	return new PresidentialPardonForm(target);
}

static AForm *request_shrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string type, std::string target) {

	const std::string request_type[] = {
		"robotomy request",
		"shrubbery request",
		"presidental request"
	};

	AForm *(*request_list[])(std::string) = {
		&request_robotomy,
		&request_presidential,
		&request_shrubbery
	};

	if (target.empty()) {
		target = "unnamed";
	}

	size_t idx = 0;

	while (idx < 3) {

		if (request_type[idx] == type) {
			std::cout << "Intern creates " << type << std::endl;
			return (request_list[idx](target));
		}

		idx++;

	}

	std::cerr << "Error: intern cannot create a " << type << std::endl;
	return NULL;

}
