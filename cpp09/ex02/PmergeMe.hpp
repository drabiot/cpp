/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:46:12 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/07 20:45:24 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <ctime>
# include "color.hpp"

# include <vector>
# include <deque>
# include <utility>

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
        PmergeMe& operator=( cref(PmergeMe) rhs );
        ~PmergeMe();

        bool    add( char* number );
        void    showVectors( double vecTime, double deqTime ) const;
        void    makePair( int level, struct timespec *vecStart, struct timespec *deqStart, struct timespec *vecEnd, struct timespec *deqEnd );

    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;

        std::vector<int>    _unsorted;

        std::vector<int>    _pend;

        template <typename Container>
        void    makePairTemplate( ref(Container) container, int level );

        template <typename Container>
        void    showTemplate( cref(Container) container, cref(std::string) label) const;

        template <typename Container>
        void    sortLvl( ref(Container) container, int elRange, int level );

        template <typename Container>
        void    initPend( ref(Container) container, int elRange );

        template <typename Container>
        void    insertPend( ref(Container) container, int level );
};

#endif //PMERGEME_HPP
