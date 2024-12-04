/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:46:30 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/04 22:32:55 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	scalarProduct(Point const p1, Point const p2, Point const p) {
	return ((p2.getX() - p1.getX()) * (p.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p.getX() - p1.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	v1 = scalarProduct(a, b, point);
	Fixed	v2 = scalarProduct(b, c, point);
	Fixed	v3 = scalarProduct(c, a, point);

	if ((v1 < 0 && v2 < 0 && v3 < 0) || (v1 >= 0 && v2 >= 0 && v3 >= 0))
		return (true);
	return (false);
}
