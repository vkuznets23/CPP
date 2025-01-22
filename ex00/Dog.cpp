/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:13:54 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/21 10:52:03 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog") {std::cout << "Default Dog constructor called" << std::endl; }

Dog::Dog(const Dog &other) : Animal(other) { std::cout << "Copy Dog constructor called" << std::endl; }

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	Animal::operator = (other);
	return *this;
}

Dog::~Dog() {std::cout << "Dog destructor called" << std::endl; }

void	Dog::makeSound() const {std::cout << "Woof! Woof!" << std::endl; }
