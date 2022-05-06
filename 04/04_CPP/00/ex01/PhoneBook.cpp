/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:07 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/06 12:06:26 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	curIndex = 0;
}

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

static void wordWrap(std::string str)
{
	int length = str.length();

	if (length >= 10)
		std::cout << str.substr(0, 9) << '.';
	else {
		std::string whitespace(10 - length, ' ');
		std::cout << whitespace << str;
	}
}

static void printContact(Contact contact, int i)
{
	std::cout << "|         ";
	std::cout << i;
	std::cout << "|";
	wordWrap(contact.GetFirstName());
	std::cout << "|";
	wordWrap(contact.GetLastName());
	std::cout << "|";
	wordWrap(contact.GetNickName());
	std::cout << "|\n";

}

void PhoneBook::SearchContact()
{
	int searchIdx;

	std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|\n";
	for (int i = 0; i < 8; i++) {
		if (!contactArr[i].GetFirstName().length()) break;
		printContact(contactArr[i], i);
	}
	std::cout << "Enter Index:";
	std::cin >> searchIdx;
	if (searchIdx < 0 || searchIdx > 7 || !contactArr[searchIdx].GetFirstName().length())
		std::cout << "No Contact Found in No." << searchIdx << "!!!\n";
	else printContact(contactArr[searchIdx], searchIdx);
	std::cout << searchIdx;
}
