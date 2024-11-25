/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:09:25 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/25 23:41:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string.h>

# define BASE_COLOR	"\033[0m"
# define GRAY 		"\033[0;90m"
# define RED 		"\033[0;91m"
# define GREEN 		"\033[0;92m"
# define YELLOW 	"\033[0;93m"
# define BLUE 		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN 		"\033[0;96m"
# define WHITE		"\033[0;97m"

class	Sed {
public:
	Sed(const std::string &filename, const std::string &s1, const std::string &s2);	// Constructor
	~Sed(void);																		// Destructor

	void			startSed(void);
private:
	std::ifstream	_infile;
	std::ofstream	_outfile;
	std::string		_seek;
	std::string		_replace;
	std::string		_content;

	void			readLine(void);
	void			modifyContent(void);
	void			writeLine(void);
};

#endif //SED_HPP