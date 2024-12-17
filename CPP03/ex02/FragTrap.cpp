/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:05:40 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/17 10:25:45 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructor" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor with name " << name << " called"  << std::endl;
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

//i need to costomize its behavuor
void	FragTrap::attack(const std::string &target) {
	if (!_hitPoints) {
		std::cout << "FragTrap " << _name << " cannot attack because it has no hit points left"
			<< std::endl;
		return ;
	}
	if (!_energyPoints) {
		std::cout << "FragTrap " << _name << " doesn't have enough energy points! only "
			<< _energyPoints << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << " Remaining energy: "
		<< _energyPoints << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " requests a high five! Raise your hand!" << std::endl;
}
