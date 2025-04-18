/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:16:50 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/18 11:33:18 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

# include <list>
# include <vector>

class ItemNotFoundException: public std::exception {

    public:
	    virtual const char *what() const throw() {
            return "ItemNotFoundException: cannot find target number in the container";
        }
        
};

template<typename T>
typename T::iterator easyfind(T &container, int target) {

    typename T::iterator iter = std::find(container.begin(), container.end(), target);

    if (iter == container.end()) {
        throw ItemNotFoundException();
    }

    return iter;

}

#endif
