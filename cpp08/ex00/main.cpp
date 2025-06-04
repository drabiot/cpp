/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/05 00:56:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

int main( void ) {
	NLINE;
	PRINT GREEN "Vector test:" CENDL;
	{
		std::vector<int>	intVector;

		intVector.push_back(-10);
		intVector.push_back(0);
		intVector.push_back(10);
		intVector.push_back(42);
		intVector.push_back(64);
		intVector.push_back(14752);
		intVector.push_back(-5482);
		intVector.push_back(6);
		intVector.push_back(142);
		intVector.push_back(69);
		intVector.push_back(47);
		intVector.push_back(31);
		intVector.push_back(32472);
		intVector.push_back(24);

		easyfind(intVector, 14752);
		easyfind(intVector, -10);
		easyfind(intVector, 100);
		easyfind(intVector, 24);
	}
	NLINE;
	PRINT GREEN "Deque test:" CENDL;
	{
		std::deque<int>	intDeque;

		intDeque.push_back(-10);
		intDeque.push_back(0);
		intDeque.push_back(10);
		intDeque.push_back(42);
		intDeque.push_back(64);
		intDeque.push_back(14752);
		intDeque.push_back(-5482);
		intDeque.push_back(6);
		intDeque.push_back(142);
		intDeque.push_back(69);
		intDeque.push_back(47);
		intDeque.push_back(31);
		intDeque.push_back(32472);
		intDeque.push_back(24);

		easyfind(intDeque, 14752);
		easyfind(intDeque, -10);
		easyfind(intDeque, 100);
		easyfind(intDeque, 24);
	}
	NLINE;
	PRINT GREEN "List test:" CENDL;
	{
		std::list<int>	intList;

		intList.push_back(-10);
		intList.push_back(0);
		intList.push_back(10);
		intList.push_back(42);
		intList.push_back(64);
		intList.push_back(14752);
		intList.push_back(-5482);
		intList.push_back(6);
		intList.push_back(142);
		intList.push_back(69);
		intList.push_back(47);
		intList.push_back(31);
		intList.push_back(32472);
		intList.push_back(24);

		easyfind(intList, 14752);
		easyfind(intList, -10);
		easyfind(intList, 100);
		easyfind(intList, 24);
	}
	NLINE;
	PRINT GREEN "Stack test:" CENDL;
	{
		std::stack<int>	intStack;

		intStack.push(-10);
		intStack.push(0);
		intStack.push(10);
		intStack.push(42);
		intStack.push(64);
		intStack.push(14752);
		intStack.push(-5482);
		intStack.push(6);
		intStack.push(142);
		intStack.push(69);
		intStack.push(47);
		intStack.push(31);
		intStack.push(32472);
		intStack.push(24);

		easyfind(intStack, 14752);
		easyfind(intStack, -10);
		easyfind(intStack, 100);
		easyfind(intStack, 24);
	}
	NLINE;
	PRINT GREEN "Queue test:" CENDL;
	{
		std::queue<int>	intQueue;
	
		intQueue.push(-10);
		intQueue.push(0);
		intQueue.push(10);
		intQueue.push(42);
		intQueue.push(64);
		intQueue.push(14752);
		intQueue.push(-5482);
		intQueue.push(6);
		intQueue.push(142);
		intQueue.push(69);
		intQueue.push(47);
		intQueue.push(31);
		intQueue.push(32472);
		intQueue.push(24);

		easyfind(intQueue, 14752);
		easyfind(intQueue, -10);
		easyfind(intQueue, 100);
		easyfind(intQueue, 24);
	}
	NLINE;
	PRINT GREEN "Priority Queue test:" CENDL;
	{
		std::priority_queue<int>	intPQueue;

		intPQueue.push(-10);
		intPQueue.push(0);
		intPQueue.push(10);
		intPQueue.push(42);
		intPQueue.push(64);
		intPQueue.push(14752);
		intPQueue.push(-5482);
		intPQueue.push(6);
		intPQueue.push(142);
		intPQueue.push(69);
		intPQueue.push(47);
		intPQueue.push(31);
		intPQueue.push(32472);
		intPQueue.push(24);

		easyfind(intPQueue, 14752);
		easyfind(intPQueue, -10);
		easyfind(intPQueue, 100);
		easyfind(intPQueue, 24);
	}
	return 0;
}
