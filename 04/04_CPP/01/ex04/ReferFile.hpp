/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReferFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:06:15 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/27 13:58:16 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFERFILE_HPP
# define REFERFILE_HPP

#include <iostream>
#include <string>
#include <fstream>

class ReferFile {
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;
	public:
		ReferFile(std::string filename, std::string s1, std::string s2);
		~ReferFile(void);
		void	replaceWord(void);
};

#endif
