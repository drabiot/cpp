/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:18:23 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/03 03:27:09 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int jacobsthal(int n);

template <typename Container>
bool isSorted(const Container& c);

PmergeMe::PmergeMe( void ) {
    PRINT GREEN "PmergeMe created" CENDL;
    this->_vec.clear();
    this->_deq.clear();
    this->_unsorted.clear();
    this->_pend.clear();
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
    return (*this);
}

PmergeMe::~PmergeMe( void ) {
    PRINT YELLOW "PmergeMe destroyed" CENDL;
}

bool PmergeMe::add( char *number ) {
    std::string input(number);
    if (input.find_first_not_of("0123456789") != std::string::npos) {
        PRINT RED "Your numbers must only be in digit form & must be positive" CENDL;
        return false;
    }

    long value = std::atol(number);
    if (value < 0 || value > INT_MAX) {
        PRINT RED "Your numbers must not be greater than Max Int" CENDL;
        return false;
    }

    int intVal = static_cast<int>(value);
    this->_vec.push_back(intVal);
    this->_deq.push_back(intVal);
    this->_unsorted.push_back(intVal);
    return true;
}

void PmergeMe::showVectors( void ) const {
    NLINE;
    showTemplate(this->_unsorted, "Before");
    showTemplate(this->_vec, "After ");
    NLINE;
    if (isSorted(this->_vec) && isSorted(this->_deq))
        PRINT GREEN "Sorted" CENDL;
    else
        PRINT RED "Unsorted" CENDL;
    NLINE;
}

void PmergeMe::makePair(int level) {
    makePairTemplate(this->_vec, level);
    makePairTemplate(this->_deq, level);
}

template <typename Container>
void PmergeMe::makePairTemplate(Container& container, int level) {
    int elRange = static_cast<int>(std::pow(2.0, level - 1));
    size_t size = container.size();
    if (size < static_cast<size_t>(elRange * 2))
        return;

    for (size_t i = elRange - 1; i + elRange < size; i += elRange * 2) {
        if (container[i] > container[i + elRange]) {
            for (int j = 0; j < elRange; ++j) {
                std::swap(container[i - elRange + 1 + j], container[i + 1 + j]);
            }
        }
    }

    makePairTemplate(container, level + 1);
    this->sortLvl(container, elRange, level);
}

template <typename Container>
void PmergeMe::showTemplate(const Container& container, cref(std::string) label) const {
    PRINT BLUE AND label AND ": ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        PRINT CYAN AND *it AND ' ' AND BASE_COLOR;
    }
    NLINE;
}

template <typename Container>
void PmergeMe::sortLvl(Container& container, int elRange, int level) {
    initPend(container, elRange);
    insertPend(container, level);
}

template <typename Container>
void PmergeMe::initPend(Container& container, int elRange) {
    this->_pend.clear();

    if (container.empty() || elRange <= 0)
        return;

    typename Container::iterator begin = container.begin();
    typename Container::iterator end = container.end();
    int totalSize = std::distance(begin, end);
    int totalGroups = totalSize / elRange;

    if (totalGroups < 2) {
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
        }
        else {
            mainTemp.insert(mainTemp.end(), groupStart, it);
        }
        groupIndex++;
    }

    if (it != end) {
        mainTemp.insert(mainTemp.end(), it, end);
    }

    container.clear();
    container.insert(container.end(), mainTemp.begin(), mainTemp.end());
}

template <typename Container>
void PmergeMe::insertPend(Container &container, int level) {
    if (_pend.empty())
        return;

    int elRange = 1;
    for (int i = 0; i < level - 1; ++i)
        elRange *= 2;

    int totalGroups = static_cast<int>(_pend.size()) / elRange;

    int inserted = 0;
    int jacIndex = 2;
    int curJ = 3;
    int prevJ = 1;
    int Jdiff = curJ - prevJ;

    while (inserted < totalGroups) {
        if (totalGroups < curJ - 1) {
            for (; inserted < totalGroups; ++inserted) {
                typename Container::iterator insertPos = container.begin();
                int left = 0;
                int right = static_cast<int>(container.size()) / elRange;

                typename std::vector<int>::iterator pendIt = _pend.begin();
                std::advance(pendIt, (inserted + 1) * elRange - 1);
                int pendingVal = *pendIt;

                while (left < right) {
                    int mid = (left + right) / 2;
                    typename Container::iterator midIter = container.begin();
                    std::advance(midIter, (mid + 1) * elRange - 1);
                    if (pendingVal > *midIter)
                        left = mid + 1;
                    else
                        right = mid;
                }
                insertPos = container.begin();
                std::advance(insertPos, left * elRange);
                container.insert(insertPos, _pend.begin() + inserted * elRange, _pend.begin() + (inserted + 1) * elRange);
            }
            break;
        }

        std::vector<std::pair<int, int> > pairs;

        for (int i = 0; i < Jdiff; ++i) {
            int pendIdx = curJ - 1 - inserted - i + prevJ - 2;
            int boundIdx = pendIdx + inserted + 1;
            pairs.push_back(std::make_pair(pendIdx, boundIdx));
        }

        for (size_t i = 0; i < pairs.size(); ++i) {
            int pendIdx = pairs[i].first;
            int boundIdx = pairs[i].second;

            typename std::vector<int>::iterator pendIt = _pend.begin();
            std::advance(pendIt, (pendIdx + 1) * elRange - 1);
            int pendingVal = *pendIt;

            int insertPosIdx = 0;
            int left = 0;
            int right = boundIdx;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                typename Container::iterator midIter = container.begin();
                std::advance(midIter, (mid + 1) * elRange - 1);
                if (pendingVal > *midIter)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            insertPosIdx = left;

            int nbToUpdate = boundIdx - insertPosIdx + 1;

            for (size_t j = i + 1; j < pairs.size() && (j - i) <= static_cast<size_t>(nbToUpdate); ++j) {
                pairs[j].second++;
            }

            typename Container::iterator insertPos = container.begin();
            std::advance(insertPos, insertPosIdx * elRange);
            container.insert(insertPos, _pend.begin() + pendIdx * elRange, _pend.begin() + (pendIdx + 1) * elRange);
            ++inserted;
        }

        if (inserted > curJ - 2) {
            prevJ = curJ;
            jacIndex++;
            curJ = jacobsthal(jacIndex);
            Jdiff = curJ - prevJ;
        }
    }

    _pend.clear();
}

static int jacobsthal(int n) {
    if (n == 0 || n == 1)
        return n;
    int j0 = 0;
    int j1 = 1;
    int jn = 0;
    for (int i = 2; i <= n; ++i) {
        jn = j1 + 2 * j0;
        j0 = j1;
        j1 = jn;
    }
    return jn;
}

template <typename Container>
bool isSorted(const Container& c) {
    if (c.size() < 2)
        return true;

    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator next = it;
    ++next;

    while (next != c.end()) {
        if (*next < *it)
            return false;
        ++it;
        ++next;
    }
    return true;
}
