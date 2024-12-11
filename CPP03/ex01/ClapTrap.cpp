/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:08:48 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 13:41:41 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _name("Default name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {std::cout << "Default constructor called" << std::endl; };

ClapTrap::ClapTrap(std::string name) :  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {std::cout << "Constructor with name " << name << " called" << std::endl; };

ClapTrap &ClapTrap::operator = (const ClapTrap &origin) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &origin) {
		return *this;
	}

	_name = origin._name;
	_hitPoints = origin._hitPoints;
	_energyPoints = origin._energyPoints;
	_attackDamage = origin._attackDamage;
	return *this;
}

ClapTrap:: ClapTrap(const ClapTrap &origin) {
	std::cout << "Copy constructor called" << std::endl;
	_name = origin._name;
	_hitPoints = origin._hitPoints;
	_energyPoints = origin._energyPoints;
	_attackDamage = origin._attackDamage;
}

ClapTrap::~ClapTrap() {std::cout << "Destructor called" << std::endl; }

void	ClapTrap::attack(const std::string &target) {
	if (!_hitPoints) {
		std::cout << "ClapTrap " << _name << " doesn't have enough hit points! only "
			<< _hitPoints << std::endl;
	} else if (!_energyPoints) {
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points! only "
			<< _energyPoints << std::endl;
	} else {
		_energyPoints--;

		std::cout << "Claptrap " << _name << " attacks " << target << ", causing " 
		<< _attackDamage << " points of damage!" << " Remaining energy: " << _energyPoints << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->_hitPoints) {
		std::cout << "ClapTrap " << _name << " is almost dead, it cannot loose " << amount << " damage" << std::endl;
		return ;	
	}
	this->_hitPoints = (_hitPoints > amount ? _hitPoints - amount : 0);
	std::cout << "ClapTrap " << _name << " took " << amount << " damage, how sad! " 
		<< (_hitPoints ? "It's still alive" : "It's dead") << ". It has " << _hitPoints << " hit points"
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints >= 0 && _hitPoints + amount <= 10) {
		std::cout << "ClapTrap " << _name  << " gets " << _hitPoints 
			<< " amount of hit points back" << std::endl;
		
		_energyPoints--;
		_hitPoints += amount;
	} else {
		std::cout << "Cannot add hit points, ClapTrap " << _name 
			<< " already has " << _hitPoints << std::endl;
	}

}
