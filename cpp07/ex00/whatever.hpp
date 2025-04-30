/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/30 21:52:32 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>
# include <string>
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
cref(T) max(cref(T) x, cref(T) y) {
    return (x > y) ? x : y;
}

template <typename T>
ref(T) max(ref(T) x, ref(T) y) {
    return (x > y) ? x : y;
}

template <typename T>
cref(T) min(cref(T) x, cref(T) y) {
    return (x < y) ? x : y;
}

template <typename T>
ref(T) min(ref(T) x, ref(T) y) {
    return (x < y) ? x : y;
}

template <typename T>
void swap(ref(T) x, ref(T) y) {
	T	tmp = x;

	x = y;
	y = tmp;
}

#endif //TEMPLATE_HPP
