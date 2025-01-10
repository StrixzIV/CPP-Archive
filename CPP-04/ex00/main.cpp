/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:10:58 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:10:58 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
    
    std::cout << "---------- Constructor ----------" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    // Type attribute check
    std::cout << "---------- getType() ----------" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    // makeSound check
    std::cout << "---------- makeSound() ----------" << std::endl;
    cat->makeSound();
    dog->makeSound();

    std::cout << "---------- Animal makeSound() ----------" << std::endl;
	const Animal* generic = new Animal();
    generic->makeSound();

    std::cout << "---------- Deconstructor ----------" << std::endl;
    delete dog;
    delete cat;

    std::cout << "---------- WrongCat----------" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();

    delete wrongCat;

}
