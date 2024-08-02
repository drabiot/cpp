/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:53:10 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 16:54:08 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB {
public:
	HumanB(std::string init_name);	// Constructor
	~HumanB(void);					// Destructor

	// Getters
	std::string getName();

	// Setters
	void	setName(std::string new_name);
	void	setWeapon(Weapon &weapon);

	void	attack(void);
private:
	std::string	_name;
	Weapon		*_weapon;

};

#endif //HUMANB_HPP