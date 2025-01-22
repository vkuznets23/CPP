/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:30 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 12:03:39 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\n-----Types-----" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << "\n-----Making sounds-----" << std::endl;
	i->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << "\n-----Destructors-----" << std::endl;
	delete meta;
	delete dog; //should not create any leaks
	delete i;

	std::cout << "\n-----Unit test to check if Brain works-----" << std::endl;
	Brain	*brain = new Brain();
	brain->setIdea(0, "Bark at the mailman");
	brain->setIdea(1, "Chase the ball");
	brain->setIdea(2, "Take over the world");
	std::cout << "Idea 0: " << brain->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << brain->getIdea(1) << std::endl;
	std::cout << "Idea 2: " << brain->getIdea(2) << std::endl;
	delete brain;

	return 0;
}
