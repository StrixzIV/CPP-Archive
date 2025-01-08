/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:52:37 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/04 12:03:02 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <cstdlib>
# include <iomanip>
# include <sstream>
# include <iostream>

# include "ContactInfo.hpp"

class PhoneBook {

	private:
		size_t		_contact_size;
		ContactInfo _contact_list[8];

	public:

		PhoneBook();
		~PhoneBook();

		void add_contact();
		void show_contact() const;
		void search_contact() const;

};

#endif
