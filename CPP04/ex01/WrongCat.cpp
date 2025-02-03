/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:22:30 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 09:40:35 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {std::cout << "Default WrongCat constructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "copy WrongCat constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this == &other)
		return *this;
	WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() { std::cout << "Default WrongCat destructor called" << std::endl; }

void	WrongCat::makeSound() const {
	std::cout << "Wrong cat doesn't say meow" << std::endl;
}
