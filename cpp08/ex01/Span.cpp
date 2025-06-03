/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:17:20 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/03 15:24:40 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int N ) {
    this->_size = N;
    PRINT GREEN "Create a list that contains " MAGENTA AND N AND GREEN " numbers" CENDL;
}

Span::Span( cref(Span) src ) {
    *this = src;
    PRINT GREEN "Span Copy constructor operator called" CENDL;
}

Span &Span::operator = ( cref(Span) rhs ) {
    PRINT GREEN "Span Copy assignment operator called" CENDL;
	if (this == &rhs)
		return (*this);
	this->_size = rhs._size;
    this->_vec = rhs._vec;
	return (*this);
}

Span::~Span( void ) {
    PRINT RED "Destroy the list" CENDL;
}

void    Span::addNumber( int newNumber ) {
    if (this->_size <= this->_vec.size())
        throw std::out_of_range("List already full");
    else {
        this->_vec.push_back(newNumber);
    }

}

void    Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
    (void)begin;
    (void)end;
}

int     Span::shortestSpan( void ) {
    std::vector<int> tmp = this->_vec;
    std::sort(tmp.begin(), tmp.end());

    int shortestSpan = INT_MAX;
    
    if (this->_vec.size() >= 2) {
        for (size_t i = 0; i < this->_vec.size() - 1; ++i) {
            int testingSpan = tmp.at(i + 1) - tmp.at(i);
            if (testingSpan < shortestSpan)
                shortestSpan = testingSpan;
        }
        return (shortestSpan);
    }
    else
        throw std::runtime_error("Not enough numbers to calcutate the Shortest Span");
}

int     Span::longestSpan( void ) {
    std::vector<int> tmp = this->_vec;
    std::sort(tmp.begin(), tmp.end());

    if (this->_vec.size() >= 2) {
        return (tmp.at(tmp.size() - 1) - tmp.at(0));
    }
    else
        throw std::runtime_error("Not enough numbers to calcutate the Longest Span");
}
