/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:11:48 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/22 14:25:38 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: Invalid arguments" << std::endl;
        std::cerr << "Usage: ./btc <exchange_file>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange("./data.csv");
        exchange.calculate_exchange(std::string(argv[1]));
    }

    catch (BitcoinExchange::ExchangeFileException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

}
