/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:53:52 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/21 10:40:08 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() :  _type("Animal") {std::cout << "Default Animal constructor called" << std::endl; }

Animal::Animal(const std::string &type) : _type(type) {std::cout << "Parameterized Animal constructor called" << std::endl; }

Animal::Animal(const Animal &other) {
	std::cout << "Copy Animal constructor" << std::endl;
	_type = other._type;
}

//it might need deep copy ???
Animal &Animal::operator = (const Animal &other) {
	std::cout << "Copy Animal assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
	_type = other._type;
	return *this;
}

Animal::~Animal() {std::cout << "Animal destructor called" << std::endl; }

std::string Animal::getType() const {return _type; }

void	Animal::makeSound() const {std::cout << "Default sound" << std::endl; }
