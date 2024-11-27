/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:30 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 20:07:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "color.hpp"

// Constructor
Weapon::Weapon(const std::string &type) {
    this->_type = type;

    std::cout << MAGENTA << this->_type << " join the armory!" BASE_COLOR << std::endl;
}

// Destructor
Weapon::~Weapon() {
    std::cout << RED << this->_type << " just got destroyed." BASE_COLOR << std::endl;
}

const std::string &Weapon::getType() {
    return (_type);
}

void	Weapon::setType(std::string new_type) {
    this->_type = new_type;
}
