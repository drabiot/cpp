/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:44:58 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 15:10:06 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  *zombie;

    // Creation of one time use Zombies that introduces themselves (stack)
    randomChump("Patrice");
    randomChump("Sebastian");
    randomChump("Isolde");

    // Creation of zombies that can introduces themselves (heap)
    zombie = newZombie("Valerie");
    zombie->annonce();
    zombie->annonce();
    delete(zombie);

    zombie = newZombie("George");
    delete(zombie);

    zombie = newZombie("Mike");
    zombie->annonce();
    delete(zombie);

    return (0);
}