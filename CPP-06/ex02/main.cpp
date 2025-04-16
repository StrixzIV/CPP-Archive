/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:44:53 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 13:14:39 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate() {
	
	int choice = std::rand() % 3;

	switch (choice) {

		case 0:
			std::cout << "Generating class A" << std::endl;
			return new A;

		case 1:
			std::cout << "Generating class B" << std::endl;
			return new B;

		case 2:
			std::cout << "Generating class C" << std::endl;
			return new C;

	}

	return (NULL);

}

void identify(Base *ref) {

	if (dynamic_cast<A *>(ref)) {
		std::cout << "A" << std::endl;
	}

	else if (dynamic_cast<B *>(ref)) {
		std::cout << "B" << std::endl;
	}

	else if (dynamic_cast<C *>(ref)) {
		std::cout << "C" << std::endl;
	}

	else {
		std::cout << "unknown" << std::endl;
	}

}

void identify(Base &ref) {

	try {

		A &result = dynamic_cast<A &>(ref);
		(void) result;
	
		std::cout << "A" << std::endl;
		return ;
	
	}

	catch (const std::exception &error) {}

	try {

		B &result = dynamic_cast<B &>(ref);
		(void) result;
	
		std::cout << "B" << std::endl;
		return ;
	
	}

	catch (const std::exception &error) {}

	try {

		C &result = dynamic_cast<C &>(ref);
		(void) result;
	
		std::cout << "C" << std::endl;
		return ;
	
	}

	catch (const std::exception &error) {
		std::cout << "unknown" << std::endl;
	}
	
}

int main() {

	A a;
	B b;
	C c;

	std::cout << "Exact class check" << std::endl;

	identify(a);
	identify(b);
	identify(c);

	std::cout << "Randomized class check" << std::endl;

	Base *unknown_class;

	for (size_t n = 0; n < 10; n++) {

		std::srand(time(0));
		sleep(1);
		
		unknown_class = generate();

		std::cout << "Pointer identified as: ";
		identify(unknown_class);

		std::cout << "Reference identified as: ";
		identify(unknown_class);
		
		delete unknown_class;

	}

}
