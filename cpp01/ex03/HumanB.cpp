/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:53:17 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 20:36:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "color.hpp"

// Constructor
HumanB::HumanB (const std::string &name) {
	this->_name = name;
	this->_weapon = __nullptr;

    std::cout << GREEN << _name << " of type HumanB join the battle!" BASE_COLOR << std::endl;
}

// Destructor
HumanB::~HumanB () {
    std::cout << YELLOW << _name << " of type HumanB passed away..." BASE_COLOR << std::endl;
}

void    HumanB::attack() {
	if (!_weapon)
		std::cout << CYAN << _name << " doesn't have any weapon! But he gonna fight with his hands" BASE_COLOR << std::endl;
	else
		std::cout << CYAN << _name << " attacks with their " << _weapon->getType() << BASE_COLOR << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}