/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:46:12 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/19 20:26:47 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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

class RPN {
    public:
        RPN( void );
        RPN( cref(RPN) src );
        RPN &operator = ( cref(RPN) rhs );
        ~RPN( void );

        std::stack<float>   getStack( void );

        void                popInStack( int number );
        bool                makeOperation( char sign );
        bool                checkStack( void );
    private:
        std::stack<float>   _stack;
};

#endif //RPN_HPP
