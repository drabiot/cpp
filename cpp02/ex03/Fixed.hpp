/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:01:57 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/04 21:54:01 by tchartie         ###   ########.fr       */
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
	Fixed( const float num );
	Fixed( const Fixed &src );
	~Fixed( void );

	Fixed	&operator =		( const Fixed &rhs );
	Fixed	operator +		( const Fixed &rhs ) const ;
	Fixed	operator -		( const Fixed &rhs ) const ;
	Fixed	operator *		( const Fixed &rhs ) const ;
	Fixed	operator /		( const Fixed &rhs ) const ;

	bool 	operator >		( const Fixed &rhs ) const ;
	bool 	operator <		( const Fixed &rhs ) const ;
	bool 	operator >=		( const Fixed &rhs ) const ;
	bool 	operator <=		( const Fixed &rhs ) const ;
	bool 	operator ==		( const Fixed &rhs ) const ;
	bool 	operator !=		( const Fixed &rhs ) const ;

	Fixed	&operator ++	();
	Fixed	operator ++		(int);
	Fixed	&operator --	();
	Fixed	operator --		(int);

	static	Fixed &min (Fixed &num1, Fixed &num2);
	static	const Fixed &min (Fixed const &num1, Fixed const &num2);
	static	Fixed &max (Fixed &num1, Fixed &num2);
	static	const Fixed &max (Fixed const &num1, Fixed const &num2);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
private:
	int					_num;
	static const int	_bit = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& Fixed);

#endif //FIXED_HPP
