/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:25:35 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/18 01:39:29 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon		_weapon;
	public:
		HumanA(void);
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);
		void	attack(void);
};

#endif
