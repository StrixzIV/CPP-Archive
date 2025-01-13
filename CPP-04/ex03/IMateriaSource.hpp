/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:44:32 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 00:13:57 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {

	protected:

		IMateriaSource();
		IMateriaSource(const IMateriaSource &base);
		const IMateriaSource &operator=(const IMateriaSource &lhs);

	public:

		virtual ~IMateriaSource() {}

		virtual void learnMateria(AMateria *materia) = 0;
		virtual AMateria *createMateria(const std::string &type) = 0;

};

#endif
