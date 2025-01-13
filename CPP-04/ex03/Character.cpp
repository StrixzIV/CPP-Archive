/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:16:19 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 01:16:19 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _inventory() {
    this->_name = "Default";
    std::cout << "Character \"" << this->_name << "\" created with default constructor" << std::endl;
}

Character::Character(const std::string &name): _inventory() {
    this->_name = name;
    std::cout << "Character \"" << this->_name << "\" created with string-overloaded constructor" << std::endl;
}

Character::Character(const Character &base): ICharacter(base), _inventory() {

    this->_name = base._name;

    for (size_t idx = 0; idx < 4; idx++) {
        if (base._inventory[idx]) {
            this->_inventory[idx] = base._inventory[idx];
        }
    }

    std::cout << "Character \"" << this->_name << "\" copied" << std::endl;

}

const Character &Character::operator=(const Character &lhs) {
    this->_name = lhs._name;
    return (*this);
}

Character::~Character() {

    for (size_t idx = 0; idx < 4; idx++) {
        if (this->_inventory[idx]) {
            delete this->_inventory[idx];
        }
    }

    std::cout << "Character \"" << this->_name << "\" destroyed" << std::endl;

}

const std::string &Character::getName() const {
    return (this->_name);
}

void Character::setName(const std::string &name) {
    this->_name = name;
}

bool Character::isInInventory(AMateria *materia) {
    
    for (size_t idx = 0; idx < 4; idx++) {
        if (this->_inventory[idx] == materia) {
            return (true);
        }
    }

    return (false);

}

void Character::equip(AMateria *materia) {

    for (size_t idx = 0; idx < 4; idx++) {
        if (materia && this->_inventory[idx] == NULL) {
                
            if (this->isInInventory(materia)) {
                this->_inventory[idx] = materia->clone();
            }

            else {
                this->_inventory[idx] = materia;
            }

            std::cout << "Materia: \"" << this->_inventory[idx]->getType()
                << "\" is added to " << this->_name << "'s inventory "
                << "at index #" << idx << std::endl;

            return;

        }
    }

    if (materia) {
        std::cout << this->_name << " inventory is full" << std::endl;
    }

    else {
        std::cout << "Invalid materia" << std::endl;
    }

    if (!this->isInInventory(materia)) {
        delete materia;
    }

}

void Character::unequip(int idx) {

    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    else if (!this->_inventory[idx]) {
        std::cout << "Index #" << idx << " is empty" << std::endl;
        return;
    }
    
    std::cout << "Materia: \"" << this->_inventory[idx]->getType()
            << "\" is removed from " << this->_name << "'s inventory "
            << "at index #" << idx << std::endl;

    this->_inventory[idx] = NULL;

}

void Character::use(int idx, ICharacter &target) {

    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    else if (!this->_inventory[idx]) {
        std::cout << "Index #" << idx << " is empty" << std::endl;
        return;
    }

    this->_inventory[idx]->use(target);

}
