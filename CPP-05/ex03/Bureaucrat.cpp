/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:40:41 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 11:38:53 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "A new bureaucrat has arrived!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name) {

	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}

	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}

	this->grade = grade;

	if (name.empty()) {
		std::cout << "A nameless bureaucrat has arrived!" << std::endl;
	}

	else {
		std::cout << name << " has became a new bureaucrat!" << std::endl;
	}

}

Bureaucrat::Bureaucrat(const Bureaucrat &base) {
	*this = base;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {

	(void) rhs;

	std::cout << "A new bureaucrat has been assigned to a job from " << rhs.name << std::endl;
	return *this;
	
}

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs) {
	return lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
}

Bureaucrat::~Bureaucrat() {

	if (this->name.empty()) {
		std::cout << "A nameless bureaucrat just got kicked out!" << std::endl;
	}

	else {
		std::cout << this->name << " just got kicked out!" << std::endl;
	}

}

int Bureaucrat::getGrade() const {
	return this->grade;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::increment_grade() {

	if (this->grade <= 1) {
		throw GradeTooHighException();
	}

	this->grade--;

	std::cout << this->name << " is getting promoted to grade " << this->grade << std::endl;

}

void Bureaucrat::decrement_grade() {

	if (this->grade <= 150) {
		throw GradeTooLowException();
	}

	this->grade++;

	std::cout << this->name << " is getting demoted to grade " << this->grade << std::endl;

}

void Bureaucrat::promote(int grade) {

	if (grade < 0) {
		grade = abs(grade);
	}
	
	if (this->grade - grade < 1 || grade > 150) {
		throw GradeTooHighException();
	}

	this->grade -= grade;

	std::cout << this->name << " is getting promoted to grade " << this->grade << std::endl;

}

void Bureaucrat::demote(int grade) {

	if (grade < 0) {
		grade = abs(grade);
	}
	
	if (this->grade + grade > 150 || grade > 150) {
		throw GradeTooLowException();
	}

	this->grade += grade;

	std::cout << this->name << " is getting demoted to grade " << this->grade << std::endl;

}

void Bureaucrat::signForm(AForm &form) {

	try {
		form.beSigned(*this);
	}

	catch (std::exception &exception) {
		std::cerr << this->name << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
	}

}

void Bureaucrat::executeForm(const AForm &form) {

	try {
		form.execute(*this);
	}

	catch (std::exception &exception) {
		std::cerr << this->name << " couldn't execute " << form.getName() << " because " << exception.what() << std::endl;
	}

}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException - the input grade is too high (the grade value must be in between 1 to 150)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException - the input grade is too low (the grade value must be in between 1 to 150)";
}
