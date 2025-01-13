/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:48:02 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/13 23:52:15 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria {

	protected:

		std::string _type;

		AMateria(const std::string &type);
		AMateria(const AMateria &base);

	public:

		virtual ~AMateria();
		const AMateria &operator=(const AMateria &lhs);

		const std::string &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;

};

#endif
