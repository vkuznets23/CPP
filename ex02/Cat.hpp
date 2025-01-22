/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:22:12 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 10:48:18 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "Animal.hpp"

class	Cat : public Animal {
private:
	Brain	*_catBrain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void	makeSound() const override;
};
