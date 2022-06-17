/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:29:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 19:35:19 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
	private:
		std::string	_darkestSecret;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
	public:
		Contact(void);
		~Contact(void);
		void	SetFirstName(std::string fn);
		std::string	GetFirstName();
		void	SetLastName(std::string ln);
		std::string	GetLastName();
		void	SetNickName(std::string nn);
		std::string	GetNickName();
		void	SetPhoneNumber(std::string pn);
		std::string	GetPhoneNumber();
		void	SetDarkestSecret(std::string ds);
		std::string	GetDarkestSecret();
};

#endif
