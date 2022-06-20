/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:30:14 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/20 17:31:09 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _weapon(weapon) {
	_name = name;
	_weapon = weapon;
}

HumanA::~HumanA(void) {}

void HumanA::attack(void) {
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}
