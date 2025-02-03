/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:44:53 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/23 10:34:28 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include "Brain.hpp"

class	Animal {
	protected:
		std::string	_type;
	public:
		Animal(); 				// default constructor
		Animal(const std::string &type);	// parameterized constr
		Animal(const Animal &other);		// copy constructor
		Animal &operator=(const Animal &other);	//copy assignment operator
		virtual ~Animal();				// destructor
	
		std::string	getType() const;
		virtual void	makeSound() const = 0;
};
