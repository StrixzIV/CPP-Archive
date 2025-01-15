/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:46:58 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 22:19:13 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    std::cout << "===== Default constructor test =====" << std::endl;
    DiamondTrap dt1;
    std::cout << std::endl;

    std::cout << "===== String constructor test =====" << std::endl;
    DiamondTrap dt2("DiamondTrap");
    std::cout << std::endl;

    std::cout << "===== Copy constructor test =====" << std::endl;
    DiamondTrap dt3(dt2);
    std::cout << std::endl;

    std::cout << "===== Assignment operator test =====" << std::endl;
    DiamondTrap dt4;
    dt4 = dt2;
    std::cout << std::endl;

    std::cout << "===== Attack method test =====" << std::endl;
    dt2.attack("Enemy");
    std::cout << std::endl;

    std::cout << "===== High five (FragTrap function) test =====" << std::endl;
    dt2.highFivesGuys();
    std::cout << std::endl;

    std::cout << "===== Guard gate (ScavTrap function) test =====" << std::endl;
    dt2.guardGate();
    std::cout << std::endl;

    std::cout << "===== Who am I (DiamondTrap function) test =====" << std::endl;
    dt2.whoAmI();
    std::cout << std::endl;

    return 0;
}
