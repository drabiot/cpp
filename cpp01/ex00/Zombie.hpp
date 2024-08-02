/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:45:10 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 13:54:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
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
 
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif //ZOMBIE_HPP