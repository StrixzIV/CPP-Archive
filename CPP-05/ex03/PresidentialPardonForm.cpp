/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:20:38 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 12:43:37 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): 
	AForm(target, 25, 5), target(target), minimum_auth_grade(25), minimum_exec_grade(5)
{
	this->is_signed = false;
	std::cout << "A PresidentialPardonForm for " << this->target << " has been issued." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &base): 
	AForm(base), target(base.target), minimum_auth_grade(25), minimum_exec_grade(5)
{
	*this = base;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	(void) rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &rhs, const PresidentialPardonForm &lhs) {

	return rhs << "A " << lhs.getName() 
		<< "'s PresidentialPardonForm has a minimum authorization grade of " << lhs.getGradeAuth()
		<< " and a minimum execution grade of " << lhs.getGradeExec();;
		
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "A " << this->target << " PresidentialPardonForm has been invalidated." << std::endl;
}

void	PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat) {

	if (this->is_signed) {
		std::cout << "A " << this->target << " PresidentialPardonForm has already been signed";
		return ;
	}

	if (bureaucrat.getGrade() > this->minimum_auth_grade) {
		throw PresidentialPardonForm::GradeTooLowException();
	}

	this->is_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->target << std::endl;

}

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {

	if (!this->is_signed) {
		throw std::runtime_error("PresidentialPardonForm for " + this->target + " has not been signed before execute");
	}

	if (bureaucrat.getGrade() > this->minimum_exec_grade) {
		throw PresidentialPardonForm::GradeTooLowException();
	}

	std::cout << this->target << " has been pardoned by Mr. President" << std::endl;

}
