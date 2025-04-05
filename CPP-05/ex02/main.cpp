/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:02:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/05 15:46:48 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {

		Bureaucrat					personnel1("Jhon", 25);
		Bureaucrat					personnel2("Adam", 5);
		Bureaucrat					personnel3("Adam", 120);
		ShrubberyCreationForm		document1("shrub");
		RobotomyRequestForm			document2("robot");
		PresidentialPardonForm		document3("prez");

		personnel1.signForm(document1);
		personnel2.executeForm(document1);

	}

	catch (std::exception &error) {
		std::cerr << "Error -> " << error.what() << std::endl;
	}

}
