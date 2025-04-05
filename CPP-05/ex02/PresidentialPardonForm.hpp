/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:22:08 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/05 15:39:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		bool				is_signed;
		const std::string	target;
		const int			minimum_auth_grade;
		const int			minimum_exec_grade;

	public:

		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm const &base);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		virtual ~PresidentialPardonForm();

		virtual void beSigned(class Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &bureaucrat) const;

};

std::ostream &operator<<(std::ostream &lhs, const PresidentialPardonForm &rhs);

#endif
