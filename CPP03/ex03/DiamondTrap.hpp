/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:48:33 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/17 10:34:09 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	_name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &origin);
	DiamondTrap &operator=(const DiamondTrap &origin);
	~DiamondTrap();

	void	whoAmI();
	void	attack(const std::string &target);
};
