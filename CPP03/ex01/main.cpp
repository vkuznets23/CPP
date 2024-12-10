/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:37:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/10 16:46:46 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	vannila;
	ScavTrap	uno("Bob");
	ScavTrap	duo("Gena");

	uno.attack("Gena");
	duo.takeDamage(0);
	duo.beRepaired(9999);

	ScavTrap	angryRoboot(duo); //copy constructor

	angryRoboot.attack("Bob");
	uno.takeDamage(10);
	uno.beRepaired(10);

	for (int i = 0; i < 10; i++)
		angryRoboot.attack("Bob");
	
	uno.takeDamage(1);
	angryRoboot.beRepaired(1);

	angryRoboot.guardGate();
	
	return 0;
}
