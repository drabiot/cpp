/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/08 19:47:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria {
public:
	Ice( void );
	Ice( const Ice &src );
	Ice &operator = ( const Ice &rhs );
	~Ice( void );

	AMateria*	clone() const;
	void		use( ICharacter& target );
};

#endif //ICE_HPP
