/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:47 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/05 21:25:17 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    {
        ClapTrap    noName;

        noName.attack("Patricia");
        noName.takeDamage(0);
        noName.beRepaired(10);
        noName.takeDamage(4);
        noName.attack("Patricia");
        noName.takeDamage(70);
        noName.beRepaired(1);
        noName.attack("Patricia");
        noName.takeDamage(0);
    }
    {
        ClapTrap    zerg("Zerg");

        zerg.beRepaired(1);
        zerg.beRepaired(2);
        zerg.beRepaired(3);
        zerg.beRepaired(4);
        zerg.beRepaired(5);
        zerg.beRepaired(6);
        zerg.beRepaired(7);
        zerg.beRepaired(8);
        zerg.beRepaired(9);
        zerg.beRepaired(10);

        zerg.attack("Scuttle");
        zerg.attack("Gromp");

        zerg.takeDamage(100);

        zerg.beRepaired(100);
    }
    {
        ClapTrap    sir("Sir");

        sir.attack("enemy");
        sir.attack("enemy");
        sir.attack("enemy");
        sir.attack("enemy");
        sir.attack("");
        sir.takeDamage(9);
        sir.attack("enemy");
        sir.attack("enemy");
        sir.attack("");
        sir.attack("enemy");
        sir.attack("enemy");

        sir.beRepaired(10);
        sir.takeDamage(1);
        sir.attack("enemy");
    }
}
