/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:18:23 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/28 00:00:59 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {
    PRINT GREEN "PmergeMe created" CENDL;
    this->_vec.clear();
    this->_deq.clear();
    this->_unsorted.clear();
    this->_pend.clear();
    this->_nonPart.clear();
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
    this->_deq = rhs._deq;
    this->_unsorted = rhs._unsorted;
    this->_pend = rhs._pend;
    this->_nonPart = rhs._nonPart;
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

    long value = std::atol(number);
    if (value < 0 || value > INT_MAX) {
        PRINT RED "Your numbers must not be greater than Max Int" CENDL;
        return (false);
    }

    this->_vec.push_back(static_cast<int>(value));
    this->_deq.push_back(static_cast<int>(value));
    this->_unsorted.push_back(static_cast<int>(value));
    return (true);
}

void PmergeMe::showVectors( void ) const {
    NLINE;
    showTemplate(this->_unsorted, "Before");
    showTemplate(this->_vec, "After ");
    NLINE;
}

void PmergeMe::makePair(int level) {
    makePairTemplate(this->_vec, level);
    makePairTemplate(this->_deq, level);
}

template <typename Container>
void PmergeMe::makePairTemplate( ref(Container) container, int level ) {
    int elRange = static_cast<int>(std::pow(2.0, level - 1));
    if (container.size() < static_cast<size_t>(elRange * 2))
        return;

    typename Container::iterator it = container.begin() + elRange - 1;
    while (true) {
        if (*it > *(it + elRange))
            std::swap_ranges(it - elRange + 1, it + 1, it + 1);
        if (std::distance(it, container.end()) <= elRange * 3)
            break;
        it += elRange * 2;
    }
    makePairTemplate(container, level + 1);
    sortLvl(container, elRange, level);
}

template <typename Container>
void    PmergeMe::showTemplate( const Container container, cref(str) label ) const {
    PRINT BLUE AND label AND ": ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        PRINT CYAN AND *it AND ' ' AND BASE_COLOR;
    NLINE;
}

template <typename Container>
void    PmergeMe::sortLvl( ref(Container) container, int elRange, int level ) {
    //Container tmpContainer = container;

    initPend(container, elRange);
    showTemplate(container, "main");
    showTemplate(this->_pend, "pend");
    showTemplate(this->_nonPart, "non participating");
    NLINE;
    insertPend(container, level);
}

template <typename Container>
void    PmergeMe::initPend( ref(Container) container, int elRange ) {
    this->_pend.clear();
    this->_nonPart.clear();

    if (container.empty() || elRange <= 0)
        return;

    typename Container::iterator begin = container.begin();
    typename Container::iterator end = container.end();
    int totalSize = std::distance(begin, end);
    int totalGroups = totalSize / elRange;

    if (totalGroups < 2) {
        this->_nonPart.insert(this->_nonPart.end(), begin, end);
        container.clear();
        return;
    }

    typename Container::iterator it = begin;
    Container mainTemp;
    typename Container::iterator groupStart = it;
    std::advance(it, elRange);
    mainTemp.insert(mainTemp.end(), groupStart, it);
    groupStart = it;
    std::advance(it, elRange);
    mainTemp.insert(mainTemp.end(), groupStart, it);

    int groupIndex = 2;
    while (std::distance(it, end) >= elRange) {
        groupStart = it;
        std::advance(it, elRange);

        if (groupIndex % 2 == 0) {
            this->_pend.insert(this->_pend.end(), groupStart, it);
        } else {
            mainTemp.insert(mainTemp.end(), groupStart, it);
        }
        groupIndex++;
    }
    if (it != end)
        this->_nonPart.insert(this->_nonPart.end(), it, end);

    container.clear();
    container.insert(container.end(), mainTemp.begin(), mainTemp.end());
}

template <typename Container>
void PmergeMe::insertPend( ref(Container) container, int level ) {
    (void)level;

    if (_pend.empty())
        return;

    static const size_t jacobsthal[] = {
        0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461
    };

    (void)container;
    (void)jacobsthal;
}
