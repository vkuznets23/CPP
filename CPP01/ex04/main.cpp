/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:42 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 17:11:03 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av) {
	if (ac < 4) {
		std::cout << "Usage: ./a.out <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	//define file names
	std::string	sourceFileName = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::string	destinationFileName = "destination.txt";

	//open for reading
	std::ifstream sourceFile(sourceFileName);
	if (!sourceFile) {
		std::cerr << "Cannot open file" << std::endl;
		return 1;
	}
	
	//open for writing
	std::ofstream destinationFile(destinationFileName);
	if (!destinationFile) {
		std::cerr << "Cannot create destination file" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(sourceFile, line)) {
		std::string modifiedLine = "";
		size_t pos = 0;

		while ((pos = line.find(s1, pos)) != std::string::npos) {
			// Append the part before s1 to modifiedLine
			modifiedLine += line.substr(0, pos);

			// Append s2
			modifiedLine += s2;

			// Move past the current match
			pos += s1.length();

			// Keep the rest of the line after s1
			line = line.substr(pos);

			pos = 0; // Reset pos to search again in the remaining part
		}
		modifiedLine += line;
		destinationFile << modifiedLine << '\n';
	}

	// Close files
	sourceFile.close();
	destinationFile.close();

	return 0;
}
