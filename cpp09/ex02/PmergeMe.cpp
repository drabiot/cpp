/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:18:23 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:45 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {
    PRINT GREEN "PmergeMe created" CENDL;
}

PmergeMe::PmergeMe( cref(PmergeMe) src ) {
    PRINT GREEN "PmergeMe Copy constructor operator called" CENDL;
    *this = src;
}

PmergeMe &PmergeMe::operator = ( cref(PmergeMe) rhs ) {
    PRINT GREEN "PmergeMe Copy assignment operator called" CENDL;
    if (this == &rhs)
        return (*this);
    this->_vec = rhs._vec;
    this->_unsortedVec = rhs._unsortedVec;
    return (*this);
}

PmergeMe::~PmergeMe( void ) {
    PRINT YELLOW "PmergeMe destroyed" CENDL;
}

bool    PmergeMe::add( char *number ) {
    str input = number;
    if (input.find_first_not_of("0123456789") != str::npos) {
        PRINT RED "Your numbers must only be in digit form & must be positive" CENDL;
        return (false);
    }

    int value = std::atol(number);
    if (value < 0) {
        PRINT RED "Your numbers must not be greater than Max Int" CENDL;
        return (false);
    }

    this->_vec.push_back(value);
    this->_unsortedVec.push_back(value);
    return (true);
}

void    PmergeMe::showVectors( void ) {
    NLINE;
    PRINT BLUE "Before Sorting: " BASE_COLOR;
    for (std::vector<int>::iterator it = this->_unsortedVec.begin(); it != this->_unsortedVec.end(); ++it)
        PRINT CYAN AND *it AND " " BASE_COLOR;
    NLINE;
    PRINT BLUE "After Sorting:  " BASE_COLOR;
    for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); ++it)
        PRINT CYAN AND *it AND " " BASE_COLOR;
    NLINE;
    NLINE;
}

void    PmergeMe::makePair( int level ) {
    int elRange = pow(2, level - 1);
    if ((unsigned long)elRange * 2 > this->_vec.size())
        return ;

    for (std::vector<int>::iterator it = this->_vec.begin() + elRange - 1; ; it += elRange * 2) {
        if (*it > *(it + elRange))
            std::swap_ranges(it - elRange + 1, it + 1, it + 1);
        if (std::distance(it, this->_vec.end()) <= elRange * 3)
            break ;
    }
    this->makePair(level + 1);
}
