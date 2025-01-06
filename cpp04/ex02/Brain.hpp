/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:42:46 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 20:28:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "color.hpp"
# include <iostream>

class Brain {
public:
	Brain( void );
	Brain( const Brain &src );
	Brain &operator = ( const Brain &rhs );
	~Brain( void );
private:
	std::string _ideas[100];
};

#endif //BRAIN_HPP
