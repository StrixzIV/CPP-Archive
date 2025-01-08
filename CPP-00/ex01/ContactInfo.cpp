/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:44:21 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/04 10:51:15 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactInfo.hpp"

ContactInfo::ContactInfo() : _name(""), _lastname(""), _nickname(""), _phone_number(""), _secret("") {}

ContactInfo::~ContactInfo() {}

std::string ContactInfo::get_name() const {
    return this->_name;
}

std::string ContactInfo::get_lastname() const {
    return this->_lastname;
}

std::string ContactInfo::get_nickname() const {
    return this->_nickname;
}

std::string ContactInfo::get_phone_number() const {
    return this->_phone_number;
}

std::string ContactInfo::get_secret() const {
    return this->_secret;
}

void ContactInfo::set_name(std::string value) {
    this->_name = value;
}

void ContactInfo::set_lastname(std::string value) {
    this->_lastname = value;
}

void ContactInfo::set_nickname(std::string value) {
    this->_nickname = value;
}

void ContactInfo::set_phone_number(std::string value) {
    this->_phone_number = value;
}

void ContactInfo::set_secret(std::string value) {
    this->_secret = value;
}
