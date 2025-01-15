/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:42:42 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 16:33:21 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

int main() {

	std::cout << "---------- Subject's test ----------" << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
	
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		AMateria* tmp;
		ICharacter* me = new Character("me");
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << "---------- Learn Materia test ----------" << std::endl;

		IMateriaSource* src = new MateriaSource();
	
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	
		AMateria *mat = new Cure();
		src->learnMateria(mat);
	
		std::cout << std::endl;

		std::cout << "---------- Character deep copy test ----------" << std::endl;

		Character *character0 = new Character("Alice");
		ICharacter *character1 = new Character(*character0);
		
		delete character0;
		delete character1;
		
		std::cout << std::endl;
	
		std::cout << "---------- Materia create test ----------" << std::endl;

		AMateria* tmp;
		ICharacter *character2 = new Character("Alice");
		
		tmp = src->createMateria("ice");
		character2->equip(tmp);
		
		tmp = src->createMateria("cure");
		character2->equip(tmp);
		
		tmp = src->createMateria("pain");
		character2->equip(tmp);
		
		delete src;
		
		std::cout << std::endl;

		std::cout << "---------- Equip test ----------" << std::endl;

		AMateria *cure = new Cure();
		AMateria *ice = new Ice();

		character2->equip(cure);
		character2->equip(cure);
		character2->equip(ice);
		character2->unequip(2);
		delete cure;

		character2->unequip(2);
		character2->unequip(6);
		
		std::cout << std::endl;

		std::cout << "---------- Materia use test ----------" << std::endl;

		ICharacter* bob = new Character("Bob");

		character2->use(0, *bob);
		character2->use(1, *bob);
		character2->use(2, *bob);
		character2->use(6, *bob);
		character2->use(-4, *bob);
		character2->use(3, *bob);
		
		delete bob;
		delete character2;

	}

}
