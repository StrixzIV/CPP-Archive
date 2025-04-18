/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:25:05 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 11:35:49 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void vector_test() {

    std::vector<int> numbers;

    for (int value = 0; value < 10; ++value) {
        numbers.push_back(value * 2);
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 6);
        std::cout << "Found 6 at position: " << std::distance(numbers.begin(), it) << std::endl;
    }
    
    catch (const ItemNotFoundException &e) {
        std::cout << "Failed to find 6: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 7);
        std::cout << "Found 7 at position: " << std::distance(numbers.begin(), it) << std::endl;
    }
    
    catch (const ItemNotFoundException &e) {
        std::cout << "Failed to find 7: " << e.what() << std::endl;
    }

}

void list_test() {

    std::list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    try {
        std::list<int>::iterator it = easyfind(numbers, 30);
        std::cout << "Found 30 in list." << std::endl;
        (void) it;
    }
    
    catch (const ItemNotFoundException &e) {
        std::cout << "Failed to find 30: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(numbers, 25);
        std::cout << "Found 25 in list." << std::endl;
        (void) it;
    }
    
    catch (const ItemNotFoundException &e) {
        std::cout << "Failed to find 25: " << e.what() << std::endl;
    }

}

int main() {

    std::cout << "----- Vector -----" << std::endl;
    vector_test();

    std::cout << "----- List -----" << std::endl;
    list_test();

}
