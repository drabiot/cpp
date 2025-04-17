/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:15:46 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 15:42:10 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "color.hpp"

# define ERROR	std::cerr <<
# define PRINT	std::cout <<
# define AND	<<
# define ENDL	<< std::endl
# define CENDL	<< BASE_COLOR << std::endl
# define TAB	"\t"

class Base {
	public:
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif //BASE_HPP
