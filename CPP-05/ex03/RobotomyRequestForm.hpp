/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:20:13 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/05 15:39:55 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		bool				is_signed;
		const std::string	target;
		const int			minimum_auth_grade;
		const int			minimum_exec_grade;

	public:

		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm const &base);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		virtual ~RobotomyRequestForm();

		virtual void beSigned(class Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &bureaucrat) const;

};

std::ostream &operator<<(std::ostream &lhs, const RobotomyRequestForm &rhs);

#endif
