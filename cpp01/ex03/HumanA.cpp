/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:54 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 16:52:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string init_name, Weapon &init_weapon) : _weapon(init_weapon) {
	if (init_name.empty())
		_name = "nobody";
	else
		_name   = init_name;
}

// Destructor
HumanA::~HumanA() {
	std::cout << "We just lost " << this->_name << ". Goodbye..." << std::endl;
}

// Getters
std::string    HumanA::getName() {
	return (_name);
}
// Setters
void    HumanA::setName(std::string new_name) {
	this->_name = new_name;
}

void	HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}