/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:54:49 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/05 11:08:08 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	if (N < 1)
		return NULL;

	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}

	return horde;
}
