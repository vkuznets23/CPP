/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:26:30 by vkuznets          #+#    #+#             */
/*   Updated: 2024/11/28 14:34:08 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iomanip> 
#include <iostream>

// getInput method definition
bool Contact::getInput(std::string &field, const std::string &prompt) {
    std::cout << prompt;
    if (!std::getline(std::cin, field)) {
        return false; // If EOF or input error occurs
    }
    if (field.empty()) {
        std::cout << "All fields must be filled in!\n";
        return getInput(field, prompt); // Retry input if the field is empty
    }
    return true;
}

// setContactDetails method definition
bool Contact::setContactDetails() {
    if (!getInput(firstName, "Enter first name: ")) return false;
    if (!getInput(lastName, "Enter last name: ")) return false;
    if (!getInput(nickname, "Enter nickname: ")) return false;
    if (!getInput(phoneNumber, "Enter phone number: ")) return false;
    if (!getInput(darkestSecret, "Enter darkest secret: ")) return false;
    return true;
}

// formatField method definition
std::string Contact::formatField(const std::string &field) {
    if (field.length() > 10) {
        return field.substr(0, 9) + "."; // Truncate and add a dot if it's longer than 10 characters
    }
    return field;
}

// printRow method definition
void Contact::printRow(int index) {
    std::cout << std::setw(10) << std::right << index << "|"
              << std::setw(10) << std::right << formatField(firstName) << "|"
              << std::setw(10) << std::right << formatField(lastName) << "|"
              << std::setw(10) << std::right << formatField(nickname) << "\n";
}
