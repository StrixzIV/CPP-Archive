/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:47:46 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/15 14:27:32 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "A new Brain is created with default constructor" << std::endl;
}

Brain::Brain(const Brain &base) {
	*this = base;
	std::cout << "A brain is getting copied with copy constructor" << std::endl;
}

Brain::~Brain() {
	std::cout << "Braindead" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
	std::copy(rhs._ideas, rhs._ideas + 100, this->_ideas);
	std::cout << "A brain is getting copied with copy-assignment operator" << std::endl;
	return (*this);
}

const std::string &Brain::get_idea(const int &idx) const {
	
	if (idx < 0 || idx > 100) {
		return (this->_ideas[0]);
	}

	return (this->_ideas[idx]);

}

void Brain::set_idea(const std::string &idea, const int idx) {
	if (idx >= 0 && idx < 100) {
		this->_ideas[idx] = idea;
	}
}
