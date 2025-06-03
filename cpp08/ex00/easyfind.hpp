/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/03 14:08:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
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

template <typename T>
typename T::iterator easyfind(cref(T) list, int value) {
    typename T::iterator toFind = std::find(list.begin(), list.end(), value);
    
    if (toFind != list.end())
        PRINT BLUE AND value AND CYAN " is in the given list" CENDL;
    else
        ERROR RED AND value AND MAGENTA " isn't in the given list" CENDL;
    return (toFind);
}

template <typename T>
typename T::iterator easyfind(ref(T) list, int value) {
    typename T::iterator toFind = std::find(list.begin(), list.end(), value);

    if (toFind != list.end())
        PRINT BLUE AND value AND CYAN " is in the given list" CENDL;
    else
        ERROR RED AND value AND MAGENTA " isn't in the given list" CENDL;
    return (toFind);
}

#endif //EASYFIND_HPP
