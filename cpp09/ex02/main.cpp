/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/24 17:59:15 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if (argc < 2) {
		ERROR RED "Need integer too sort" CENDL;
		return (1);
	}

	PmergeMe	sort;
	size_t		i = 0;

	while (argv[++i])
		if (!sort.add(argv[i]))
			return (1);
	
	sort.makePair(1);
	sort.showVectors();

	return (0);
}
