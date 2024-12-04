/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:53:58 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 14:28:04 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class	Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie(std::string name); 	// Constructor to initialize the name
		~Zombie(void);			// Destructor
		void announce( void );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif
