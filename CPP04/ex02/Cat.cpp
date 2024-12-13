/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:17:31 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 16:07:21 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat") {
	std::cout << "Default Cat constructor" << std::endl;
	_catBrain = new Brain();	//Dynamically allocate a Brain obj for the Cat
}

Cat::Cat(const Cat &origin) : Animal(origin) {
	std::cout << "Copy Cat constructor called" << std::endl;
	_catBrain = new Brain(*origin._catBrain);
}

Cat &Cat::operator=(const Cat &origin) {
	if (this == &origin) {
		return *this;
	}
	(Animal::operator=(origin));
	*(_catBrain) = *(origin._catBrain);  // Copy the Brain object
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
	delete _catBrain;
}

void	Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
