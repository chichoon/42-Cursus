/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:52 by jiychoi           #+#    #+#             */
/*   Updated: 2022/04/28 17:19:54 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void SetFirstName(string _firstName)
{
	firstName = _firstName;
}

void SetLastName(string _lastName)
{
	lastName = _lastName;
}

void SetNickName(string _nickName)
{
	nickName = _nickName;
}

void SetPhoneNumber(string _phoneNumber)
{
	phoneNumber = _phoneNumber;
}

void SetDarkestSecret(string _darkestSecret)
{
	darkestSecret = _darkestSecret;
}

string Contact::GetFirstName()
{
	return firstName;
}

string Contact::GetLastName()
{
	return lastName;
}

string Contact::GetNickName()
{
	return nickName;
}

string Contact::GetPhoneNumber()
{
	return phoneNumber;
}

string Contact::GetDarkestSecret()
{
	return darkestSecret;
}
