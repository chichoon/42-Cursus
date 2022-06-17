/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:52:57 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 20:20:42 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *toReturn = new Zombie[N];
	std::stringstream s;

	for (int i = 0; i < N; i++) {
		s << name << "_" << i;
		toReturn[i].setName(s.str());
		s.str("");
	}
	return toReturn;
}
