/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:24:46 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 20:36:45 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "===== Memory Addresses\n";
	std::cout << "Memory Address of string:\t" << &brain << "\n";
	std::cout << "Memory Address of stringPTR:\t" << &stringPTR << "\n";
	std::cout << "Memory Address of stringREF:\t" << &stringREF << "\n";

	std::cout << "\n===== Values\n";
	std::cout << "Values of string:\t" << brain << "\n";
	std::cout << "Values of stringPTR:\t" << *stringPTR << "\n";
	std::cout << "Values of stringREF:\t" << stringREF << "\n";
}
