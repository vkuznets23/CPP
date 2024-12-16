/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMAteria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:39:25 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/16 15:54:53 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream> 

class	AMateria {
protected:
	std::string _type;
public:
	AMateria();
	AMateria(const std::string &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMAteria &other);
	virtual ~AMateria();

	//returns materis type
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
