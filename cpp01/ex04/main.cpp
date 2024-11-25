/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:53:39 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/25 23:49:35 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED "3 arguments needed: <filename> <s1> <s2>" BASE_COLOR << std::endl;
		return (1);
	}
	try {
		Sed	data(argv[1], argv[2], argv[3]);
		data.startSed();
	}
	catch (std::exception &e){
		std::cerr << RED << e.what() << BASE_COLOR << std::endl;
		return (2);
	}
	return (0);
}
