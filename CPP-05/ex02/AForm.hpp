/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:21:02 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/05 15:21:03 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class AForm
{
	private:
		bool				is_signed;
		const std::string	name;
		const int			minimum_auth_grade;
		const int			minimum_exec_grade;

	public:

		AForm(AForm const &base);
		AForm(const std::string name, const int minimum_auth_grade, const int minimum_exec_grade);
		AForm &operator=(const AForm &rhs);
		virtual ~AForm();

		int getGradeAuth() const;
		int getGradeExec() const;
		std::string getName() const;

		virtual void beSigned(class Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &bureaucrat) const = 0;

		// Exceptions
		class GradeTooLowException: public std::exception {

			public:
				virtual const char *what() const throw();

		};

		class GradeTooHighException: public std::exception {

			public:
				virtual const char *what() const throw();

		};

};

std::ostream &operator<<(std::ostream &lhs, const AForm &rhs);

#endif
