/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:14:50 by jiychoi           #+#    #+#             */
/*   Updated: 2022/04/28 15:30:23 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int j;
	if (argc < 2) std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int i = 1; i < argc; i++) {
			j = 0;
			while (argv[i][j]) {
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					std::cout << char(argv[i][j] - 32);
				else std::cout << argv[i][j];
				j++;
			}
		}
	std::cout << "\n";
	}
}
