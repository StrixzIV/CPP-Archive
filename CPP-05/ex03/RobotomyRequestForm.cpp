/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:20:26 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/11 12:43:37 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): 
	AForm(target, 72, 45), target(target), minimum_auth_grade(72), minimum_exec_grade(45)
{
	this->is_signed = false;
	std::cout << "A RobotomyRequestForm for " << this->target << " has been issued." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &base): 
	AForm(base), target(base.target), minimum_auth_grade(72), minimum_exec_grade(45)
{
	*this = base;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	(void) rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &rhs, const RobotomyRequestForm &lhs) {

	return rhs << "A " << lhs.getName() 
		<< "'s RobotomyRequestForm has a minimum authorization grade of " << lhs.getGradeAuth()
		<< " and a minimum execution grade of " << lhs.getGradeExec();;
		
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "A " << this->target << " RobotomyRequestForm has been invalidated." << std::endl;
}

void	RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat) {

	if (this->is_signed) {
		std::cout << "A " << this->target << " RobotomyRequestForm has already been signed";
		return ;
	}

	if (bureaucrat.getGrade() > this->minimum_auth_grade) {
		throw RobotomyRequestForm::GradeTooLowException();
	}

	this->is_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->target << std::endl;

}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {

	if (!this->is_signed) {
		throw std::runtime_error("RobotomyRequestForm for " + this->target + " has not been signed before execute");
	}

	if (bureaucrat.getGrade() > this->minimum_exec_grade) {
		throw RobotomyRequestForm::GradeTooLowException();
	}

	std::cout << "Robotomizing " << this->target << "... Bzzzzzz!!!!!" << std::endl;
	
	if (rand() % 10 < 5) {
		std::cout << this->target << " has pass away while taking robotomization operation" << std::endl;
	}

	else {
		std::cout << this->target << " is leaving behind their humanity and turning into a robot!" << std::endl;
	}

}
