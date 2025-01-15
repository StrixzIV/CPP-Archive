/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:46:58 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 19:24:54 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {

    std::cout << "=== Default Constructor Test ===" << std::endl;
    ClapTrap defaultClapTrap;
    std::cout << "Name: " << defaultClapTrap.get_name() << ", HP: " 
              << defaultClapTrap.get_hp() << ", MP: " << defaultClapTrap.get_mp() 
              << ", Damage: " << defaultClapTrap.get_dmg() << std::endl;

    std::cout << "\n=== Overloaded Constructor Test ===" << std::endl;
    ClapTrap namedClapTrap("Clappy");
    std::cout << "Name: " << namedClapTrap.get_name() << ", HP: " 
              << namedClapTrap.get_hp() << ", MP: " << namedClapTrap.get_mp() 
              << ", Damage: " << namedClapTrap.get_dmg() << std::endl;

    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    ClapTrap copyClapTrap(namedClapTrap);
    std::cout << "Name: " << copyClapTrap.get_name() << ", HP: " 
              << copyClapTrap.get_hp() << ", MP: " << copyClapTrap.get_mp() 
              << ", Damage: " << copyClapTrap.get_dmg() << std::endl;

    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    ClapTrap assignedClapTrap;
    assignedClapTrap = namedClapTrap;
    std::cout << "Name: " << assignedClapTrap.get_name() << ", HP: " 
              << assignedClapTrap.get_hp() << ", MP: " << assignedClapTrap.get_mp() 
              << ", Damage: " << assignedClapTrap.get_dmg() << std::endl;

    std::cout << "\n=== Attack Test ===" << std::endl;
    namedClapTrap.set_dmg(5);
    namedClapTrap.attack("Enemy");

    std::cout << "\n=== Take Damage Test ===" << std::endl;
    namedClapTrap.takeDamage(3);
    std::cout << "HP after taking damage: " << namedClapTrap.get_hp() << std::endl;

    std::cout << "\n=== Be Repaired Test ===" << std::endl;
    namedClapTrap.beRepaired(4);
    std::cout << "HP after repair: " << namedClapTrap.get_hp() << std::endl;

    std::cout << "\n=== Edge Cases ===" << std::endl;
    namedClapTrap.takeDamage(20); // Died from taking damage
    namedClapTrap.attack("Enemy"); // Attack while dead
    namedClapTrap.beRepaired(5); // Healing while dead

    std::cout << "\n=== Deconstructor ===" << std::endl;

    return 0;
}
