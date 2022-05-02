/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:29:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/02 16:34:35 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact {
	private:
		std::string	_darkestSecret;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
	public:
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
