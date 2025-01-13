/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:48:02 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 00:05:11 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter {

	protected:

		ICharacter();
		ICharacter(const ICharacter &base);
		const ICharacter &operator=(const ICharacter &lhs);

	public:

		virtual ~ICharacter() {}

		virtual const std::string &getName() const = 0;

		virtual void equip(AMateria *materia) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;

};

#endif
