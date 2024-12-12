/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:32:22 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 14:19:07 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {std::cout << "Default WrongAnimal constructor called" << std::endl; }

WrongAnimal::WrongAnimal(std::string type) : _type(type) {std::cout << "Parameterized WrongAnimal constructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &origin) {
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	_type = origin._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &origin) {
	if(this == &origin) {
		return *this;
	}
	_type = origin._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal destructor called" << std::endl; }

std::string	WrongAnimal::getType() const {
	return _type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Default WrongAnimal sound" << std::endl ;
}
