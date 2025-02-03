/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:50 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 11:26:02 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class	Brain {
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(const std::string ideas[100]);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;
};
