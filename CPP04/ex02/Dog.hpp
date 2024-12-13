/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:06:51 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 16:03:23 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {
public:
	Brain	*_dogBrain;

public:
	Dog();
	Dog(const Dog &origin);
	Dog &operator=(const Dog &origin);
	~Dog();

	//override the makeSound function
	void	makeSound() const override;
};

#endif
