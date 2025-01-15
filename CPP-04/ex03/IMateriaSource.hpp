/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:44:32 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/15 14:24:28 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {

	protected:

		IMateriaSource();
		IMateriaSource(const IMateriaSource &base);
		const IMateriaSource &operator=(const IMateriaSource &rhs);

	public:

		virtual ~IMateriaSource() {}

		virtual void learnMateria(AMateria *materia) = 0;
		virtual AMateria *createMateria(const std::string &type) = 0;

};

#endif
