/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:42:42 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 13:13:04 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <ctime>
# include <cstdlib>
# include <iostream>

# include <unistd.h>

class Base {

	public:
		virtual ~Base() {};

};

class A: public Base {};
class B: public Base {};
class C: public Base {};

#endif
