/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:44 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 16:34:34 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

# include "Weapon.hpp"
# include <iostream> 

class HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void) const;
};

#endif
