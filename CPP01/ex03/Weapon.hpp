/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:52:40 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 16:29:10 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>

class	Weapon {
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		std::string const &getType(void);
		void	setType(std::string type);
};

#endif
