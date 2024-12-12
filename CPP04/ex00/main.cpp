/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:41 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 15:01:06 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "type: " << j->getType() << " " << std::endl;
	std::cout << "type: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "------WrongAnimal thingy------" << std::endl;
	const WrongAnimal* defaultPet = new WrongAnimal();
	const WrongAnimal* defaultPet2 = new WrongAnimal("pet");
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "type: " << wrongCat->getType() << std::endl;
	std::cout << "type: " << defaultPet->getType() << std::endl;
	std::cout << "type: " << defaultPet2->getType() << std::endl;
	wrongCat->makeSound();
	defaultPet->makeSound();
	defaultPet2->makeSound();

	delete meta;
	delete j;
	delete i;

	delete defaultPet;
	delete defaultPet2;
	delete wrongCat;

	return 0;
}
