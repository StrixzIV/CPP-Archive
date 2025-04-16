/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:59:19 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 01:56:22 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename DataType>
Array<DataType>::Array() {
	this->size = 0;
	this->values = new DataType[this->size];
}

template<typename DataType>
Array<DataType>::Array(size_t size): values(NULL) {

	if (size == SIZE_T_MAX) {
		throw IndexOverflowException();
	}

	this->size = size;
	this->values = new DataType[this->size];

}

template<typename DataType>
Array<DataType>::Array(const Array &base): size(base.size), values(base.values) {

	this->values = new DataType[this->size];

	for (size_t idx = 0; idx < this->size; idx++) {
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

	for (size_t idx = 0; idx < this->size; idx++) {
		this->values[idx] = rhs.values[idx];
	}

	return *this;

}

template<typename DataType>
DataType Array<DataType>::operator[](size_t idx) const {

	if (idx >= this->size) {
		throw OutOfBoundException();
	}

	return this->values[idx];

}

template<typename DataType>
DataType &Array<DataType>::operator[](size_t idx) {

	if (idx >= this->size) {
		throw OutOfBoundException();
	}

	return this->values[idx];

}

template<typename DataType>
std::ostream &operator<<(std::ostream &lhs, Array<DataType> &rhs) {

	lhs << "[";

	for (size_t idx = 0; idx < rhs.size; idx++) {

		lhs << rhs.values[idx];

		if (idx < rhs.size - 1) {
			lhs << ",";
		}

	}

	lhs << "]";

	return lhs;

}

template<typename DataType>
size_t Array<DataType>::length() const {
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
