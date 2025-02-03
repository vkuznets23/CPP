/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:11:04 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/23 10:27:53 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Animal.hpp"

class	Dog : public Animal {
	public:
		Brain	*_dogBrain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		//override the makeSoud function from Animal class
		void	makeSound() const override;

		// Test methods
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};
