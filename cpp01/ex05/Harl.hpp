/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:45:20 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 02:14:00 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define BASE_COLOR	"\033[0m"
# define GRAY 		"\033[0;90m"
# define RED 		"\033[0;91m"
# define GREEN 		"\033[0;92m"
# define YELLOW 	"\033[0;93m"
# define BLUE 		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN 		"\033[0;96m"
# define WHITE		"\033[0;97m"

class	Harl {
public:
	Harl( void );	// Constructor
	~Harl( void );	// Destructor

	void	complain( std::string level );
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	void	incorrect( void );
	
	void	(Harl::*_pfnMessage[5])();
	
};

#endif //HARL_HPP
