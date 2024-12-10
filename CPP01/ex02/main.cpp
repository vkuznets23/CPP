/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:42:11 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/10 11:43:34 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string 	*stringPTR = &str;
	std::string 	&stringREF = str;

	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;


	std::cout << "Memory value of the string variable: " << str << std::endl;
	std::cout << "Memory value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "Memory value of the stringREF: " << stringREF << std::endl;
	
	return 0;
}
