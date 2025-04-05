/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:20:54 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/05 15:20:56 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(AForm const &base): 
	name(base.name), minimum_auth_grade(base.minimum_auth_grade), minimum_exec_grade(base.minimum_exec_grade)
{
	*this = base;
}

AForm::AForm(const std::string name, const int minimum_auth_grade, const int minimum_exec_grade): 
	name(name), minimum_auth_grade(minimum_auth_grade), minimum_exec_grade(minimum_exec_grade)
{
	
	if (minimum_auth_grade > 150 || minimum_exec_grade > 150) {
		throw AForm::GradeTooLowException();
	}

	else if (minimum_auth_grade < 1 || minimum_exec_grade < 1) {
		throw AForm::GradeTooHighException();
	}

	this->is_signed = false;
	std::cout << "A " << this->name << " AForm has been created." << std::endl;

}

AForm	&AForm::operator=(AForm const &rhs) {
	(void) rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &rhs, const AForm &lhs) {

	return rhs << "A " << lhs.getName() 
		<< " AForm has a minimum authorization grade of " << lhs.getGradeAuth()
		<< " and a minimum execution grade of " << lhs.getGradeExec() 
		<< std::endl;
		
}

AForm::~AForm() {
	std::cout << "A " << this->name << " AForm has been invalidated." << std::endl;
}

std::string	AForm::getName() const {
	return this->name;
}

int	AForm::getGradeAuth() const {
	return this->minimum_auth_grade;
}

int	AForm::getGradeExec() const {
	return this->minimum_exec_grade;
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {

	if (this->is_signed) {
		std::cout << "A " << this->name << " AForm has already been signed";
		return ;
	}

	if (bureaucrat.getGrade() > this->minimum_auth_grade) {
		throw AForm::GradeTooLowException();
	}

	this->is_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->name << std::endl;

}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException - the input grade is too high (the grade value must be in between 1 to 150)";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException - the input grade is too low (the grade value must be in between 1 to 150)";
}
