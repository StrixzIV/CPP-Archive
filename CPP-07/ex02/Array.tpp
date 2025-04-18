/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:59:19 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 11:21:19 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename DataType>
Array<DataType>::Array() {
	this->size = 0;
	this->values = new DataType[this->size];
}

template<typename DataType>
Array<DataType>::Array(unsigned int size): values(NULL) {

	if (size == UINT_MAX) {
		throw IndexOverflowException();
	}

	this->size = size;
	this->values = new DataType[this->size];

}

template<typename DataType>
Array<DataType>::Array(const Array &base): size(base.size), values(base.values) {

	this->values = new DataType[this->size];

	for (unsigned int idx = 0; idx < this->size; idx++) {
		this->values[idx] = base.values[idx];
	}

}

template<typename DataType>
Array<DataType>::~Array() {
	
	if (!this->values) {
		return;
	}

	delete [] this->values;
	this->values = NULL;

}

template<typename DataType>
Array<DataType> &Array<DataType>::operator=(const Array &rhs) {

	if (this == &rhs)
		return *this;

	delete [] this->values;

	this->size = rhs.size;
	this->values = new DataType[this->size];

	for (unsigned int idx = 0; idx < this->size; idx++) {
		this->values[idx] = rhs.values[idx];
	}

	return *this;

}

template<typename DataType>
DataType Array<DataType>::operator[](unsigned int idx) const {

	if (idx >= this->size) {
		throw OutOfBoundException();
	}

	return this->values[idx];

}

template<typename DataType>
DataType &Array<DataType>::operator[](unsigned int idx) {

	if (idx >= this->size) {
		throw OutOfBoundException();
	}

	return this->values[idx];

}

template<typename DataType>
std::ostream &operator<<(std::ostream &lhs, Array<DataType> &rhs) {

	lhs << "[";

	for (unsigned int idx = 0; idx < rhs.length(); idx++) {

		lhs << rhs[idx];

		if (idx < rhs.length() - 1) {
			lhs << ",";
		}

	}

	lhs << "]";

	return lhs;

}

template<typename DataType>
unsigned int Array<DataType>::length() const {
	return this->size;
}

template<typename DataType>
const char *Array<DataType>::OutOfBoundException::what() const throw() {
	return "Array::OutOfBoundException - access is out of bound";
}

template<typename DataType>
const char *Array<DataType>::IndexOverflowException::what() const throw() {
	return "Array::IndexOverflowException - the given index is overflow";
}
