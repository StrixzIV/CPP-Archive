/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:38:28 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 11:22:38 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <limits.h>

# include <ctime>
# include <cstdlib>
# include <iostream>

template<typename DataType>
class Array {

	private:
		unsigned int size;
		DataType *values;

	public:

		Array<DataType>();
		Array<DataType>(unsigned int size);
		Array<DataType>(const Array &base);
		~Array();

		Array<DataType> &operator=(const Array<DataType> &rhs);
		DataType operator[](unsigned int i) const;
		DataType &operator[](unsigned int i);

		unsigned int length() const;

		class OutOfBoundException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class IndexOverflowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

template<typename DataType>
std::ostream &operator<<(std::ostream &lhs, Array<DataType> &rhs);

# include "Array.tpp"

#endif
