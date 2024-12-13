/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:07:54 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 09:46:31 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal{
protected:
	std::string	_type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &origin);
	Animal &operator=(const Animal &origin);

	//By making the destructor in the base class virtual, it ensures that the destructor 
	//for the derived class (Dog) runs first, followed by the base class (Animal). 
	//This helps properly clean up resources in a polymorphic setup.
	virtual ~Animal();

	//getter
	std::string	getType() const;

	virtual void	makeSound() const = 0;
};

#endif
