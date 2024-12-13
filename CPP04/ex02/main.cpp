/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:41 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 09:55:52 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	int	numAnimals = 100;
	const 	Animal* animals[numAnimals];


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	//meta->makeSound();

	//delete meta;
	delete j;
	delete i;

	return 0;
}
