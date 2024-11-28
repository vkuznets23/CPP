/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:25:26 by vkuznets          #+#    #+#             */
/*   Updated: 2024/11/28 14:38:27 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip> 

// Constructor definition
PhoneBook::PhoneBook() : contactCount(0) {}

// addContact method definition
void PhoneBook::addContact() {
    if (contactCount < 8) {
        if (!array[contactCount].setContactDetails()) {
            std::cout << "\nExiting the program.\n";
            exit(0);
        }
        contactCount++;
    } else {
        std::cout << "Phonebook is full, replacing the oldest contact.\n";
        if (!array[7].setContactDetails()) {
            std::cout << "\nExiting the program.\n";
            exit(0);
        }
    }
}

// searchContact method definition
void PhoneBook::searchContact(int index) {
    if (contactCount == 0) {
        std::cout << "No contacts in the phonebook\n";
        return;
    }
    if (index >= 1 && index <= contactCount) {
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
