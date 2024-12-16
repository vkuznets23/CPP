/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMAteria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:39:25 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/16 15:42:22 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream> 

class	AMateria {
protected:
	std::string _type;
public:
	AMateria();
	AMateria(std::string const &type);
	AMAteria(const AMAteria &other);
	AMAteria &operator=(const AMAteria &other);
	~AMAteria();

	//returns materis type
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
