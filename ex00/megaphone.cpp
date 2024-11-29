/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:51:28 by vkuznets          #+#    #+#             */
/*   Updated: 2024/11/29 11:15:26 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char * av[])
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j] != '\0'; j++) {
			av[i][j] = std::toupper(av[i][j]);
			std::cout << av[i][j];
		}
		if (i < ac - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
