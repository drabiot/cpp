/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/29 21:22:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <exception>
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
class Array {
public:
    Array( void );
    Array( unsigned int n );
    Array( cref(Array) src );
    Array &operator = ( cref(Array) rhs );
    ~Array( void );

    unsigned int    size( void ) const;

    T &operator [] (unsigned int index);
    const T &operator [] (unsigned int index) const;
private:
    T*              _array;
    unsigned int    _size;

    class outOfRangeException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of range in the array!";
        }
    };
};

template <typename T>
std::ostream	&operator<<(std::ostream &out, Array<T> &in);

#include "Array.tpp"

#endif //ITER_HPP
