/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:46:44 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 01:46:44 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria {

    public:

        Cure();
        Cure(const Cure &base);
        const Cure &operator=(const Cure &rhs);
        ~Cure();

        virtual AMateria *clone() const;

        void use(ICharacter &target);

};

#endif
