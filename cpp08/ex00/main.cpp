/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/03 14:12:35 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main( void ) {
	std::vector<int>	intVector;

	intVector.push_back(-10);
	intVector.push_back(0);
	intVector.push_back(10);
	intVector.push_back(42);
	intVector.push_back(64);
	intVector.push_back(14752);
	intVector.push_back(-5482);
	intVector.push_back(6);
	intVector.push_back(142);
	intVector.push_back(69);
	intVector.push_back(47);
	intVector.push_back(31);
	intVector.push_back(32472);
	intVector.push_back(24);

	easyfind(intVector, 14752);
	easyfind(intVector, -10);
	easyfind(intVector, 100);
	easyfind(intVector, 24);
	
	return 0;
}
