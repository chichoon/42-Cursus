/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:21:26 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/06 15:24:34 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
	std::string input;
	PhoneBook pb;

	while (1) {
		std::cout >> "Input command: ";
		std::getline(std::cin, input);
		if (input == "ADD") pb.AddNewContact();
		else if (input == "SEARCH") pb.SearchContact();
		else if (input == "EXIT") exit(0);
	}
}
