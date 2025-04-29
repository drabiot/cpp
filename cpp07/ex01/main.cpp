/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/22 23:18:38 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <cstring>

static void ft_toupper(ref(char) c);
static void ft_tolower(ref(char) c);

int main( void ) {
	char 		msg[] = "42 amogus SUS potions!";
	std::size_t	length = strlen(msg);

	::iter(msg, length, ft_toupper);
	PRINT msg ENDL;
	::iter(msg, length - 5, ft_tolower);
	PRINT msg ENDL;
}

static void ft_toupper(ref(char) c) {
	c = toupper(c);
}

static void ft_tolower(ref(char) c) {
	c = tolower(c);
}
