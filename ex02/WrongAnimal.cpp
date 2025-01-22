/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:46:56 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 10:05:45 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {std::cout << "Default WrongAnimal constructor called" << std::endl; }

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {std::cout << "Prameterized WrongAnimal constructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	_type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

std::string	WrongAnimal::getType() const {
	return _type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl ;
}
