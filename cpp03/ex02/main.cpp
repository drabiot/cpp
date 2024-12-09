/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:47 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 21:11:32 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << BRED "Create ClapTrap" BASE_COLOR << std::endl << std::endl;
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
	std::cout << std::endl << BRED "Create ScavTrap" BASE_COLOR << std::endl <<std::endl;
    {
        ScavTrap    masterWu;

        masterWu.setName("Master Wu");
        masterWu.takeDamage(0);
        masterWu.guardGate();
        masterWu.guardGate();
        for (size_t i = 1; i <= 40; i++) {
			masterWu.beRepaired(i);
        }
		for (size_t i = 1; i <= 15; i++) {
			masterWu.attack("Anathema");
        }
		masterWu.guardGate();
		masterWu.guardGate();
    }
	std::cout << std::endl << BRED "Create FragTrap" BASE_COLOR << std::endl << std::endl;
    {
        FragTrap    yasagi("Yasuo");

        yasagi.attack("Wind");
        yasagi.takeDamage(10);
        yasagi.highFivesGuys();

		//	Call setter to see if he can interact with 0 energy or 0 health
	
		std::cout << BYELLOW "Set Health to 0" BASE_COLOR << std::endl << std::endl;
		yasagi.setHealth(0);
		yasagi.attack("Wind");
		yasagi.takeDamage(10);
		yasagi.highFivesGuys();

		std::cout << BYELLOW "Set Energy to 0" BASE_COLOR << std::endl << std::endl;
		yasagi.setHealth(11);
		yasagi.setEnergy(0);
		yasagi.attack("Wind");
		yasagi.takeDamage(10);
		yasagi.highFivesGuys();
    }
}
