/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:16:48 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 11:32:09 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt("DiamondBot");

	dt.attack("target");
	dt.takeDamage(10);
	dt.beRepaired(5);

	dt.whoAmI();

	return 0;
}
