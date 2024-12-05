/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:50:29 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/05 15:14:30 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	command;
	std::string	index;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) { // Check if input failed (e.g., Ctrl+D)
			std::cout << "\nExiting the program.\n";
			break ;
		}
		if (command == "ADD") {
			phonebook.addContact();
		} else if (command == "SEARCH") {
			phonebook.displayContacts();
			std::cout << "Enter the contact index to view details (1-8): ";
			if(!std::getline(std::cin, index)) {
				std::cout << "\nExiting the program.\n";
				break ;
			}
			try {
				int number = std::stoi(index);  // Convert string to int
				phonebook.searchContact(number);
			} catch (const std::exception& e) {
				std::cout << "Invalid index." << std::endl;
			}
		} else if (command == "EXIT") {
			std::cout << "\nExiting the program.\n";
			break ;
		} else {
			std::cout << "Invalid command, please try again.\n";
		}
	}
	return (0);
}
