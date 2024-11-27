#ifndef CONTACT_HPP
#define CONTACT_HPP

class	Contact {
	
	private:
		std::string 	firstName;
		std::string 	lastName;
		std::string 	nickname;
		std::string 	phoneNumber;
		std::string 	darkestSecret;

	public:
		void	setContactDetails() {
			std::cout << "Enter first name: ";
        		std::getline(std::cin, firstName);
        		std::cout << "Enter last name: ";
        		std::getline(std::cin, lastName);
        		std::cout << "Enter nickname: ";
        		std::getline(std::cin, nickname);
        		std::cout << "Enter phone number: ";
        		std::getline(std::cin, phoneNumber);
        		std::cout << "Enter darkest secret: ";
        		std::getline(std::cin, darkestSecret);

        	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
            		std::cout << "All fields must be filled in!\n";
            		return;
        	}
	}
}

#endif
