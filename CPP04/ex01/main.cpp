/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:30 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/23 10:28:42 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const int animalCount = 6;
	Animal* animals[animalCount];

	// Create half dogs and half cats
	std::cout << "-----Half dogs-----" << std::endl;
	for (int i = 0; i < animalCount / 2; ++i) {
		animals[i] = new Dog();
	}
	
	std::cout << "-----Half cats-----" << std::endl;
	for (int i = animalCount / 2; i < animalCount; ++i) {
		animals[i] = new Cat();
	}

	std::cout << "-----Deep dog copy-----" << std::endl;
	// Copy a dog and test deep copy
	Dog originalDog;
	originalDog.setIdea(0, "Protect the house");
	Dog copiedDog = originalDog; // Copy constructor

	// Modify the copy and verify original is unaffected
	copiedDog.setIdea(0, "Play in the yard");
	std::cout << "Original Dog Idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea[0]: " << copiedDog.getIdea(0) << std::endl;
	
	// Cleanup
	std::cout << "-----Cleanup-----" << std::endl;
	for (int i = 0; i < animalCount; ++i) {
		delete animals[i];
	}
}
