/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:02:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/03 23:17:48 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	try {

		// Constructor test
		Bureaucrat poomk("Poom K.", 1);
		Bureaucrat supun("Supun", 150);

		// Promote-Demote
		std::cout << poomk << std::endl;
		std::cout << supun << std::endl;

		supun.promote(5);
		poomk.demote(5);

		std::cout << poomk << std::endl;
		std::cout << supun << std::endl;

		// Exceptions - Invalid constructor
		// Bureaucrat poomk2("Poom K. #2", 0);
		// Bureaucrat poomk3("Poom K. #3", -1);
		// Bureaucrat supun2("Supun #2", 69420);

		// Exceptions - Invalid promote-demote
		// Bureaucrat poomk4("Poom K. #4", 1);
		// Bureaucrat supun3("Supun #3", 150);

		// poomk4.promote(1);
		// supun3.demote(1);

	}

	catch (std::exception &error) {
		std::cerr << "Error -> " << error.what() << std::endl;
	}

}
