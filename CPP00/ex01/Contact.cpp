/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:26:30 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/05 15:05:25 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iomanip> 
#include <iostream>

Contact::Contact() {}

bool	isEmptyOrWhitespace(const std::string& str) {
	// Check if the string is empty or if all characters are space
	for (char c : str) {
		if (!std::isspace(c)) {
			return false;  // Return false if any character is not a space
		}
	}
	return true;  // Return true if all characters are spaces or the string is empty
}

bool	Contact::getInput(std::string &field, const std::string &prompt) {
	std::cout << prompt;
	if (!std::getline(std::cin, field)) {
		return false; // If EOF or input error occurs
	}
	if (field.empty() || isEmptyOrWhitespace(field)) {
		std::cout << "All fields must be filled in!\n";
		return getInput(field, prompt); // Retry input if the field is empty
	}
	return true;
}

bool	Contact::setContactDetails() {
	if (!getInput(_firstName, "Enter first name: "))
    		return false;
	if (!getInput(_lastName, "Enter last name: "))
    		return false;
	if (!getInput(_nickname, "Enter nickname: "))
    		return false;
	if (!getInput(_phoneNumber, "Enter phone number: "))
    		return false;
	if (!getInput(_darkestSecret, "Enter darkest secret: "))
    		return false;
	return true;
}

std::string	Contact::formatField(const std::string &field) {
	if (field.length() > 10) {
		return field.substr(0, 9) + ".";
	}
	return field;
}

void	Contact::printRow(int index) {
	std::cout << std::setw(10) << std::right << index << "|"
		<< std::setw(10) << std::right << formatField(_firstName) << "|"
		<< std::setw(10) << std::right << formatField(_lastName) << "|"
		<< std::setw(10) << std::right << formatField(_nickname) << "\n";
}

void	Contact::printDetails() {
	std::cout << "First name: " << _firstName << "\n"
		<< "Last name: " << _lastName << "\n"
		<< "Nickname: " << _nickname << "\n"
		<< "Phone number: " << _phoneNumber << "\n"
		<< "Darkest secret: " << _darkestSecret << "\n";
}
