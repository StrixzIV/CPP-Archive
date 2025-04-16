/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:45:54 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 11:32:46 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Error: bad arguments." << std::endl;
		std::cerr << "Usage: convert <string-literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

}
