/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:18:11 by jiychoi           #+#    #+#             */
/*   Updated: 2022/06/18 01:35:58 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string&	getType();
		void			setType(std::string type);
};

#endif
