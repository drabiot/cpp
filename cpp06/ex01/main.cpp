/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 15:13:25 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	{
		t_data		*data = new t_data;
		uintptr_t	intptr;

		data->data = 42;
		PRINT CYAN AND "Data before serialization: " MAGENTA AND data->data CENDL;
		intptr = Serializer::serialize(data);
		PRINT YELLOW "Serialize data: " RED AND intptr CENDL;
		PRINT CYAN "Data after serialization: " MAGENTA AND Serializer::deserialize(intptr)->data CENDL;
		delete data;
	}
	{
		t_data		*data = new t_data;
		uintptr_t	intptr;

		std::srand(std::time(NULL));
		data->data = std::rand() % 42000;
		PRINT CYAN AND "Data before serialization: " MAGENTA AND data->data CENDL;
		intptr = Serializer::serialize(data);
		PRINT YELLOW "Serialize data: " RED AND intptr CENDL;
		PRINT CYAN "Data after serialization: " MAGENTA AND Serializer::deserialize(intptr)->data CENDL;
		delete data;
	}
}
