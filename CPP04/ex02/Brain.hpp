/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:16:34 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 15:20:56 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain {
private:
	std::string	_ideas[100];

public:
	Brain();
	Brain(std::string ideas[100]);
	Brain(const Brain &origin);
	Brain &operator=(const Brain &origin);
	~Brain();
};

#endif
