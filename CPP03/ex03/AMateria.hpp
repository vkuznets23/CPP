/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:00:10 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 10:05:16 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	AMateria {
protected:
	std::string const _type
public:
	AMateria(std::string const &_type);
};
