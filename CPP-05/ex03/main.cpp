/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:02:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/07 17:32:13 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	AForm *form = NULL;
	
	try
	{
		Intern		intern;
		Bureaucrat	bill("Billy the third", 12);
		Bureaucrat	brainrot("Send help", 1);

		form = intern.makeForm("presidental request", "rizz");
		if (form)
		{
			form->beSigned(bill);
			brainrot.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception & e)
	{
		delete form;
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}

