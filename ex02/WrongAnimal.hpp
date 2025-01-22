/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:43:28 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 09:37:37 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 
# include <iostream>

class	WrongAnimal {
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator= (const WrongAnimal &other);
		virtual ~WrongAnimal();

		std::string	getType() const;
		virtual void	makeSound() const;
};
