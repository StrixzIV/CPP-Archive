/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:02:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 12:21:44 by jikaewsi         ###   ########.fr       */
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

		ShrubberyCreationForm shrub("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm pardon("P. Diddy");

		john.signForm(pardon);
		mike.executeForm(pardon);

	}

	catch (std::exception &error) {
		std::cerr << "Error -> " << error.what() << std::endl;
	}

}
