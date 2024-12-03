/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:01:57 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/03 21:21:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include "color.hpp"

class	Fixed {
public:
	Fixed( void );
	Fixed( const int num );
	Fixed( const float num);
	Fixed( const Fixed &src );
	Fixed &operator = ( const Fixed &rhs );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
private:
	int					_num;
	static const int	_bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);

#endif //FIXED_HPP