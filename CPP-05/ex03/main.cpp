/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:02:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 12:10:43 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {

	AForm *form = NULL;
	
	try {
		
		Intern		intern;
		Bureaucrat	supun("Supun", 12);
		
		form = intern.makeForm("robotomy request", "Alice");
		delete form;

		form = intern.makeForm("shrubbery request", "Charlie");
		delete form;
		
		form = intern.makeForm("presidental request", "David");
		delete form;
		
		// Error - Unmatched
		// form = intern.makeForm("random request", "Elisa");
		// delete form;

		form = intern.makeForm("robotomy request", "Poom K.");

		if (form) {
			form->beSigned(supun);
			supun.executeForm(*form);
			delete form;
		}

	}
	
	catch (std::exception & e) {
		delete form;
		std::cout << "Caught Error: " << e.what() << std::endl;
	}

}

