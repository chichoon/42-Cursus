/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:20:33 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/18 01:36:46 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon(void) {}

std::string& Weapon::getType(void) {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}
