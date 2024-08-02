/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:30 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 17:07:32 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon() {
    _type = "";
}

// Destructor
Weapon::~Weapon() {
    std::cout << this->_type << " just got destroyed." << std::endl;
}

const std::string &Weapon::getType() {
    return (_type);
}

void	Weapon::setType(std::string new_type) {
    this->_type = new_type;
}
