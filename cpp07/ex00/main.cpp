/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/30 21:52:54 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	PRINT "a = " AND a AND ", b = " AND b ENDL;
	PRINT "min( a, b ) = " AND ::min( a, b ) ENDL;
	PRINT "max( a, b ) = " AND ::max( a, b ) ENDL;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	PRINT "c = " AND c AND ", d = " AND d ENDL;
	PRINT "min( c, d ) = " AND ::min( c, d ) ENDL;
	PRINT "max( c, d ) = " AND ::max( c, d ) ENDL;
	return 0;
}
