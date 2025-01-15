/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:47:30 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/08 18:55:56 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	private:
		int _hp;
		int _mp;
		int _dmg;
		std::string _name;

	public:

		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &base);
		ClapTrap &operator=(const ClapTrap &rhs);
		~ClapTrap();

		const std::string &get_name() const;
		const int &get_hp() const;
		const int &get_mp() const;
		const int &get_dmg() const;

		void set_name(const std::string &name);
		void set_hp(const int &value);
		void set_mp(const int &value);
		void set_dmg(const int &value);

		void attack(const std::string &target);
		void takeDamage(unsigned int n_damage);
		void beRepaired(unsigned int n_heal);

};

#endif
