/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:44 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 16:53:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA {
public:
	HumanA(std::string init_name, Weapon &init_weapon);	// Constructor
	~HumanA(void);										// Destructor

	// Getters
	std::string getName();

	// Setters
	void	setName(std::string new_name);

	void	attack(void);
private:
	std::string	_name;
	Weapon		&_weapon;

};

#endif //HUMANA_HPP