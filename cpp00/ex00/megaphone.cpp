/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:48:50 by tchartie          #+#    #+#             */
/*   Updated: 2024/07/27 07:48:50 by tchartie         ###   ########.fr       */
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
        for (size_t j = 1; string[j]; j++)
            string[j] = std::toupper(string[j]);
        std::cout << string << std::endl;
    }
    return (0);
}