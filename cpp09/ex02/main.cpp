/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/07 20:33:40 by tchartie         ###   ########.fr       */
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

    struct timespec vecStart, deqStart, vecEnd, deqEnd; 
    sort.makePair(1, &vecStart, &deqStart, &vecEnd, &deqEnd);

    double vecTime = (vecEnd.tv_sec - vecStart.tv_sec) * 1e6 + (vecEnd.tv_nsec - vecStart.tv_nsec) * 1e-3;
    double deqTime = (deqEnd.tv_sec - deqStart.tv_sec) * 1e6 + (deqEnd.tv_nsec - deqStart.tv_nsec) * 1e-3;
    sort.showVectors(vecTime, deqTime);
    return (0);
}
