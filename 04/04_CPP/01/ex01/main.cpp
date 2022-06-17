/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:32:59 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 20:15:23 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void) {
	int n = 10;
	Zombie *horde = zombieHorde(n, "jiychoi");

	std::cout << "======Horde of Zombies Crying...\n";
	for (int i = 0; i < n; i++)
		horde[i].announce();
	std::cout << "\n";

	std::cout << "======Horde of Zombies Destroying...\n";
	delete[](horde);
}
