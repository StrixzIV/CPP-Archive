/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:57:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 12:34:37 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>

# include <stdint.h>

# include "Data.hpp"

class Serializer {

	private:
		Serializer();

	public:
		
		Serializer(const Serializer &base);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();

		static uintptr_t serialize(Data *ref_ptr);
		static Data *deserialize(uintptr_t raw_value);

};

#endif
