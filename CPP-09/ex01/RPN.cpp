/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:48:00 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/29 12:38:48 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &expression) {
    
    size_t expression_len = expression.size();

    if (expression.empty()) {
        throw InvalidExpressionException();
    }

    for (size_t idx = 0; idx < expression_len; idx++) {

        if (std::isspace(expression[idx])) {
            continue;
        }

        else if (is_valid_ops(expression[idx]) && (std::isspace(expression[idx + 1]) || idx + 1 >= expression_len)) {
            read_ops(expression[idx]);
        }

        else if (std::isdigit(expression[idx]) && std::isspace(expression[idx + 1])) {
            this->values.push(static_cast<int>(expression[idx] - '0'));
        }

        else {
            throw InvalidExpressionException();
        }

    }

    // If there still a value left in the stack after eval, throw an exception
    if (this->values.size() != 1) {
        throw InvalidExpressionException();
    }

    std::cout << this->values.top() << std::endl;

}

RPN::RPN(const RPN &base) {
    (void) base;
}

RPN &RPN::operator=(const RPN &rhs) {
    (void) rhs;
    return (*this);
}

RPN::~RPN() {}

bool RPN::is_valid_ops(const char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
} 

void RPN::read_ops(const char c) {

    int x, y;

    if (this->values.size() < 2) {
        throw InvalidExpressionException();
    }

    x = this->values.top();
    this->values.pop();

    y = this->values.top();
    this->values.pop();

    switch (c) {

        case '+':
            this->values.push(y + x);
            break;

        case '-':
            this->values.push(y - x);
            break;

        case '*':
            this->values.push(y * x);
            break;

        case '/':

            if (x == 0) {
                throw DivisionByZeroException();
            }

            this->values.push(y / x);
            break;

    }

}

const char* RPN::InvalidExpressionException::what() const throw() {
    return "Error: Invalid expression syntax or unexpected character.";
}

const char* RPN::DivisionByZeroException::what() const throw() {
    return "Error: Cannot divide by zero.";
}
