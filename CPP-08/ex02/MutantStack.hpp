/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:53:03 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 13:12:09 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>
# include <stack>
# include <iostream>

template<typename DataType>
class MutantStack: public std::stack<DataType> {

    public:

        typedef typename std::stack<DataType>::container_type::iterator iterator;

        MutantStack();
        MutantStack(const MutantStack &base);
        MutantStack &operator=(const MutantStack &rhs);
        ~MutantStack();

    iterator begin();
    iterator end();

};

# include "MutantStack.tpp"

#endif
