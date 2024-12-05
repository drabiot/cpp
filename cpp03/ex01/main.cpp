/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:47 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/05 23:04:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    {
        ClapTrap    noName;

        noName.attack("Patricia");
        noName.takeDamage(0);
        noName.beRepaired(10);
        noName.takeDamage(4);
        noName.setName("Fabrice");
        noName.attack("Patricia");
        noName.takeDamage(70);
        noName.beRepaired(1);
        noName.attack("Patricia");
        noName.takeDamage(0);
    }
    {
        ScavTrap    masterWu;

        masterWu.setName("Master Wu");
        masterWu.attack("Anathema");
        masterWu.takeDamage(0);
        masterWu.guardGate();
        masterWu.guardGate();
    }
}
