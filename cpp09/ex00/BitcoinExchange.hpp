/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 05:07:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/17 17:05:48 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <map>
# include <sstream>
# include <fstream>
# include <exception>
# include <ctime>
# include <cstring>
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

class BitcoinExchange {
    public:
        BitcoinExchange( void );
        BitcoinExchange( cref(BitcoinExchange) src );
        BitcoinExchange &operator = ( cref(BitcoinExchange) rhs );
        ~BitcoinExchange( void );

        std::map<std::time_t, float>    getBitcoinValue( void );

        bool    parseLine( cref(str) line, ref(std::time_t) date, ref(float) value );
        int     parseInput( cref(str) line, ref(str) dateFormat, ref(std::time_t) date, ref(float) value );
        str     dateFormat( std::time_t date );
        float   searchPrice( std::time_t date );   
        void    run( char *data );
    private:
        std::map<std::time_t, float> _bitcoinValue;
};

#endif //BITCOINEXCHANGE_HPP