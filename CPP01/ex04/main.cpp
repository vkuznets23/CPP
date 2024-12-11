/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:42 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 10:59:19 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/* ************************************************************************** */
/* This program replaces all occurrences of a substring (s1) with another     */
/* substring (s2) in a text file. It reads from a source file line by line,   */
/* performs the replacement, and writes the result to a new file named        */
/* sourceFileName + ".replace".                                               */
/*                                                                            */
/* Process:                                                                   */
/* 1. Open the source file for reading and a destination file for writing.    */
/* 2. For each line, find all occurrences of s1 using line.find(s1, pos):     */
/*    - Replace s1 with s2, append to the modified line, and adjust pos.      */
/* 3. Write the modified line to the destination file.                        */
/* 4. Close both files when done.                                             */
/*                                                                            */
/* Notes:                                                                     */
/* - Ensure files are opened successfully and handle errors appropriately.    */
/* - Use std::string::npos to check if s1 is not found.                       */
/* ************************************************************************** */

std::string replaceSubstring(const std::string& line, const std::string& s1, const std::string& s2) {
	std::string modifiedLine;
	size_t pos = 0, lastPos = 0;

	while ((pos = line.find(s1, lastPos)) != std::string::npos) {
		modifiedLine += line.substr(lastPos, pos - lastPos) + s2;
		lastPos = pos + s1.length();
	}
	modifiedLine += line.substr(lastPos);
	return modifiedLine;
}

int	main(int ac, char **av) {
	if (ac < 4) {
		std::cout << "Usage: ./a.out <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	sourceFileName = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::string	destinationFileName = sourceFileName + ".replace";

	if (s1.empty()) {
		std::cerr << "Error: The substring to replace (s1) cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream sourceFile(sourceFileName);
	if (!sourceFile) {
		std::cerr << "Cannot open file: " << sourceFileName << std::endl;
		return 1;
	}
	std::ofstream destinationFile(destinationFileName);
	if (!destinationFile) {
		std::cerr << "Cannot create destination file: " << destinationFileName << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(sourceFile, line)) {
		destinationFile << replaceSubstring(line, s1, s2) << '\n';
	}
	sourceFile.close();
	destinationFile.close();

	return 0;
}
