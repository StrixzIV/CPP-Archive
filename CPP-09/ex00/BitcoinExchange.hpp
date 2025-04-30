/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:43:22 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/22 14:24:47 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

# include <map>
# include <ctime>
# include <cstdlib>
# include <fstream>
# include <iostream>

class BitcoinExchange {

    private:

        std::map<std::string, double> exchange_map;

        BitcoinExchange();

        void validate_date(const std::string &line);
        bool is_valid_input(const std::string &line, const char delimiter);

        std::string get_date(const std::string &line);
        double get_value(const std::string &line, const char delimiter);

    public:

        BitcoinExchange(const std::string &exchange_value_path);
        BitcoinExchange(const BitcoinExchange &base);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        void calculate_exchange(const std::string &path);

        class DateTooEarlyException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

        class InvalidDateException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

        class InvalidValueException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

        class ExchangeFileException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

#endif
