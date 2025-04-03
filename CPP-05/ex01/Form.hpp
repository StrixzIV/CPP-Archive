/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:25:21 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/03 23:25:23 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_auth;
		const int			grade_exec;

	public:
		~Form();
		Form(Form const &copy);
		Form &operator=(Form const &assignment);
		Form(const std::string name, const int grade_auth, const int grade_exec);

		std::string		getName() const;
		int				getGradeAuth() const;
		int				getGradeExec() const;
		void			beSigned(class Bureaucrat &personnel);

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

};

std::ostream &operator<<(std::ostream &stream, const Form &insert);

#endif
