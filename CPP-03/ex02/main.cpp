/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:46:58 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 21:50:55 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    
    std::cout << "=== Default Constructor Test ===" << std::endl;
    
    FragTrap frag1;
    std::cout << std::endl;

    std::cout << "=== String Constructor Test ===" << std::endl;
    
    FragTrap frag2("FragMaster");
    std::cout << std::endl;

    std::cout << "=== Copy Constructor Test ===" << std::endl;
    
    FragTrap frag3(frag2);
    std::cout << std::endl;

    std::cout << "=== Copy Assignment Operator Test ===" << std::endl;
    
    frag1 = frag2;
    std::cout << std::endl;

    std::cout << "=== Attack Test ===" << std::endl;
    
    frag2.attack("Intruder");
    frag2.attack("Another Intruder");
    
    std::cout << std::endl;

    std::cout << "=== Energy Drain Test ===" << std::endl;
    
    for (int i = 0; i < 100; ++i) {
        frag2.attack("Dummy Target");
    }
    
    frag2.attack("Dummy Target");
    
    std::cout << std::endl;

    std::cout << "=== Take Damage Test ===" << std::endl;
    
    frag2.takeDamage(50);
    frag2.takeDamage(80); // Overkill
    frag2.takeDamage(10); // Already dead
    
    std::cout << std::endl;

    std::cout << "=== Repair Test ===" << std::endl;
    
    frag3.takeDamage(50); // Reduce HP first
    frag3.beRepaired(20);
    frag3.beRepaired(40);
    frag3.beRepaired(10); // Insufficient energy
    
    std::cout << std::endl;

    std::cout << "=== High Five Test ===" << std::endl;
    
    frag3.highFivesGuys(); // Alive
    frag2.highFivesGuys(); // Dead
    
    std::cout << std::endl;

    std::cout << "=== Deconstructor ===" << std::endl;

}

