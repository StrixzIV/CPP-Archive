/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:38:19 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 02:21:33 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 10

int main() {
	
    std::cout << "Creating Array of size " << MAX_VAL << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(static_cast<unsigned>(time(NULL)));

    std::cout << "Filling both Array and mirror with random values..." << std::endl;
    for (size_t idx = 0; idx < MAX_VAL; idx++) {
        int value = rand();
        numbers[idx] = value;
        mirror[idx] = value;
    }

    {
        std::cout << "Testing copy constructor and assignment operator in scope..." << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        for (size_t idx = 0; idx < MAX_VAL; ++idx) {
            if (tmp[idx] != numbers[idx] || test[idx] != tmp[idx]) {
                std::cerr << "Copy test failed at index " << idx << std::endl;
                return 1;
            }
        }
		
    }

    std::cout << "Verifying values after scope to ensure deep copy..." << std::endl;
    for (size_t idx = 0; idx < MAX_VAL; idx++) {
        if (mirror[idx] != numbers[idx]) {
            std::cerr << "Error: Value mismatch at index " << idx << "! Expected " 
                      << mirror[idx] << ", got " << numbers[idx] << std::endl;
            return 1;
        }
    }

    std::cout << "Testing overflow size..." << std::endl;
	
    try {
        Array<int> test(SIZE_T_MAX);
    } 
	
	catch (const std::exception& e) {
        std::cerr << "Caught exception (overflow index initialization): " << e.what() << std::endl;
    }

    std::cout << "Testing out-of-bounds access..." << std::endl;
	
    try {
        numbers[-2] = 0;
    } 
	
	catch (const std::exception& e) {
        std::cerr << "Caught exception (negative index): " << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    } 
	
	catch (const std::exception& e) {
        std::cerr << "Caught exception (overflow index): " << e.what() << std::endl;
    }

    std::cout << "Refilling array with new random values..." << std::endl;
    for (size_t idx = 0; idx < MAX_VAL; idx++) {
        numbers[idx] = rand();
    }

	std::cout << "Display test" << std::endl;
	std::cout << numbers << std::endl;

    std::cout << "Cleaning up..." << std::endl;
    delete[] mirror;

}
