/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:29:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/04/28 17:16:37 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact {
	private:
		string firstName;
		string lastName;
		string nickName;
		string phoneNumber;
		string darkestSecret;
	public:
		void SetContact(string _firstName, string _lastName, string _nickName, string _phoneNumber, string _darkestSecret);
		string GetFirstName();
		string GetLastName();
		string GetNickName();
		string GetPhoneNumber();
		string GetDarkestSecret();
}
