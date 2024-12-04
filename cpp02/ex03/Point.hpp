/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:46:38 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/04 22:31:48 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {
public:
	Point( void );
	Point( const float x, const float y );
	Point( const Point &src );
	Point &operator = ( const Point &rhs );
	~Point( void );

	const Fixed	&getX( void ) const;
	const Fixed	&getY( void ) const;
private:
	const Fixed	_x;
	const Fixed	_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif //POINT_HPP
