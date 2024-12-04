/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:25:26 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 13:27:56 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip> 
#include <cstdlib>

// Constructor definition
PhoneBook::PhoneBook() : _nextIndex(0), _contactCount(0) {}

void	PhoneBook::addContact() {
	if (!array[_nextIndex].setContactDetails()) {
		std::cout << "\nExiting the program.\n";
		exit(1);
	}
	_nextIndex = (_nextIndex + 1) % 8;
	if (_contactCount < 8)
		_contactCount++;
}

void	PhoneBook::displayContacts() {
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First name" << "|"
		<< std::setw(10) << "Last name" << "|"
		<< std::setw(10) << "Nickname" << "\n";
	std::cout << std::string(44, '-') << "\n";
	for (int i = 0; i < _contactCount; ++i) {
		array[i].printRow(i + 1);
	}
}

void	PhoneBook::searchContact(int index) {
	if (_contactCount == 0) {
		std::cout << "No contacts in the phonebook\n";
        	return ;
	}
	if (index < 1 || index > _contactCount) {
		std::cout << "Invalid index.\n";
		return ;
	}
	array[index - 1].printDetails();
}
