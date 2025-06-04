/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/04 19:50:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

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
class   MutantStack : public std::stack<T> {
    public:
        MutantStack( void );
        MutantStack( cref(MutantStack) src );
        MutantStack &operator = ( cref(MutantStack) rhs ); 
        ~MutantStack( void );

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator    begin( void );
        iterator    end( void );
};

# include "MutantStack.tpp"

#endif //MUTANTSTACK_HPP
