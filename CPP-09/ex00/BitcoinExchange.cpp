/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:15:05 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/22 14:29:46 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &exchange_value_path) {

    std::ifstream exchange_value_filestream(exchange_value_path.c_str());

    if (!exchange_value_filestream.good()) {
        throw ExchangeFileException();
    }

    std::string line;
    std::string date_str;

    std::getline(exchange_value_filestream, line);

    while (std::getline(exchange_value_filestream, line)) {

        date_str = get_date(line);

        try {
            validate_date(date_str);
            this->exchange_map[date_str] = get_value(line, ',');
        }

        catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    }

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &base) {
    this->exchange_map = base.exchange_map;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {

    if (this == &rhs) {
        return (*this);
    }

    this->exchange_map = rhs.exchange_map;
    return (*this);

}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::get_date(const std::string &line) {

    std::string date = line.substr(0, line.find('|'));

    // Stripping leading and trailing spaces
    date.erase(0, date.find_first_not_of(' '));
    date.erase(date.find_last_not_of(' ') + 1);

    return date;

}

double BitcoinExchange::get_value(const std::string &line, const char delimiter) {

    size_t delimiter_pos = line.find(delimiter);

    if (delimiter_pos == std::string::npos || delimiter_pos == line.length() - 1) {
        throw InvalidValueException();
    }
    
    return static_cast<double>(std::atof(line.substr(delimiter_pos + 1).c_str()));

}

bool BitcoinExchange::is_valid_input(const std::string &line, const char delimiter) {
    size_t delimiter_pos = line.find(delimiter);
    return !(delimiter_pos == std::string::npos || delimiter_pos == line.length() - 1);
}

void BitcoinExchange::validate_date(const std::string &line) {

    struct std::tm time_data;
    const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (!strptime(line.c_str(), "%Y-%m-%d", &time_data) || !std::isdigit(line[line.size() - 1])) {
        throw InvalidDateException();
    }

    int day = time_data.tm_mday;
    int month = time_data.tm_mon + 1;
    int year = time_data.tm_year + 1900;

    if (year < 2009 || (year == 2009 && month == 1 && day < 3)) {
        throw DateTooEarlyException();
    }

    if (day > days_in_month[month - 1]) {

        if (month != 2 || ((year % 400 != 0) && ((year % 4 != 0) || (year % 100 == 0))) || day > 29) {
            throw InvalidDateException();
        }

    }

}

void BitcoinExchange::calculate_exchange(const std::string &path) {

    if (this->exchange_map.size() < 1)
        throw InvalidValueException();

    std::string line;
    std::ifstream input_file_stream(path.c_str());

    if (!input_file_stream.good()) {
        throw ExchangeFileException();
    }

    std::string date;
    double value;

    std::getline(input_file_stream, line);

    while (std::getline(input_file_stream, line)) {

        date = get_date(line);

        try {

            validate_date(date);

            if (!is_valid_input(line, '|')) {
                throw InvalidValueException();
            }

        }

        catch (std::exception &e) {
            std::cerr << "Error: bad input => " << line << " (" << e.what() << ")" << std::endl;
            continue;
        }

        value = get_value(line, '|');

        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
        }

        else if (value < 0) {
            std::cerr << "Error: not a positive number" << std::endl;
        }

        else {

            std::map<std::string, double>::iterator iter = this->exchange_map.lower_bound(date);

            if (iter == this->exchange_map.end() || iter->first > date) {
                --iter;
            } 

            std::cout << date << " => " << value << " = " << value * iter->second << std::endl;

        }

    }

}

const char *BitcoinExchange::DateTooEarlyException::what() const throw() {
    return "Input date is before the creation of Bitcoin";
}

const char *BitcoinExchange::InvalidDateException::what() const throw() {
    return "Invalid input date";
}

const char *BitcoinExchange::InvalidValueException::what() const throw() {
    return "Invalid input value";
}

const char *BitcoinExchange::ExchangeFileException::what() const throw() {
    return "Unable to read or process the exchange file.";
}
