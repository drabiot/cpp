/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:06:05 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 21:58:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include "color.hpp"

# define CT_HEALTH 10
# define CT_ENERGY 10
# define CT_DAMAGE 0

class	ClapTrap {
public:
	ClapTrap( void );
	ClapTrap( const std::string &name );
	ClapTrap( const ClapTrap &src );
	ClapTrap &operator = ( const ClapTrap &rhs );
	virtual ~ClapTrap( void );

	void				setName( const std::string &name );
	void				setHealth( const int &i );
	void				setEnergy( const int &i );
	void				setDamage( const int &i );

	const std::string	getName( void );
	int					getHealth( void );
	int					getEnergy( void );
	int					getDamage( void );

	virtual void	attack( const std::string &target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
protected:
	std::string	_name;
	int			_health;
	int			_energy;
	int			_damage;
};

#endif //CLAPTRAP_HPP
