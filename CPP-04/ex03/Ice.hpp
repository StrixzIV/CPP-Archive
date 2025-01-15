/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:57:10 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 01:57:10 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria {

    public:

        Ice();
        Ice(const Ice &base);
        const Ice &operator=(const Ice &rhs);
        ~Ice();

        virtual AMateria *clone() const;

        void use(ICharacter &target);

};

#endif
