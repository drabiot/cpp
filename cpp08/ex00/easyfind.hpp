/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/05 00:54:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <stack>
# include <queue>
# include "color.hpp"

# define AND	<<
# define PRINT	std::cout AND
# define ERROR	std::cerr AND
# define NLINE	PRINT std::endl
# define ENDL	AND std::endl
# define CENDL	AND BASE_COLOR ENDL
# define TAB	"\t"

typedef std::string str;

# define cref(type) const type &
# define ref(type) type &


/*
 * Utility: Vector,Deque,list
 * Return:  Iterator
 */
template <typename T>
typename T::iterator easyfind(cref(T) list, int value) {
    typename T::iterator toFind = std::find(list.begin(), list.end(), value);
    
    if (toFind != list.end())
        PRINT BLUE AND value AND CYAN " is in the given list" CENDL;
    else
        ERROR RED AND value AND MAGENTA " isn't in the given list" CENDL;
    return (toFind);
}

/*
 * Utility: Vector,Deque,list
 * Return:  Iterator
 */
template <typename T>
typename T::iterator easyfind(ref(T) list, int value) {
    typename T::iterator toFind = std::find(list.begin(), list.end(), value);

    if (toFind != list.end())
        PRINT BLUE AND value AND CYAN " is in the given list" CENDL;
    else
        ERROR RED AND value AND MAGENTA " isn't in the given list" CENDL;
    return (toFind);
}

/*
 * Utility: Stack
 * Return:  Bool
 */
template <typename T, typename Container>
bool    easyfind(const std::stack<T, Container>& s, int value) {
    for (std::stack<T, Container> copy = s; !copy.empty(); copy.pop()) {
        if (copy.top() == value) {
            PRINT BLUE AND value AND CYAN " is in the given list" CENDL;
            return true;
        }
    }
   ERROR RED AND value AND MAGENTA " isn't in the given list" CENDL;
    return false;
}

/*
 * Utility: Queue
 * Return:  Bool
 */
template <typename T, typename Container>
bool    easyfind(const std::queue<T, Container>& q, int value) {
    for (std::queue<T, Container> copy = q; !copy.empty(); copy.pop()) {
        if (copy.front() == value) {
            PRINT BLUE AND value AND CYAN " is in the given list" CENDL;
            return true;
        }
    }
    ERROR RED AND value AND MAGENTA " isn't in the given list" CENDL;
    return false;
}

/*
 * Utility: Priority Queue
 * Return:  Bool
 */
template <typename T, typename Container, typename Compare>
bool    easyfind(const std::priority_queue<T, Container, Compare>& pq, int value) {
    for (std::priority_queue<T, Container, Compare> copy = pq; !copy.empty(); copy.pop()) {
        if (copy.top() == value) {
            PRINT BLUE AND value AND CYAN " is in the given list" CENDL;
            return true;
        }
    }
    ERROR RED AND value AND MAGENTA " isn't in the given list" CENDL;
    return false;
}

#endif //EASYFIND_HPP
