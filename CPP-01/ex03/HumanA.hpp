/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:33:17 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 15:55:52 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA {

	private:
		std::string _name;
		Weapon &_weapon;

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();

		void setWeapon(Weapon weapon);

};

#endif
