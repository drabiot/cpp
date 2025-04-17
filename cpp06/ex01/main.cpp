/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 13:31:40 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

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

		data->data = -4764338;
		PRINT CYAN AND "Data before serialization: " MAGENTA AND data->data CENDL;
		intptr = Serializer::serialize(data);
		PRINT YELLOW "Serialize data: " RED AND intptr CENDL;
		PRINT CYAN "Data after serialization: " MAGENTA AND Serializer::deserialize(intptr)->data CENDL;
		delete data;
	}
}
