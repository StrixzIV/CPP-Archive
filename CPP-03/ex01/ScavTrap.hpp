/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:01:54 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 21:23:36 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &base);
		ScavTrap &operator=(const ScavTrap &rhs);
		~ScavTrap();

		void guardGate();
		void attack(const std::string &target);

};

#endif
