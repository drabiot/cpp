/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:52:44 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 19:48:09 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA {
public:
	HumanA(const std::string &name, Weapon &weapon);	// Constructor
	~HumanA(void);			// Destructor

	void	attack(void);
private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif //HUMANA_HPP