/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:16:48 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 14:17:54 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {
	std::cout << "Calling default ClapTrap constructors" << std::endl;
	ClapTrap	vannila1;
	ClapTrap	chocolate1;
	std::cout << std::endl;
	
	std::cout << "Calling ClapTrap constructors with names" << std::endl;
	ClapTrap	uno1("Bobby");
	ClapTrap	duo2("Genaaa");
	std::cout << std::endl;

	std::cout << "Calling default FragTrap constructors" << std::endl;
	FragTrap	vannila;
	FragTrap	chocolate;
	std::cout << std::endl;
	
	std::cout << "Calling constructors with names" << std::endl;
	FragTrap	uno("Bob");
	FragTrap	duo("Gena");
	std::cout << std::endl;

	std::cout << "Attacks and cmnds for FragTrap" << std::endl;
	uno.attack("Gena");
	duo.takeDamage(0);
	duo.beRepaired(9999);

	FragTrap	angryRoboot(duo);
	
	angryRoboot.attack("Bob");
	uno.takeDamage(10);
	uno.beRepaired(10);

	for (int i = 0; i < 10; i++)
		angryRoboot.attack("Bob");
	
	uno.takeDamage(1);
	angryRoboot.beRepaired(1);

	std::cout << std::endl << "High five function" << std::endl;
	angryRoboot.highFiversGuys();
	std::cout << std::endl;
	
	return 0;
}