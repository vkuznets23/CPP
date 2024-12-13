/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:09:30 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 11:38:48 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {std::cout << "Default DiamondTrap constructor called" << std::endl; }

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "Parameterized DiamondTrap constructor called" << std::endl;
	_hitPoints = 100;
	_hitPoints = 100;
	_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &origin) 
	: ClapTrap(origin), ScavTrap(origin), FragTrap(origin) {
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &origin) {
	if (this != &origin) {
		ClapTrap::operator = (origin);
		ScavTrap::operator = (origin);
		FragTrap::operator = (origin);
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {std::cout << "DiamondTrap destructor called" << std::endl; }

void	DiamondTrap::whoAmI() {
	std::cout << "It's name: " << _name << std::endl
		<< "ClpaTrap name: " << ClapTrap::_name << std::endl;
}
