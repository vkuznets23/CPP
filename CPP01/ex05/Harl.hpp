/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:38:49 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/05 13:49:41 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class	Harl {
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
	
	public:
		//call private functions depending on the level passed as param
		void	complain(std::string level);
};

#endif
