/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:51:13 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 14:50:26 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

	int horde_size = 20;
	Zombie *horde = zombieHorde(horde_size, "Horde Zombie");

	for (int idx = 0; idx < horde_size; idx++) {
		horde[idx].announce();
	}

	delete [] horde;

}
