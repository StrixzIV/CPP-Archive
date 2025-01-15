/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:17:53 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/15 14:24:28 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter {

	private:

		std::string _name;
		AMateria	*_inventory[4];

	public:

		Character();
		Character(const std::string &name);
		Character(const Character &base);
		const Character &operator=(const Character &rhs);
		~Character();

		const std::string &getName() const;
		void setName(const std::string &name);

		bool isInInventory(AMateria *materia);

		virtual void equip(AMateria *materia);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

};

#endif
