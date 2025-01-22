/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:30 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 09:34:51 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	//-------------------------------------------//
	std::cout << "-----WrongCat tests-----" << std::endl;
	const WrongAnimal *defaultPet = new WrongAnimal();
	const WrongAnimal *parameterizedPet = new WrongAnimal("pet");
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "type: " << defaultPet->getType()  << std::endl;
	std::cout << "type: " << parameterizedPet->getType()  << std::endl;
	std::cout << "type: " << wrongCat->getType()  << std::endl;

	defaultPet->makeSound();
	parameterizedPet->makeSound();
	wrongCat->makeSound();

	delete meta;
	delete j;
	delete i;

	delete defaultPet;
	delete parameterizedPet;
	delete wrongCat;

	return 0;
}
