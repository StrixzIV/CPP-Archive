/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:11:05 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 13:26:43 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {

    std::cout << "----- Subject's mandatory tests -----" << std::endl;
    
    std::cout << "\nMutatntStack:" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);

    std::cout << "\nList:" << std::endl;
    
    std::list<int> list;
    
    list.push_back(5);
    list.push_back(17);
    
    std::cout << list.back() << std::endl;
    list.pop_back();

    std::cout << list.size() << std::endl;
    
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    
    std::list<int>::iterator it2 = list.begin();
    std::list<int>::iterator ite2 = list.end();

    ++it2;
    --it2;

    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::cout << std::endl;

    std::cout << "----- Iteration tests -----" << std::endl;

    std::cout << "\nForward:" << std::endl;
    MutantStack<int>::iterator it3 = mstack.begin();
    MutantStack<int>::iterator ite3 = mstack.end();
    for (; it3 != ite3; ++it3) {
        std::cout << *it3 << std::endl;
    }

    std::cout << "\nReverse:" << std::endl;
    for (MutantStack<int>::iterator rit = --mstack.end(); rit != --mstack.begin(); --rit) {
        std::cout << *rit << std::endl;
    }

    std::cout << std::endl;

}
