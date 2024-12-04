/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:02:39 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 16:31:38 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type) {}

std::string const &Weapon::getType() {
	return _type;
}

void	Weapon::setType(std::string type) {
	_type = type;
}
