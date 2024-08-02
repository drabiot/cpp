/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:53:17 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 16:53:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string init_name) {
	if (init_name.empty())
		_name = "nobody";
	else
		_name   = init_name;
	_weapon = NULL;
}

// Destructor
HumanB::~HumanB() {
	std::cout << "We just lost " << this->_name << ". Goodbye..." << std::endl;
}

// Getters
std::string    HumanB::getName() {
	return (_name);
}
// Setters
void    HumanB::setName(std::string new_name) {
	this->_name = new_name;
}
void    HumanB::setWeapon(Weapon &new_weapon) {
	this->_weapon = &new_weapon;
}

void	HumanB::attack() {
	if (!this->_weapon)
		std::cout << this->_name << " has no weapon. He is attacking with his fists!" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}