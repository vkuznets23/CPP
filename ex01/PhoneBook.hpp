
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
				std::cout << std::string(44, '-') << "\n"; // Separator line
				array[index - 1].printRow(index);
			} else {
				std::cout << "Invalid index.\n";
			}		
		}

		/*void printAllContacts() {
			if (contactCount == 0) {
				std::cout << "Phonebook is empty.\n";
				return;
			}
			std::cout << std::setw(10) << "Index" << "|"
			          << std::setw(10) << "First Name" << "|"
			          << std::setw(10) << "Last Name" << "|"
			          << std::setw(10) << "Nickname" << "\n";
			std::cout << std::string(44, '-') << "\n"; // Separator line

			for (int i = 0; i < contactCount; i++) {
				array[i].printRow(i + 1);
			}
		}*/
};

#endif
