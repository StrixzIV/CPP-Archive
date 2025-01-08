/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:52:27 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 14:22:38 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {

	private:
		std::string _name;

	public:

		Zombie();
		Zombie(std::string);
		
		~Zombie();

		void announce();
		void set_name(std::string name);

};

Zombie *zombieHorde(int n_zombie, std::string name);

#endif
