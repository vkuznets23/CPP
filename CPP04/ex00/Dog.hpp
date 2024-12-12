/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:06:51 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 16:37:38 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal {
public:
	Dog();
	Dog(const Dog &origin);
	Dog &operator=(const Dog &origin);
	~Dog();

	//override the makeSound function
	void	makeSound() const override;
};

#endif
