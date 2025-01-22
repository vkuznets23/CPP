/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:24:09 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 11:17:20 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat") {
	std::cout << "Default Cat constructor called" << std::endl;
	_catBrain = new Brain();	//Dynamically allocate a Brain obj for the Cat
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Copy Cat constructor called" << std::endl;
	_catBrain = new Brain(*other._catBrain);
}

Cat &Cat::operator=(const Cat &other) {
	if (this == &other)
		return *this;
	Animal::operator = (other);
	delete _catBrain;			//to avoid leaks
	_catBrain = new Brain(*other._catBrain);	//Copy the brain object
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _catBrain;
}

void	Cat::makeSound() const {std::cout << "Meow! Meow!" << std::endl; }
