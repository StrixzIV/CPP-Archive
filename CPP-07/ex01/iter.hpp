/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:26:45 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 00:31:32 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename MapFunc>
void iter(T *array, size_t length, MapFunc function) {

	for (size_t idx = 0; idx < length; idx++) {
		function(array[idx]);
	}

}

#endif
