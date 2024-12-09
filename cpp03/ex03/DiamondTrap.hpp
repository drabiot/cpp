/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:00:59 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 22:24:45 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "color.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define DT_HEALTH FT_HEALTH
# define DT_ENERGY ST_ENERGY
# define DT_DAMAGE FT_DAMAGE

class	DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap( void );
	DiamondTrap( const std::string &name );
	DiamondTrap( const DiamondTrap &src );
	DiamondTrap &operator = ( const DiamondTrap &rhs );
	~DiamondTrap( void );

	void	whoAmI( void );
	void	attack( const std::string &target );
private:
	std::string	_name;
};

#endif //DIAMONDTRAP_HPP
