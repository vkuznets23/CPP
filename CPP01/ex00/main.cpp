/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:22 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/10 10:50:27 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*heap_zombie;

	std::cout << "ALLOCATE A ZOMBIE ON THE STACK" << std::endl;
	randomChump("Foo_stack");

	std::cout << std::endl << "ALLOCATE A ZOMBIE ON THE HEAP" << std::endl;
	heap_zombie = newZombie("Foo_heap");

	// Now you can use the zombie (e.g., announce it)
	std::cout << "Announce it manually!!" << std::endl;
	heap_zombie->announce();

	// Once you're done with the zombie, free the memory
	std::cout << std::endl << "Destroy it manually!!" << std::endl;
	delete heap_zombie;

	return 0;
}
