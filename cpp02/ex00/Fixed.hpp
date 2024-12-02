/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:01:57 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/02 22:30:55 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include "color.hpp"

class	Fixed {
public:
	Fixed( void );
	Fixed( const Fixed &src );
	Fixed &operator = ( const Fixed &rhs );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
private:
	int					_num;
	static const int	_bit = 8;
};

#endif //FIXED_HPP