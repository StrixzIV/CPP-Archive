/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:07:51 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 17:27:45 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

typedef enum e_complain_level {
	DEBUG,
	INFO,
	WARNING,
	ERROR
} t_complain_level;

class Harl {

	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		
		Harl();
		~Harl();

		void complain(std::string level);

};

#endif
