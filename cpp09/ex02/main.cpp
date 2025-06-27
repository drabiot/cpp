/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/25 22:00:48 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Need integer to sort" << std::endl;
        return (1);
    }

    PmergeMe sort;
    for (int i = 1; i < argc; ++i)
        if (!sort.add(argv[i]))
            return 1;

    sort.makePair(1);
    sort.showVectors();
    return (0);
}
