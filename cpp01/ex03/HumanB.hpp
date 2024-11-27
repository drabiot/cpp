/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:53:10 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 20:06:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB {
public:
	HumanB(const std::string &name);	// Constructor
	~HumanB(void);			            // Destructor

	void	attack(void);
    void    setWeapon(Weapon &weapon);
private:
	std::string	_name;
	Weapon	    *_weapon;
};

#endif //HUMANB_HPP