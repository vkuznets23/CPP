/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:30 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/23 10:39:07 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	// Uncommenting the following line should cause a compilation error because Animal is abstract
	// Animal myAnimal; // Error: cannot declare variable of abstract type 'Animal'

	std::cout << "-----Creating a Dog-----" << std::endl;
	Dog dog;
	dog.makeSound();

	std::cout << "-----Creating a Cat-----" << std::endl;
	Cat cat;
	cat.makeSound();

	std::cout << "-----Pointer to Abstract Class-----" << std::endl;
	Animal* animalPtr = new Dog(); // Allowed because Dog is not abstract
	animalPtr->makeSound();
	delete animalPtr;

	std::cout << "-----Deep Copy Test-----" << std::endl;
	Dog originalDog;
	originalDog.setIdea(0, "Protect the house");
	Dog copiedDog = originalDog; // Copy constructor

	// Modify the copy and verify the original is unaffected
	copiedDog.setIdea(0, "Play in the yard");
	std::cout << "Original Dog Idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea[0]: " << copiedDog.getIdea(0) << std::endl;

	return 0;
}
