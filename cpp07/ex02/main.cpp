/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/29 21:40:48 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(void)
{
    {
		Array<int>	test(10);

		test[0] = 0;
		test[1] = 1;

		PRINT CYAN AND test[0] CENDL;
		PRINT CYAN AND test[1] CENDL;
		try
		{
			test[-1];
		}
		catch (const std::exception &e)
		{
			ERROR RED "-1: " AND e.what() CENDL;
		}
        try
		{
			test[9];
		}
		catch(const std::exception& e)
		{
			ERROR RED "9: " AND e.what() CENDL;
		}
		try
		{
			test[10];
		}
		catch(const std::exception& e)
		{
			ERROR RED "10: " AND e.what() CENDL;
		}
		try
		{
			test[1000];
		}
		catch(const std::exception& e)
		{
			ERROR RED "1000: " AND e.what() CENDL;
		}
	}
	PRINT std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				ERROR RED AND "didn't sCave the same value!!" ENDL;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			ERROR RED AND e.what() CENDL;
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			ERROR RED AND e.what() CENDL;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
		return 0;
	}
}
