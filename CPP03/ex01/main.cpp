/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:37:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 13:57:24 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	std::cout << "Calling default ClapTrap constructors" << std::endl;
	ClapTrap	vannila1;
	ClapTrap	chocolate1;
	std::cout << std::endl;
	
	std::cout << "Calling ClapTrap constructors with names" << std::endl;
	ClapTrap	uno1("Bobby");
	ClapTrap	duo2("Genaaa");
	std::cout << std::endl;

	std::cout << "Calling default ScavTrap constructors" << std::endl;
	ScavTrap	vannila;
	ScavTrap	chocolate;
	std::cout << std::endl;
	
	std::cout << "Calling constructors with names" << std::endl;
	ScavTrap	uno("Bob");
	ScavTrap	duo("Gena");
	std::cout << std::endl;

	std::cout << "Attacks and cmnds for ScavTrap" << std::endl;
	uno.attack("Gena");
	duo.takeDamage(0);
	duo.beRepaired(9999);

	ScavTrap	angryRoboot(duo);
	
	angryRoboot.attack("Bob");
	uno.takeDamage(10);
	uno.beRepaired(10);

	for (int i = 0; i < 10; i++)
		angryRoboot.attack("Bob");
	
	uno.takeDamage(1);
	angryRoboot.beRepaired(1);

	std::cout << std::endl << "Gatekeeper mode" << std::endl;
	angryRoboot.guardGate();
	std::cout << std::endl;
	
	return 0;
}
