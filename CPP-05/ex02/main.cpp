/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:02:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 12:12:46 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {

		Bureaucrat john("John", 25);
		Bureaucrat mike("Mike", 5);
		Bureaucrat adam("Adam", 120);

		ShrubberyCreationForm document1("shrub");
		RobotomyRequestForm document2("robot");
		PresidentialPardonForm document3("prez");

		john.signForm(document1);
		mike.executeForm(document1);

	}

	catch (std::exception &error) {
		std::cerr << "Error -> " << error.what() << std::endl;
	}

}
