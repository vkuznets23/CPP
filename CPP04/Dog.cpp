/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:12:00 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 16:38:16 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog") {std::cout << "Default Dog constuctor called" << std::endl; }

Dog::Dog(const Dog &origin) : Animal(origin) {
	std::cout << "Copy Dog constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &origin) {
	if (this == &origin) {
		return *this;
	}
	(Animal::operator=(origin));
	return *this;
}

Dog::~Dog() {std::cout << "Dog destructor" << std::endl; }

void	Dog::makeSound() const {
	std::cout << "Woof! Woof! Hau! Hau!" << std::endl;
}
