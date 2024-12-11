/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:11:15 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 16:38:14 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {std::cout << "Default Animal constructor called" << std::endl; }

Animal::Animal(std::string type) : _type(type) {std::cout << "Parameterized Animal constructor called" << std::endl; }

Animal::Animal(const Animal &origin) {
	std::cout << "Copy animal constructor" << std::endl;
	_type = origin._type;
}

Animal &Animal::operator = (const Animal &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin) {
		return *this;
	}
	_type = origin._type;
	return *this;
}

Animal::~Animal() {std::cout << "Animal destructor called" << std::endl; }

std::string Animal::getType() const {
    return _type;
}

void	Animal::makeSound() const {
	std::cout << "Default animal sound" << std::endl;
}
