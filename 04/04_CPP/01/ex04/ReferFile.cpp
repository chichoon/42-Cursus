/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReferFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:24:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/27 15:50:22 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReferFile.hpp"

ReferFile::ReferFile(std::string filename, std::string s1, std::string s2) {
	_filename = filename;
	_s1 = s1;
	_s2 = s2;
	std::cout << _filename + " constructed\n";
}

ReferFile::~ReferFile(void) {
	std::cout << _filename + " destructed\n";
}

void ReferFile::replaceWord(void) {
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		line;
	std::string		fullLine;
	std::size_t		i;

	inputFile.open(_filename);
	outputFile.open(_filename + ".replace");

	std::cout << _filename + " opened\n";

	fullLine = "";

	while (!inputFile.eof()) {
		std::getline(inputFile, line);
		fullLine += line;
		if (line.length() > 0) fullLine += "\n";
	}
	fullLine.erase(fullLine.length(), 1);

	if (_s1.length() == 0) {
		i = 0;
		while (i < fullLine.length()) {
			fullLine.insert(i, _s2);
			i += (_s2.length() + 1);
		}
	} else {
		i = fullLine.find(_s1);
		while (i != fullLine.npos) {
			fullLine.erase(i, _s1.length());
			fullLine.insert(i, _s2);
			i = fullLine.find(_s1);
		}
	}
	outputFile << fullLine;
	inputFile.close();
	outputFile.close();
	std::cout << _filename + " closed\n";
}
