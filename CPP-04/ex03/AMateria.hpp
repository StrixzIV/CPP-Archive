/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:48:02 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/15 14:24:28 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria {

	protected:

		std::string _type;
		AMateria(const AMateria &base);

	public:

		AMateria(const std::string &type);
		virtual ~AMateria();
		const AMateria &operator=(const AMateria &rhs);

		const std::string &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;

};

#endif
