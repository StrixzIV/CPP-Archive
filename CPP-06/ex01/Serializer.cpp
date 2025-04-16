/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:02:44 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 12:33:52 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &base) {
	*this = base;
}

Serializer &Serializer::operator=(const Serializer &rhs) {
	(void) rhs;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ref_ptr) {
	return reinterpret_cast<uintptr_t>(ref_ptr);
}

Data *Serializer::deserialize(uintptr_t raw_value) {
	return reinterpret_cast<Data *>(raw_value);
}
