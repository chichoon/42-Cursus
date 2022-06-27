/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:57:30 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/27 14:50:09 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << "Harl Created\n";
}

Harl::~Harl(void) {
	std::cout << "Harl Destructed\n";
}

void Harl::debug(void) {
	std::cout << "DEBUG: Blah\n";
}

void Harl::info(void) {
	std::cout << "INFO: Blah\n";
}

void Harl::warning(void) {
	std::cout << "WARNING: BlahBlah\n";
}

void Harl::error(void) {
	std::cout << "Error: BlahBlah\n";
}

void Harl::complain(std::string level) {
	void		(Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (str[i] == level) {
			(this->*func[i])();
			return;
		}
	}
	std::cout << "Harl cannot complain because the input value is invalid\n";
}
