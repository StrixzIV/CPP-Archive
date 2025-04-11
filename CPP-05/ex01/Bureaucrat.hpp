/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:41:54 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 11:32:15 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <cmath>
# include <string>
# include <iostream>

# include "Form.hpp"

class Bureaucrat {

	private:
		int grade;
		const std::string name;

	public:

		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &base);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		int getGrade() const;
		std::string getName() const;

		void increment_grade();
		void decrement_grade();
		void promote(int grade);
		void demote(int grade);
		void signForm(class Form &form);

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

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);

#endif
