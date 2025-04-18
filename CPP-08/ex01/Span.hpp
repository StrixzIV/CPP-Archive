/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:00:00 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 12:31:50 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span {

    private:
        unsigned int size;
        std::vector<int> contents;

    public:

        Span(unsigned int size);
        Span(const Span &base);
        Span &operator=(const Span &rhs);
        ~Span();

        void addNumber(int number);
        void addMultipleNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan();
        int longestSpan();

        class OutOfBoundException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

        class SpanTooShortException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

#endif
