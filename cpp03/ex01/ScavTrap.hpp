/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:37:41 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/05 22:57:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define ST_HEALTH 100
# define ST_ENERGY 50
# define ST_DAMAGE 20

class	ScavTrap : public ClapTrap {
public:
	ScavTrap( void );
	ScavTrap( const std::string &name );
	ScavTrap( const ScavTrap &src );
	ScavTrap &operator = ( const ScavTrap &rhs );
	~ScavTrap( void );

	void	attack( const std::string &target );
	void	guardGate( void );
private:
	bool	_isGuard;
};

#endif //SCAVTRAP_HPP
