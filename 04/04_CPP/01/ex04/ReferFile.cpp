/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReferFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:24:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/20 18:25:38 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReferFile.hpp"

ReferFile::ReferFile(std::string filename) {
	_filename = filename;
}

ReferFile::~ReferFile(void) {
	std::cout << "file deleted" << "\n";
}
