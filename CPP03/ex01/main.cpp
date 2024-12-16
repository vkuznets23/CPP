/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:37:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/16 11:37:50 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	std::cout << "\n------- Calling default ScavTrap constructors -------" << std::endl;
	ScavTrap	vannila;
	ScavTrap	chocolate;
	
	std::cout << "\n------- Calling constructors with names -------" << std::endl;
	ScavTrap	uno("Bob");
	ScavTrap	duo("Gena");

	uno.attack("Gena");
	duo.takeDamage(0);
	duo.beRepaired(9999);

	std::cout << "\n------- Copy constructor Gena -------" << std::endl;
	ScavTrap	angryRoboot(duo);
	
	angryRoboot.attack("Bob");
	uno.takeDamage(10);
	uno.beRepaired(10);
	uno.beRepaired(10);

	std::cout << "\n------- While loop for copy constructor Gena (he has 49 energy points) -------" << std::endl;
	for (int i = 0; i < 50; i++)
		angryRoboot.attack("Bob");

	std::cout << std::endl;
	uno.takeDamage(1);
	angryRoboot.beRepaired(1);

	std::cout << "\n------- Gatekeeper mode -------" << std::endl;
	angryRoboot.guardGate();
	std::cout << std::endl;
	
	return 0;
}
