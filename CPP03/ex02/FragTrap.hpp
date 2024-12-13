/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:01:44 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 10:38:18 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &origin);
	FragTrap &operator = (const FragTrap &origin);
	~FragTrap();

	void	highFiversGuys();
};

#endif
