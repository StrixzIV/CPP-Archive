/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:02:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/04 01:12:20 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	try {

		Bureaucrat	supun("Supun", 69);
		Form		physics_lab_budget_form("Physics Lab project's budget", 42, 43);

		std::cout << physics_lab_budget_form << std::endl;

		supun.promote(27);
		supun.signForm(physics_lab_budget_form);

		std::cout << physics_lab_budget_form << std::endl;

	}

	catch (std::exception &error) {
		std::cerr << "Error -> " << error.what() << std::endl;
	}

}
