/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:54:49 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/10 11:13:39 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	if (N < 1) {
		std::cout << "Invalid number of zombies. Returning nullptr." << std::endl;
		return NULL;
	}

	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name + "_" + std::to_string(i + 1));
	}

	return horde;
}
