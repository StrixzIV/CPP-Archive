/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:51:13 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 14:14:36 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

	Zombie *heap_zombie;

	heap_zombie = newZombie("Heap zombie");
	heap_zombie->announce();

	randomChump("Stack zombie");

	delete heap_zombie;

}
