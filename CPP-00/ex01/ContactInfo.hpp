/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:33:46 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/04 10:47:25 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_INFO_HPP
# define CONTACT_INFO_HPP

# include <string>

class ContactInfo {

	private:
		std::string	_name;
		std::string _lastname;
		std::string _nickname;
		std::string _phone_number;
		std::string _secret;

	public:

		ContactInfo();
		~ContactInfo();

		std::string get_name() const;
		std::string get_lastname() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_secret() const;

		void set_name(std::string value);
		void set_lastname(std::string value);
		void set_nickname(std::string value);
		void set_phone_number(std::string value);
		void set_secret(std::string value);

};

#endif
