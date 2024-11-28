/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:50:40 by vkuznets          #+#    #+#             */
/*   Updated: 2024/11/28 10:50:44 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <iomanip> // for std::setw()
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact array[8];
		int	contactCount;
	public:
		PhoneBook() : contactCount(0) {}

		void	addContact() {
			if (contactCount < 8) {
				array[contactCount].setContactDetails();
				contactCount++;
			} else {
				std::cout << "Phonebook is full, replacing the oldest contact.\n";
				array[7].setContactDetails();
			}
		}

		void	searchContact(int index) {
			if (contactCount == 0) {
				std::cout << "No contacts in the phonebook\n";
				return ;
			} 
			if (index >= 1 && index <= contactCount){
				std::cout << std::setw(10) << "Index" << "|"
			          << std::setw(10) << "First Name" << "|"
			          << std::setw(10) << "Last Name" << "|"
			          << std::setw(10) << "Nickname" << "\n";
				std::cout << std::string(44, '-') << "\n";
				array[index - 1].printRow(index);
			} else {
				std::cout << "Invalid index.\n";
			}		
		}
};

#endif
