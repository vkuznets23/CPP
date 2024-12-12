/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:15:58 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 13:30:23 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {std::cout << "Default WrongCat constructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &origin) : WrongAnimal(origin) {
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &origin) {
	if (this == &origin) {
		return *this;
	}
	(WrongAnimal::operator=(origin));
	return *this;
}

WrongCat::~WrongCat() {std::cout << "WrongCat destructor called" << std::endl; }

void	WrongCat::makeSound() const {
	std::cout << "Wrong cat doesn't speak, only laugh, hahahaha!" << std::endl;
}
