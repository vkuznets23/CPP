/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:13:55 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 15:49:19 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {
private:
	Brain	*_catBrain;
public:
	Cat();
	Cat(const Cat &origin);
	Cat &operator=(const Cat &prigin);
	~Cat();

	void	makeSound() const override;
};

#endif
