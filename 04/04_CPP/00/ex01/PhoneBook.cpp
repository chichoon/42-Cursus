/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:07 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 17:50:53 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	curIndex = 0;
	for (int i = 0; i < 8; i++) isFilled[i] = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "\033[1;31mPhonebook Losts forever. byebye...\e[0m\n";
}

void PhoneBook::AddNewContact() {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << "\nCurrent Index: " << curIndex + 1 << "\n";
	std::cout << "\033[1;32mEnter Firstname\e[0m: ";
	std::getline(std::cin, firstName);
	std::cout << "\033[1;32mEnter Lastname\e[0m: ";
	std::getline(std::cin, lastName);
	std::cout << "\033[1;32mEnter Nickname\e[0m: ";
	std::getline(std::cin, nickName);
	std::cout << "\033[1;32mEnter Phone Number\e[0m: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "\033[1;32mEnter Darkest Secret\e[0m: ";
	std::getline(std::cin, darkestSecret);
	contactArr[curIndex].SetFirstName(firstName);
	contactArr[curIndex].SetLastName(lastName);
	contactArr[curIndex].SetNickName(nickName);
	contactArr[curIndex].SetPhoneNumber(phoneNumber);
	contactArr[curIndex].SetDarkestSecret(darkestSecret);
	isFilled[curIndex] = 1;
	curIndex++;
	if (curIndex == 8) curIndex = 0;
	std::cout << "\n";
}

static void wordWrap(std::string str) {
	if (str.length() >= 10)
		std::cout << str.substr(0, 9) << '.';
	else {
		std::cout << std::setw(10);
		std::cout << str;
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
	std::cout << "\033[1;32mFirstname\e[0m: " << contact.GetFirstName() << "\n";
	std::cout << "\033[1;32mLastname\e[0m: " << contact.GetLastName() << "\n";
	std::cout << "\033[1;32mNickname\e[0m: " << contact.GetNickName() << "\n";
	std::cout << "\033[1;32mPhone number\e[0m: " << contact.GetPhoneNumber() << "\n";
	std::cout << "\033[1;32mDarkest Secret\e[0m: " << contact.GetDarkestSecret() << "\n";
	std::cout << "---------------------------------\n\n";
}

void PhoneBook::SearchContact() {
	std::string idxTemp;
	int searchIdx;

	std::cout << "\n|     \033[1;32mINDEX\e[0m| \033[1;32mFIRSTNAME\e[0m| \033[1;32m LASTNAME\e[0m|  \033[1;32mNICKNAME\e[0m|\n";
	for (int i = 0; i < 8; i++) {
		if (!isFilled[i]) break;
		printContact(contactArr[i], i);
	}
	std::cout << "\nEnter Index: ";
	std::getline(std::cin, idxTemp);
	if (idxTemp.length() > 2 || idxTemp[0] < '1' || idxTemp[0] > '8') std::cout << "Invalid Input " << idxTemp << " !!\n";
	else {
		searchIdx = std::atoi(idxTemp.c_str()) - 1;
		if (searchIdx < 0 || searchIdx > 7 || !isFilled[searchIdx])
			std::cout << "\n\033[1;31mNo Contact Found in index No." << searchIdx + 1 << "!!!\e[0m\n\n";
		else printSearchedContact(contactArr[searchIdx]);
	}
}
