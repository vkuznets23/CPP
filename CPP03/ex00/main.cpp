/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:37:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/17 10:13:23 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	vannila;
	ClapTrap	uno("Bob");
	ClapTrap	duo("Gena");

	std::cout << "\n------- Original constructors Bod and Gena -------" << std::endl;
	uno.attack("Gena");
	duo.takeDamage(0);
	duo.beRepaired(9999);

	std::cout << "\n------- Copy constructor Gena -------" << std::endl;
	ClapTrap	angryRoboot(duo); //copy constructor

	angryRoboot.attack("Bob");
	uno.takeDamage(10);
	uno.beRepaired(10);
	uno.beRepaired(10);

	std::cout << "\n------- While loop for copy constructor Gena (he has 9 energy points) -------" << std::endl;
	for (int i = 0; i < 10; i++)
		angryRoboot.attack("Bob");
	std::cout << std::endl;

	uno.takeDamage(1);
	angryRoboot.beRepaired(1);

	std::cout << "\n------- Destructors -------" << std::endl;
	
	return 0;
}
