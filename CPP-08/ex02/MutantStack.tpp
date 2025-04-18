/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:56:52 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 13:17:50 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename DataType>
MutantStack<DataType>::MutantStack(): std::stack<DataType>() {}

template <typename DataType>
MutantStack<DataType>::MutantStack(const MutantStack &base): std::stack<DataType>(base) {}

template <typename DataType>
MutantStack<DataType> &MutantStack<DataType>::operator=(const MutantStack &rhs) {

    if (this == &rhs) {
        return *this;
    }

    std::stack<DataType>::operator=(rhs);
    return *this;

}

template <typename DataType>
MutantStack<DataType>::~MutantStack() {}

template <typename DataType>
typename MutantStack<DataType>::iterator MutantStack<DataType>::begin() {
    return std::stack<DataType>::c.begin(); // Calling actual container iterator (dequeue)
}

template <typename DataType>
typename MutantStack<DataType>::iterator MutantStack<DataType>::end() {
    return std::stack<DataType>::c.end(); // Calling actual container iterator (dequeue)
}
