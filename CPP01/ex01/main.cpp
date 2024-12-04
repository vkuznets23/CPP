#include <iostream>
#include "Zombie.hpp"

int	main(void) {
	int N = 5;  // Number of zombies in the horde
	std::string baseName = "Zombie"; // Base name for zombies

	// Create a horde of N zombies
	Zombie* horde = zombieHorde(N, baseName);

	// Announce each zombie in the horde
	for (int i = 0; i < N; ++i) {
		horde[i].announce();  // Each zombie announces itself
	}

	// Free the memory allocated for the horde
	delete [] horde;

	return 0;
}
