/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:46:58 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 21:49:56 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    
    std::cout << "=== Default Constructor Test ===" << std::endl;
    ScavTrap scav1;
    std::cout << std::endl;

    std::cout << "=== String Constructor Test ===" << std::endl;
    ScavTrap scav2("Guardian");
    std::cout << std::endl;

    std::cout << "=== Copy Constructor Test ===" << std::endl;
    ScavTrap scav3(scav2);
    std::cout << std::endl;

    std::cout << "=== Copy Assignment Operator Test ===" << std::endl;
    scav1 = scav2;
    std::cout << std::endl;

    std::cout << "=== Attack Test ===" << std::endl;
    scav2.attack("Intruder");
    scav2.attack("Another Intruder");
    std::cout << std::endl;

    std::cout << "=== Energy Drain Test ===" << std::endl;

    for (int i = 0; i < 50; ++i) {
        scav2.attack("Dummy Target");
    }
    
    scav2.attack("Dummy Target");
    std::cout << std::endl;

    std::cout << "=== Take Damage Test ===" << std::endl;
    scav2.takeDamage(30);
    scav2.takeDamage(80); // Overkill
    scav2.takeDamage(10); // Already dead
    std::cout << std::endl;

    std::cout << "=== Repair Test ===" << std::endl;
    scav3.takeDamage(50); // Reduce HP first
    scav3.beRepaired(20);
    scav3.beRepaired(40);
    scav3.beRepaired(10); // Insufficient energy
    std::cout << std::endl;

    std::cout << "=== Guard Gate Test ===" << std::endl;
    scav3.guardGate(); // Alive
    scav2.guardGate(); // Dead
    std::cout << std::endl;

    std::cout << "=== Deconstructor ===" << std::endl;
    
}
