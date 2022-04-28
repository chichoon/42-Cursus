/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:52 by jiychoi           #+#    #+#             */
/*   Updated: 2022/04/28 17:16:40 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
//first name, last name, nickname, phone number, and darkest secret.

void Contact::SetContact(string _firstName, string _lastName, string _nickName, string _phoneNumber, string _darkestSecret)
{
	firstName = _firstName;
	lastName = _lastName;
	nickName = _nickName;
	phoneNumber = _phoneNumber;
	darkestSecret= _darkestSecret;
}

void Contact::GetFirstName()
{
	return firstName;
}

void Contact::GetLastName()
{
	return lastName;
}

void Contact::GetNickName()
{
	return nickName;
}

void Contact::GetPhoneNumber()
{
	return phoneNumber;
}

void Contact::GetDarkestSecret()
{
	return darkestSecret;
}
