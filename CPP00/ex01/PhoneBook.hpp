/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:50:40 by vkuznets          #+#    #+#             */
/*   Updated: 2024/11/29 13:48:14 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact array[8];
		int	_nextIndex;
		int	_contactCount;
	public:
		PhoneBook();

		void	addContact();
		void	searchContact(int index);
		void	displayContacts();
};

#endif
