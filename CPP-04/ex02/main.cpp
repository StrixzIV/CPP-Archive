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

int main() {

    // This will be illegal by implementation
    // const Animal *animal_test = new Animal();
    
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

    std::cout << "---------- Deconstructor ----------" << std::endl;
    delete dog;
    delete cat;

    std::cout << "---------- Brain initialize ----------" << std::endl;
    
    const size_t size = 10;
    const Animal *animals[size];

    for (size_t idx = 0; idx < size; idx++) {
        
        if (idx < size / 2) {
            animals[idx] = new Dog();
        }
        
        else {
            animals[idx] = new Cat();
        }
    
    }

    std::cout << "---------- Brain test ----------" << std::endl;

    std::cout << animals[0]->getType() << std::endl;
    std::cout << animals[5]->getType() << std::endl;
    
    Brain *brain;
    brain = &animals[0]->getBrain();
    brain->set_idea("I want sarshisitas!", 0);
    brain->set_idea("Let's play ball!!", 1);
    brain->set_idea("Feed me human!", 2);
    
    std::cout << animals[0]->getBrain().get_idea(0) << std::endl;
    std::cout << animals[0]->getBrain().get_idea(1) << std::endl;

    std::cout << "---------- Brain deconstruct ----------" << std::endl;

    for (size_t idx = 0; idx < size; idx++) {
        delete animals[idx];
    }

    std::cout << "---------- Deep copy constructor test (Dog) ----------" << std::endl;

    {

		Dog *dog1 = new Dog;
		Dog *dog2 = new Dog(*dog1);

		delete dog1;
		delete dog2;

	}

    std::cout << "---------- Assignment overload test (Dog) ----------" << std::endl;
    
    {

		Dog *dog1 = new Dog;
		Dog *dog2 = new Dog;

		*dog1 = *dog2;

		delete dog1;
		delete dog2;

	}

    std::cout << "---------- Deep copy constructor test (Cat) ----------" << std::endl;

    {

		Cat *cat1 = new Cat;
		Cat *cat2 = new Cat(*cat1);

		delete cat1;
		delete cat2;

	}

    std::cout << "---------- Assignment overload test (Cat) ----------" << std::endl;
    
    {

		Cat *cat1 = new Cat;
		Cat *cat2 = new Cat;

		*cat1 = *cat2;

		delete cat1;
		delete cat2;

	}

}
