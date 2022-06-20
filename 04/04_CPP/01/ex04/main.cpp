/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:19:01 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/20 18:30:26 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReferFile.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Invalid Filename!\n";
		return 0;
	}
	else if (argc < 4) {
		std::cout << "s1 or s2 not provided!\n";
		return 0;
	}

	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		line;

	inputFile.open(argv[1]);
	outputFile.open(argv[1] + ".replace");
	std::getline(inputFile, line);
	while (line) {
		std::cout << line << "\n";
		outputFile << line << "\n";
	}

}
