/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:25:21 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/04 01:01:07 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Form
{
	private:
		bool				is_signed;
		const std::string	name;
		const int			minimum_auth_grade;
		const int			minimum_exec_grade;

	public:

		Form(Form const &base);
		Form(const std::string name, const int minimum_auth_grade, const int minimum_exec_grade);
		Form &operator=(Form const &rhs);
		~Form();

		std::string		getName() const;
		int				getGradeAuth() const;
		int				getGradeExec() const;

		void			beSigned(class Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &lhs, const Form &rhs);

#endif
