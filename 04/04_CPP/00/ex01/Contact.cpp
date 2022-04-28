/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:52 by jiychoi           #+#    #+#             */
/*   Updated: 2022/04/28 17:57:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetDarkestSecret(string _darkestSecret)
{
	darkestSecret = _darkestSecret;
}

string	Contact::GetDarkestSecret()
{
	return darkestSecret;
}
