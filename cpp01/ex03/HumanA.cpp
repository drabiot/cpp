/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:54 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 20:37:04 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "color.hpp"

// Constructor
HumanA::HumanA (const std::string &name, Weapon &weapon) : _weapon(weapon) {
    this->_name = name;

    std::cout << GREEN << _name << " of type HumanA join the battle!" BASE_COLOR << std::endl;
}

// Destructor
HumanA::~HumanA () {
    std::cout << YELLOW << _name << " of type HumanA passed away..." BASE_COLOR << std::endl;
}

void    HumanA::attack() {
    std::cout << CYAN << _name << " attacks with their " << _weapon.getType() << BASE_COLOR << std::endl;
}