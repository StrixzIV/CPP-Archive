/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:45:06 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 14:48:10 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n_zombie, std::string name) {

	Zombie *horde = new Zombie[n_zombie];

	for (int idx = 0; idx < n_zombie; idx++) {
		horde[idx].set_name(name);
	}

	return horde;

}
