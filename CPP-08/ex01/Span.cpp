/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:04:15 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 12:43:23 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size) {
    this->size = size;
}

Span::Span(const Span &base) {
    this->size = base.size;
    this->contents = base.contents;
}

Span &Span::operator=(const Span &rhs) {

    if (this == &rhs) {
        return *this;
    }

    this->size = rhs.size;
    this->contents = rhs.contents;

    return *this;

}

Span::~Span() {}

void Span::addNumber(int number) {

    if (this->contents.size() >= this->size) {
        throw OutOfBoundException();
    }

    this->contents.push_back(number);

}

void Span::addMultipleNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

    if (this->contents.size() + std::distance(begin, end) > this->size) {
        throw OutOfBoundException();
    }

    this->contents.insert(this->contents.end(), begin, end);

}

int Span::shortestSpan() {

    if (this->contents.size() <= 1) {
        throw SpanTooShortException();
    }

    std::vector<int> sorted_vec = this->contents;
    std::sort(sorted_vec.begin(), sorted_vec.end());

    int min = sorted_vec[1] - sorted_vec[0];

    for (unsigned int idx = 1; idx < sorted_vec.size() - 1; idx++) {
        if (sorted_vec[idx + 1] - sorted_vec[idx] < min) {
            min = sorted_vec[idx + 1] - sorted_vec[idx];
        }
    }

    return min;

}

int Span::longestSpan() {

    if (this->contents.size() <= 1) {
        throw SpanTooShortException();
    }

    std::vector<int> sorted_vec = this->contents;
    std::sort(sorted_vec.begin(), sorted_vec.end());

    return sorted_vec.back() - sorted_vec.front();

}


const char *Span::OutOfBoundException::what() const throw() {
	return "Span::OutOfBoundException - access is out of bound";
}


const char *Span::SpanTooShortException::what() const throw() {
	return "Span::SpanTooShortException - current span is too short for this operation.";
}
