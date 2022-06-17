/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:30:14 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/18 01:39:37 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(void) {}

HumanA::HumanA(std::string name, Weapon weapon) {
	_name = name;
	_weapon = weapon;
}

HumanA::~HumanA(void) {}

void HumanA::attack(void) {
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}
