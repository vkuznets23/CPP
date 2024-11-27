
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <iomanip> // for std::setw()

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

		void	getInput(std::string &field, const std::string &prompt) {
			do {
				std::cout << prompt;
				if (!std::getline(std::cin, field)) {
					std::cout << "\nExiting the program.\n";
					exit(0);
				}
				if (field.empty()) {
					std::cout << "All fields must be filled in!\n";
				}
			} while (field.empty());
				
		}

	public:
		void 	setContactDetails() {
			getInput(firstName, "Enter first name: ");
			getInput(lastName, "Enter last name: ");
			getInput(nickname, "Enter nickname: ");
			getInput(phoneNumber, "Enter phone number: ");
			getInput(darkestSecret, "Enter darkest secret: ");
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
};

#endif
