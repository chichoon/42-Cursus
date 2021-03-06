/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:32:59 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/20 18:47:02 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int		n = 10;
	Zombie*	horde = zombieHorde(n, "jiychoi");

	std::cout << "======Horde of Zombies Crying...\n";
	for (int i = 0; i < n; i++)
		horde[i].announce();
	std::cout << "\n";

	std::cout << "======Horde of Zombies Destroying...\n";
	delete[] horde;

	return 0;
}
