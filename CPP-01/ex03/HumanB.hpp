/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:33:17 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 15:55:52 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB {

	private:
		std::string _name;
		Weapon *_weapon;

	public:

		HumanB(std::string name);
		~HumanB();

		void attack();

		void setWeapon(Weapon &weapon);

};

#endif
