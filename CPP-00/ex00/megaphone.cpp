/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:59:47 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/04 10:15:19 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (size_t i = 1; argv[i]; i++) {
		for (size_t j = 0; argv[i][j]; j++) {
			std::cout << (char) std::toupper(argv[i][j]);
		}
	}

	std::cout << std::endl;

}
