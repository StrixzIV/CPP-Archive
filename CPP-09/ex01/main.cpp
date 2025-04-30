/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:47:29 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/29 12:34:50 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {

    try {

        if (argc != 2)
            throw std::invalid_argument("Invalid arguments. Usage: ./RPN \"<expression>\"");

        RPN notation((std::string(argv[1])));

    }

    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}
