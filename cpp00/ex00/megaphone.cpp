/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:48:50 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/11 20:40:01 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	std::string string;

	if (argc == 1)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; argv[i]; i++)
			string += argv[i];
		for (std::string::iterator iter = string.begin(); iter != string.end(); iter++)
			*iter = std::toupper(*iter);
		std::cout << string << std::endl;
	}
	return (0);
}
