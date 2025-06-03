/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/03 15:19:48 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <exception>
# include <climits>
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

class Span {
    public:
        Span( unsigned int N );
        Span( cref(Span) src );
        Span &operator = ( cref(Span) rhs );
        ~Span( void );

        void    addNumber( int newNumber );
        void    addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end );

        int     shortestSpan( void );
        int     longestSpan( void );
    private:
        unsigned int        _size;
        std::vector<int>    _vec;
};

#endif //SPAN_HPP
