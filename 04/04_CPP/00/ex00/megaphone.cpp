/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:14:50 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/18 17:10:39 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
	if (argc < 2) std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int i = 1; i < argc; i++)
			for(int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		std::cout << "\n";
	}
	return (0);
}
