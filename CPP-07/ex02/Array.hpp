/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:38:28 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 01:57:46 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename DataType>
class Array {

	private:
		size_t size;
		DataType *values;

	public:

		Array<DataType>();
		Array<DataType>(size_t size);
		Array<DataType>(const Array &base);
		~Array();

		Array<DataType> &operator=(const Array<DataType> &rhs);
		DataType operator[](size_t i) const;
		DataType &operator[](size_t i);

		size_t length() const;

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
