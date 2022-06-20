/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:32:59 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/20 18:47:05 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie*	zombie1 = newZombie("jiychoi");
	Zombie*	zombie2 = newZombie("junmkang");
	Zombie*	zombie3 = newZombie("seongele");
	Zombie*	zombie4 = newZombie("soju");

	std::cout << "======Random Chumps Crying...\n";
	randomChump("taeng");
	randomChump("jaewpark");
	randomChump("sungkim");
	std::cout << "\n";

	std::cout << "======Handmade Zombies Crying...\n";
	zombie1->announce();
	zombie2->announce();
	zombie3->announce();
	zombie4->announce();
	std::cout << "\n";

	std::cout << "======Handmade Zombies Destroying...\n";
	delete zombie1;
	delete zombie2;
	delete zombie3;
	delete zombie4;

	return 0;
}
