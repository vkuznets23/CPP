/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:12:20 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 13:15:49 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &origin);
	WrongCat &operator=(const WrongCat &origin);
	~WrongCat();

	void	makeSound() const override;
};

#endif
