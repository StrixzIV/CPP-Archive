/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:05:45 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 02:05:45 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _learning_slots() {
    std::cout << "MateriaSource created with default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &base): IMateriaSource(base), _learning_slots() {

    for (size_t idx = 0; idx < 4; idx++) {
        if (base._learning_slots[idx]) {
            this->_learning_slots[idx] = base._learning_slots[idx];
        }
    }

    std::cout << "MateriaSource copied" << std::endl;

}

const MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
    (void) rhs;
    return (*this);
}

MateriaSource::~MateriaSource() {

    for (size_t idx = 0; idx < 4; idx++) {
        if (this->_learning_slots[idx]) {
            delete this->_learning_slots[idx];
        }
    }

    std::cout << "MateriaSource destroyed" << std::endl;

}

bool MateriaSource::isInLearningSlot(AMateria *materia) {

    for (size_t idx = 0; idx < 4; idx++) {
        if (this->_learning_slots[idx] == materia) {
            return (true);
        }
    }

    return (false);

}

void MateriaSource::learnMateria(AMateria *materia) {

    for (size_t idx = 0; idx < 4; idx++) {
        if (materia && this->_learning_slots[idx] == NULL) {
                
            if (this->isInLearningSlot(materia)) {
                this->_learning_slots[idx] = materia->clone();
            }

            else {
                this->_learning_slots[idx] = materia;
            }

            std::cout << "Materia: \"" << this->_learning_slots[idx]->getType()
                << "\" is added to learning slot at index #" << idx << std::endl;

            return;

        }
    }

    if (materia) {
        std::cout << "Learning slot is full" << std::endl;
    }

    else {
        std::cout << "Invalid materia" << std::endl;
    }

    if (!this->isInLearningSlot(materia)) {
        delete materia;
    }

}

AMateria *MateriaSource::createMateria(const std::string &type) {

    for (size_t idx = 0; idx < 4; idx++) {
        if (this->_learning_slots[idx] && this->_learning_slots[idx]->getType() == type) {
            return (this->_learning_slots[idx]->clone());
        }
    }

    std::cout << "Cannot create materia of type \"" << type << "\"" << std::endl;
    return (NULL);

}
