/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:07 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/06 16:01:14 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	curIndex = 0;
	for (int i = 0; i < 8; i++) isFilled[i] = 0;
}

void PhoneBook::AddNewContact() {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << "Current Index: " << curIndex + 1 << "\n";
	std::cout << "Enter Firstname: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Lastname: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	contactArr[curIndex].SetFirstName(firstName);
	contactArr[curIndex].SetLastName(lastName);
	contactArr[curIndex].SetNickName(nickName);
	contactArr[curIndex].SetPhoneNumber(phoneNumber);
	contactArr[curIndex].SetDarkestSecret(darkestSecret);
	isFilled[curIndex] = 1;
	curIndex++;
	if (curIndex == 8) curIndex = 0;
}

static void wordWrap(std::string str) {
	int length = str.length();

	if (length >= 10)
		std::cout << str.substr(0, 9) << '.';
	else {
		std::string whitespace(10 - length, ' ');
		std::cout << whitespace << str;
	}
}

static void printContact(Contact contact, int i) {
	std::cout << "|         ";
	std::cout << i + 1;
	std::cout << "|";
	wordWrap(contact.GetFirstName());
	std::cout << "|";
	wordWrap(contact.GetLastName());
	std::cout << "|";
	wordWrap(contact.GetNickName());
	std::cout << "|\n";
}

static void printSearchedContact(Contact contact) {
	std::cout << "\n----------SEARCH RESULT----------\n";
	std::cout << "Firstname: " << contact.GetFirstName() << "\n";
	std::cout << "Lastname: " << contact.GetLastName() << "\n";
	std::cout << "Nickname: " << contact.GetNickName() << "\n";
	std::cout << "Phone number: " << contact.GetPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << "\n";
	std::cout << "---------------------------------\n\n";
}

void PhoneBook::SearchContact() {
	std::string idxTemp;
	int searchIdx;

	std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|\n";
	for (int i = 0; i < 8; i++) {
		if (!isFilled[i]) break;
		printContact(contactArr[i], i);
	}
	std::cout << "Enter Index: ";
	std::getline(std::cin, idxTemp);
	if (idxTemp.length() > 2 || idxTemp[0] < '1' || idxTemp[0] > '8') std::cout << "Invalid Input " << idxTemp << " !!\n";
	else {
		searchIdx = std::atoi(idxTemp.c_str()) - 1;
		if (searchIdx < 0 || searchIdx > 7 || !isFilled[searchIdx])
			std::cout << "No Contact Found in index No." << searchIdx << "!!!\n";
		else printSearchedContact(contactArr[searchIdx]);
	}
}
