/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:21:26 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/20 18:47:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	std::string	input;
	PhoneBook	pb;

	while (1) {
		std::cout << "Available commands: ADD, SEARCH, EXIT\n\033[0;32mInput command\e[0m: ";
		std::getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof()) break;
		else if (input == "ADD") pb.AddNewContact();
		else if (input == "SEARCH") pb.SearchContact();
		else std::cout << "[" << input << "] is invalid command!!\n";
	}
	std::cout << "Existing Phonebook...\n";
	return 0;
}
