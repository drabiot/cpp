/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:46:12 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/24 17:44:40 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <climits>
# include <cmath>
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

class PmergeMe {
    public:
        PmergeMe( void );
        PmergeMe( cref(PmergeMe) src );
        PmergeMe &operator = ( cref(PmergeMe) rhs );
        ~PmergeMe( void );

        bool    add( char *number );
        void    showVectors( void );

        void    makePair( int level );
    private:
        std::vector<int>    _unsortedVec;
        std::vector<int>    _vec;
};

#endif //PMERGEME_HPP
