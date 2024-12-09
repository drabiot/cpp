/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:40:19 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 22:40:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FT_HEALTH 100
# define FT_ENERGY 100
# define FT_DAMAGE 30

class	FragTrap : virtual public ClapTrap {
public:
	FragTrap( void );
	FragTrap( const std::string &name );
	FragTrap( const FragTrap &src );
	FragTrap &operator = ( const FragTrap &rhs );
	~FragTrap( void );

	void	highFivesGuys( void );
};

#endif //FRAGTRAP_HPP
