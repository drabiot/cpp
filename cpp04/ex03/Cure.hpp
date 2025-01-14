/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:43 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/08 19:47:24 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria {
public:
	Cure( void );
	Cure( const Cure &src );
	Cure &operator = ( const Cure &rhs );
	~Cure( void );

	AMateria*	clone() const;
	void		use( ICharacter& target );
};

#endif //CURE_HPP
