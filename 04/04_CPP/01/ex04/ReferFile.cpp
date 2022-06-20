/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReferFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:24:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/20 19:22:26 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReferFile.hpp"

ReferFile::ReferFile(std::string filename, std::string s1, std::string s2) {
	_filename = filename;
	_s1 = s1;
	_s2 = s2;
	std::cout << _filename + " constructed" << "\n";
}

ReferFile::~ReferFile(void) {
	std::cout << _filename + " destructed" << "\n";
}

void ReferFile::replaceWord(void) {
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		line;
	std::size_t		i;

	inputFile.open(_filename);
	outputFile.open(_filename + ".replace");

	std::cout << _filename + " opened" << "\n";

	while (!inputFile.eof()) {
		std::getline(inputFile, line);
		i = line.find(_s1);
		while (i < line.npos) {
			line.erase(i, _s1.length());
			line.insert(i, _s2);
			i = line.find(_s1);
		}
		outputFile << line << "\n";
	}
	inputFile.close();
	outputFile.close();
	std::cout << _filename + " closed" << "\n";
}
