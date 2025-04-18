/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:30:31 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 12:42:27 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {

    std::cout << "----- Subject's mandatory tests -----" << std::endl;

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n----- OutOfBoundException -----" << std::endl;

    try {
        
        Span small(3);
        std::vector<int> big_vec;
        
        for (int number = 1; number < 6; ++number)
            big_vec.push_back(number);
        
        small.addMultipleNumber(big_vec.begin(), big_vec.end());  // should throw
    
    }
    
    catch (const Span::OutOfBoundException &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- SpanTooShortException -----" << std::endl;
    
    try {
        Span shortSpan(1);
        shortSpan.addNumber(10);
        shortSpan.shortestSpan();  // should throw
    } 
    
    catch (const Span::SpanTooShortException &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- 10K numbers (addMultipleNumber) -----" << std::endl;

    try {

        Span bigSpan(10000);
        std::vector<int> nums;

        for (int i = 0; i < 10000; ++i)
            nums.push_back(rand());

        bigSpan.addMultipleNumber(nums.begin(), nums.end());
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << bigSpan.longestSpan() << std::endl;
    
    }
    
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- Copy Constructor & Assignment Operator Check -----" << std::endl;
    
    Span copy = sp;
    std::cout << "Copied Span - Shortest: " << copy.shortestSpan() << ", Longest: " << copy.longestSpan() << std::endl;

    Span assigned(10);
    assigned = sp;
    std::cout << "Assigned Span - Shortest: " << assigned.shortestSpan() << ", Longest: " << assigned.longestSpan() << std::endl;

}
