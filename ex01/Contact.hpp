/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:50:48 by vkuznets          #+#    #+#             */
/*   Updated: 2024/11/28 11:16:06 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

		bool	getInput(std::string &field, const std::string &prompt) {
			std::cout << prompt;
			if (!std::getline(std::cin, field)) {
				//std::cout << "\nExiting the program.\n";
				return false; //!!!!!
			}
			if (field.empty()) {
				std::cout << "All fields must be filled in!\n";
				return getInput(field, prompt); // Retry input
			}
			return true;
				
		}

	public:
		bool	setContactDetails() {
			if (!getInput(firstName, "Enter first name: "))
				return false;
			if (!getInput(lastName, "Enter last name: "))
				return false;
			if (!getInput(nickname, "Enter nickname: "))
				return false;
			if (!getInput(phoneNumber, "Enter phone number: "))
				return false;
			if (!getInput(darkestSecret, "Enter darkest secret: "))
				return false;
			return true;
   		}

		std::string formatField(const std::string &field){
			if(field.length() > 10) {
				return field.substr(0,9) + "."; //need to truncate and add dot
			}
			return field;
		}

		void	printRow(int index) {
			std::cout << std::setw(10) << std::right << index << "|"
				<< std::setw(10) << std::right << formatField(firstName) << "|"
				<< std::setw(10) << std::right << formatField(lastName) << "|"
				<< std::setw(10) << std::right << formatField(nickname) << "\n";
		}
};

#endif
