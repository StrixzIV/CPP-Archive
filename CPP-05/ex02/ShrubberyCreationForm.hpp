/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:22:08 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/05 15:40:00 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		bool				is_signed;
		const std::string	target;
		const int			minimum_auth_grade;
		const int			minimum_exec_grade;

	public:

		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &base);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		virtual ~ShrubberyCreationForm();

		virtual void beSigned(class Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &bureaucrat) const;

};

std::ostream &operator<<(std::ostream &lhs, const ShrubberyCreationForm &rhs);

#endif
