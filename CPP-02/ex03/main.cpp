/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:59:34 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 21:20:46 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main() {

	// Triangle #1

	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << "A(x, y) -> (" << a.get_x() << ", " << a.get_y() << ")" << std::endl;
	std::cout << "B(x, y) -> (" << b.get_x() << ", " << b.get_y() << ")" << std::endl;
	std::cout << "C(x, y) -> (" << c.get_x() << ", " << c.get_y() << ")" << std::endl;
	std::cout << std::endl;

	std::cout << std::boolalpha;
	std::cout << bsp(a, b, c, Point(5, 5)) << std::endl;
	std::cout << bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << bsp(a, b, c, Point(10, 10)) << std::endl;
	std::cout << bsp(a, b, c, Point(4, 2)) << std::endl;
	std::cout << bsp(a, b, c, Point(4.2f, 2.4f)) << std::endl;
	std::cout << bsp(a, b, c, Point(9.9f, 0.05f)) << std::endl;
	std::cout << std::endl;

	// Triangle #2

	Point d(0.0f, 0.0f);
	Point e(0.0f, 20.0f);
	Point f(10.0f, 0.0f);

	std::cout << "D(x, y) -> (" << d.get_x() << ", " << d.get_y() << ")" << std::endl;
	std::cout << "E(x, y) -> (" << e.get_x() << ", " << e.get_y() << ")" << std::endl;
	std::cout << "F(x, y) -> (" << f.get_x() << ", " << f.get_y() << ")" << std::endl;
	std::cout << std::endl;
	
	std::cout << bsp(d, e, f, Point(3.0f, 3.0f)) << std::endl;
	std::cout << bsp(d, e, f, Point(33.0f, 53.0f)) << std::endl;
	std::cout << std::endl;

}
