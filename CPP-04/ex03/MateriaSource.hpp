/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:00:17 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 02:00:17 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {

    private:
        AMateria *_learning_slots[4];

    public:

        MateriaSource();
        MateriaSource(const MateriaSource &base);
        const MateriaSource &operator=(const MateriaSource &rhs);
        ~MateriaSource();

        bool isInLearningSlot(AMateria *materia);

        virtual void learnMateria(AMateria *materia);
        virtual AMateria *createMateria(const std::string &type);

};

#endif
