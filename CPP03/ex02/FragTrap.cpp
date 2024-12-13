/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:05:40 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 10:39:01 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructor" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor with name" << std::endl;
}

FragTrap::FragTrap(const FragTrap &origin) : ClapTrap(origin) {
	std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &origin) {
	if (this != &origin) {
		ClapTrap::operator = (origin);
	}
	return *this;
}

FragTrap::~FragTrap() {std::cout << "FragTrap destructor called" << std::endl; }

void	FragTrap::highFiversGuys() {
	std::cout << "FragTrap " << _name << " requests a high five! Raise your hand!" << std::endl;
}
