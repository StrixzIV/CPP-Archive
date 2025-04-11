/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 00:14:05 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 12:40:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(Form const &base): 
	name(base.name), minimum_auth_grade(base.minimum_auth_grade), minimum_exec_grade(base.minimum_exec_grade)
{
	*this = base;
}

Form::Form(const std::string name, const int minimum_auth_grade, const int minimum_exec_grade): 
	name(name), minimum_auth_grade(minimum_auth_grade), minimum_exec_grade(minimum_exec_grade)
{
	
	if (minimum_auth_grade > 150 || minimum_exec_grade > 150) {
		throw Form::GradeTooLowException();
	}

	else if (minimum_auth_grade < 1 || minimum_exec_grade < 1) {
		throw Form::GradeTooHighException();
	}

	this->is_signed = false;
	std::cout << "A " << this->name << " form has been created." << std::endl;

}

Form	&Form::operator=(Form const &rhs) {
	(void) rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &rhs, const Form &lhs) {

	return rhs << "A " << lhs.getName() 
		<< " form has a minimum authorization grade of " << lhs.getGradeAuth()
		<< " and a minimum execution grade of " << lhs.getGradeExec();
		
}

Form::~Form() {
	std::cout << "A " << this->name << " form has been invalidated." << std::endl;
}

std::string	Form::getName() const {
	return this->name;
}

int	Form::getGradeAuth() const {
	return this->minimum_auth_grade;
}

int	Form::getGradeExec() const {
	return this->minimum_exec_grade;
}

void	Form::beSigned(Bureaucrat &bureaucrat) {

	if (this->is_signed) {
		std::cout << "A " << this->name << " form has already been signed";
		return ;
	}

	if (bureaucrat.getGrade() > this->minimum_auth_grade) {
		throw Form::GradeTooLowException();
	}

	this->is_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->name << std::endl;

}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException - the input grade is too high (the grade value must be in between 1 to 150)";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException - the input grade is too low (the grade value must be in between 1 to 150)";
}
