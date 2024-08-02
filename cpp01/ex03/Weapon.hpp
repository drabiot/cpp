/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:20 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 17:07:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon {
public:
	Weapon(void);	// Constructor
	~Weapon(void);	// Destructor

	// Getters
	const std::string &getType();

	// Setters
	void	setType(std::string new_type);
private:
	std::string	_type;

}

#endif //WEAPON_HPP