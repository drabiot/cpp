/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:20 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 19:49:36 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon {
public:
	Weapon(const std::string &type);	// Constructor
	~Weapon(void);	// Destructor

	// Getters
	const std::string &getType();

	// Setters
	void	setType(std::string new_type);
private:
	std::string	_type;

};

#endif //WEAPON_HPP