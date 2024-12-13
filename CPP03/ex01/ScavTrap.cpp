/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:17:46 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 10:28:00 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std:: string &name)
	: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor with name " << name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &origin) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &origin) {
		ClapTrap::operator=(origin);
	}
	return *this;
}

ScavTrap:: ScavTrap(const ScavTrap &origin) : ClapTrap(origin) {
	std::cout << "Copy constructor ScavTrap called" << std::endl;
}


ScavTrap::~ScavTrap() {std::cout << "Destructor for ScavTrap called" << std::endl; }

void	ScavTrap::attack(const std::string &target) {
	if (!_hitPoints) {
		std::cout << "ScavTrap " << _name << " cannot attack because it has no hit points left"
			<< std::endl;
		return ;
	}
	if (!_energyPoints) {
		std::cout << "ScavTrap " << _name << " doesn't have enough energy points! only "
			<< _energyPoints << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << " Remaining energy: "
		<< _energyPoints << std::endl;
}

void	ScavTrap::guardGate() {std::cout << "ScavTrap " << _name << "  is now in Gate keeper mode" << std::endl; }
