/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:57:34 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/17 00:23:34 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void swap(T &a, T &b) {

	T tmp = a;

	a = b;
	b = tmp;

}

template<typename T>
T min(T &a, T &b) {

	if (a < b) {
		return a;
	}

	return b;

}

template<typename T>
T max(T &a, T &b) {
	
	if (a > b) {
		return a;
	} 
	
	return b;
	
}

#endif
