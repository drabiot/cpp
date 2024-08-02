/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:23 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 15:28:34 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie {
public:
    Zombie(void);	// Constructor
	~Zombie(void);	// Destructor

	// Getters
	std::string  getName(void);

	// Setters
	void  setName(std::string new_name);

	void	annonce(void);

private:
	std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP