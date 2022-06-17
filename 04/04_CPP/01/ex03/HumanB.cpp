/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:42:27 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/18 01:43:42 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(void) {}

HumanB::HumanB(std::string name) {
	_name = name;
}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon weapon) {
	_weapon = weapon;
}

void HumanB::attack(void) {
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}
