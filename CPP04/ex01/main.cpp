/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:41 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 16:08:51 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int	numAnimals = 100;
	const 	Animal* animals[numAnimals];

	for (int i = 0; i < numAnimals / 2; i++) {
		std::cout << i + 1 << " ";
		animals[i] = new Cat();
	}
	for (int i = numAnimals / 2; i < numAnimals; i++) {
		std::cout << i + 1 << " ";
		animals[i] = new Dog();
	}

	std::cout << "\nAnimal sounds:" << std::endl;
	for (int i = 0; i < numAnimals; i++) {
		std::cout << i + 1 << " ";
		animals[i]->makeSound();
	}

	std::cout << "\nDeleting animals..." << std::endl;
	for (int i = 0; i < numAnimals; i++) {
		std::cout << i + 1 << " ";
		delete animals[i];
	}
	
	return 0;
}
