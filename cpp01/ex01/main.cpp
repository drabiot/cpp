/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:43 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 16:19:34 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie  *zombies;
    int		size_horde;

	// Try to create a horde of 10 Zombies & try to annonce them
	size_horde = 10;
    zombies = zombieHorde(size_horde, "Gerard");
	if (zombies) {
		for (int i = 0; i < size_horde; i++) {
			zombies[i].annonce();
		}
		delete [] (zombies);
	}

	// Try to create a horde of 0 Zombie & try to annonce them
	size_horde = 0;
    zombies = zombieHorde(size_horde, "Tabea");
    if (zombies) {
		for (int i = 0; i < size_horde; i++) {
			zombies[i].annonce();
		}
		delete [] (zombies);
	}

	// Try to create a horde of -7 Zombies & try to annonce them
	size_horde = -7;
    zombies = zombieHorde(size_horde, "Gilbert");
    if (zombies) {
		for (int i = 0; i < size_horde; i++) {
			zombies[i].annonce();
		}
		delete [] (zombies);
	}

	// Try to create a horde of 1215752192 Zombies & try to annonce them
	size_horde = 1215752192;
    zombies = zombieHorde(size_horde, "Thibault");
    if (zombies) {
		for (int i = 0; i < size_horde; i++) {
			zombies[i].annonce();
		}
		delete [] (zombies);
	}

	// Try to create a horde of 3 Zombies & try to annonce them
	size_horde = 3;
    zombies = zombieHorde(size_horde, "Basile");
    if (zombies) {
		for (int i = 0; i < size_horde; i++) {
			zombies[i].annonce();
		}
		delete [] (zombies);
	}

	return(0);
}