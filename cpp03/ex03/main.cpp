/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:47 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 22:54:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	{
		DiamondTrap	zigg("Zigg");

		zigg.attack("Tower");
		zigg.whoAmI();
		zigg.highFivesGuys();
		zigg.guardGate();
		zigg.guardGate();
		zigg.takeDamage(42);
	}
}
