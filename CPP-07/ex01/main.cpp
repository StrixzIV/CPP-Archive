/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:26:34 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 00:36:23 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	map_func_test(T value) {
	std::cout << "If you can see this thing -> " << value << " the code works!" << std::endl;
}

int main() {

	int numbers[] = {0, 1, 2, 3, 4};
	std::string str_arr[] = {"This", "is", "an", "example"};

	::iter(numbers, 5, map_func_test<int>);
	::iter(str_arr, 4, map_func_test<std::string>);

}
