/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:14 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 16:15:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *zombie;
    
    if (N <= 0) {
        std::cout << "Not enough Zombies to create a horde." << std::endl;
        return (NULL);
    }
    zombie = new(std::nothrow) Zombie[N];
    if (!zombie) {
        std::cout << "NOO, the horde failled to create. Try again!" << std::endl;
        return (NULL);
    }
    for (int i = 0; i < N; i++)
        zombie[i].setName(name);
    return (zombie);
}