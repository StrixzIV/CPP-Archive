/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:01:54 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 21:46:00 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{

	public:

		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &base);
		FragTrap &operator=(const FragTrap &rhs);
		~FragTrap();

		void highFivesGuys();

};

#endif
