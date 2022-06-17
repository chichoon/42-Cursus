/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:21:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 19:37:51 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
	private:
		int curIndex;
		Contact contactArr[8];
		int isFilled[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void AddNewContact();
		void SearchContact();
};

#endif
