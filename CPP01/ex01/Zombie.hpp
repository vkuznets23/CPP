/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:53:58 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/10 11:13:19 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie();			// Defaul constructor
		Zombie(std::string name); 	// Constructor to initialize the name
		~Zombie();			// Destructor
		void announce();
		void setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
