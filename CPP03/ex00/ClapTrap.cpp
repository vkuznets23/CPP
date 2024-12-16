/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:08:48 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/16 12:01:32 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _name("Default name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {std::cout << "Default constructor called" << std::endl; };

ClapTrap::ClapTrap(const std::string &name) :  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {std::cout << "Constructor with name called" << std::endl; };

ClapTrap &ClapTrap::operator = (const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}

	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap:: ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;	
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

		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
		<< _attackDamage << " points of damage!" << " Remaining energy: " << _energyPoints << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!_hitPoints) {
		std::cout << "ClapTrap " << _name << " is almost dead, it cannot loose " << amount << " damage" << std::endl;
		return ;	
	}
	_hitPoints = (_hitPoints > amount ? _hitPoints - amount : 0);
	std::cout << "ClapTrap " << _name << " took " << amount << " damage point(s) " 
		<< (_hitPoints ? "It's still alive" : "It's dead") << ". It has " << _hitPoints << " hit points"
		<< std::endl;
}

//there is no mention on a limit of points????
void	ClapTrap::beRepaired(unsigned int amount) {
	if (!_energyPoints) {
		std::cout << "ClapTrap " << _name << " is too tired to repair itself" << std::endl;
	} else if (!_hitPoints) {
		std::cout << "ClapTrap " << _name << " isn't well! It can't repair itself" << std::endl; 
	} else {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name  << " gets " << amount 
			<< " amount of hit points back." << " It has " << _hitPoints << " hit points and "
			<< _energyPoints << " energy points" << std::endl;
	}

}
