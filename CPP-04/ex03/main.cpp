/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:42:42 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/14 02:20:07 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

int main() {

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
	
	return 0;

}
