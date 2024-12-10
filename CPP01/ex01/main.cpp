/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:11:24 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/10 11:24:16 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int N = 5;  				// Number of zombies in the horde
	std::string baseName = "Zombie"; 	// Base name for zombies

	// Create a horde of N zombies
	Zombie* horde = zombieHorde(N, baseName);
	if (!horde) {
		return 1;
	}

	// Announce each zombie in the horde
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}

	// Free the memory allocated for the horde
	delete [] horde;

	return 0;
}
