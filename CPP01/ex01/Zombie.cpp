/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:17 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/10 11:17:07 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//default constructor
Zombie::Zombie() {}

//constructor to initilize Zombie with name
Zombie::Zombie(std::string name) : _name(name) {}

//destructor
Zombie::~Zombie(void) {
	std::cout << "Zombie " << _name << " has been destroyed." << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}
