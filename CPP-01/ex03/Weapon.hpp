/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:33:47 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 15:56:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

	private:
		std::string _weapon_type;

	public:

		Weapon(std::string weapon_type);
		~Weapon();

		const std::string &getType();
		void setType(std::string waeapon_type);

};

#endif
