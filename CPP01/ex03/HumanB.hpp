/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:18:03 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 16:33:58 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
# include <iostream>

class	HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string name);
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif
