/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:26:53 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 20:10:08 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie(void) {
	std::cout << _name << " destroyed... arrrgh...\n";
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
	_name = name;
}
