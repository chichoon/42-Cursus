/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:17:09 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/27 14:49:12 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl harl = Harl();

	harl.complain("WARNING");
	harl.complain("asd");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("ERROR");
	return 0;
}
