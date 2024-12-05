/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:50:48 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/05 15:05:56 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		
		bool	getInput(std::string &field, const std::string &prompt);

	public:
		Contact();
		bool		setContactDetails();
		std::string	formatField(const std::string &field);
		void		printRow(int index);
		void		printDetails();
};

bool	isEmptyOrWhitespace(const std::string& str);

#endif
