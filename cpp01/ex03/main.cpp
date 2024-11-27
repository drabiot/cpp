/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:07 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 20:43:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon zanpakuto = Weapon("Kyōka Suigetsu");
		Weapon hōgyoku = Weapon ("Hōgyoku");
		HumanB aizen("Aizen");
		aizen.attack();
		aizen.setWeapon(zanpakuto);
		aizen.attack();
		aizen.setWeapon(hōgyoku);
		aizen.attack();
	}
return 0;
}