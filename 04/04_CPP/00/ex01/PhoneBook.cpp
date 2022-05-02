/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:07 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/02 16:27:43 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::AddNewContact()
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << "Enter Firstname: ";
	std::cin >> firstName;
	std::cout << "Enter Lastname: ";
	std::cin >> lastName;
	std::cout << "Enter Nickname: ";
	std::cin >> nickName;
	std::cout << "Enter Phone Number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter Darkest Secret: ";
	std::cin >> darkestSecret;
	contactArr[curIndex].SetFirstName(firstName);
	contactArr[curIndex].SetLastName(lastName);
	contactArr[curIndex].SetNickName(nickName);
	contactArr[curIndex].SetPhoneNumber(phoneNumber);
	contactArr[curIndex].SetDarkestSecret(darkestSecret);
	curIndex++;
	if (curIndex == 8) curIndex = 0;
}

void PhoneBook::SearchContact()
{
	int searchIdx;

	std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|\n";
	for (int i = 0; i < 8; i++) {
		if (!contactArr[i].GetFirstName().length()) break;
		std::cout << "|";
		std::cout << contactArr[i].GetFirstName();
	}
	std::cin >> searchIdx;
	std::cout << searchIdx;
}
