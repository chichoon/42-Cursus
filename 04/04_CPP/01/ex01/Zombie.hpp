/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:23:21 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/17 20:19:15 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
};
