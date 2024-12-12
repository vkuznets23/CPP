/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:12:00 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 16:07:24 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog") {
	std::cout << "Default Dog constuctor called" << std::endl;
	_dogBrain = new Brain();
}

Dog::Dog(const Dog &origin) : Animal(origin) {
	std::cout << "Copy Dog constructor" << std::endl;
	_dogBrain = new Brain(*origin._dogBrain);
}

Dog &Dog::operator=(const Dog &origin) {
	if (this == &origin) {
		return *this;
	}
	(Animal::operator=(origin));
	*(_dogBrain) = *(origin._dogBrain);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
	delete _dogBrain;
}

void	Dog::makeSound() const {
	std::cout << "Woof! Woof! Hau! Hau!" << std::endl;
}
