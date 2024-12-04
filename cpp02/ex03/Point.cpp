/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:46:13 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/04 22:32:25 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(), _y() {
}

Point::Point( const float x, const float y ) : _x(x), _y(y) {
}

Point::Point( const Point &src ) {
	*this = src;
}

Point &Point::operator = ( const Point &rhs ) {
	if (this == &rhs)
		return (*this);
	const_cast<Fixed &>(this->_x) = rhs._x;
	const_cast<Fixed &>(this->_y) = rhs._y;
	return (*this);
}

Point::~Point() {
}

const Fixed &Point::getX() const {
	return(this->_x);
}

const Fixed &Point::getY() const {
	return(this->_y);
}
