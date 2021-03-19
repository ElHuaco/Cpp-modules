/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:48:30 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/19 13:17:37 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Instructions.hpp"

# define TAPE_SIZE 30000

static void	CheckSkipLoop(std::deque<Instruction *>::iterator &instructionPtr)
{
	int		nestedLevel = 0;
	++instructionPtr;
	while (((*instructionPtr)->getName() != "]") || (nestedLevel))
	{
		if ((*instructionPtr)->getName() == "[")
			++nestedLevel;
		else if ((*instructionPtr)->getName() == "]")
			--nestedLevel;
		++instructionPtr;
	}
	return;
}

static void	CheckRestartLoop(std::deque<Instruction *>::iterator &instructionPtr)
{
	int		nestedLevel = 0;
	--instructionPtr;
	while (((*instructionPtr)->getName() != "[") || (nestedLevel))
	{
		if ((*instructionPtr)->getName() == "]")
			++nestedLevel;
		else if ((*instructionPtr)->getName() == "[")
			--nestedLevel;
		--instructionPtr;
	}
	return;
}
int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "MindOpen: Error. Wrong argument count." << std::endl;
		return (EXIT_FAILURE);
	}
	std::string		filename(argv[1]);
	if (filename.size() == 0)
	{
		std::cerr << "MindOpen: Error. Filename must not be empty." << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream	inputfile(filename);
	if (inputfile.good() == false)
	{
		std::cerr << "MindOpen: Error. I/O operation failed." << std::endl;
		return (EXIT_FAILURE);
	}
	typedef Instruction	*(*instructionConstArray)(void);
	instructionConstArray instructionConstructor[] = {
		&CreateIncAdd, &CreateIncVal, &CreateDecAdd, &CreateDecVal,
		&CreateOutput, &CreateSkipLoop, &CreateRestartLoop, &CreateStore};
	char instructionChar[] = {
		'>', '+', '<', '-',
		'.', '[', ']', ','};
	std::deque<Instruction *> instructionQueue;
	while (inputfile.peek() != EOF)
	{
		for (unsigned int i = 0; i < 8; i++)
		{
			if (static_cast<char>(inputfile.peek()) == instructionChar[i])
			{
				instructionQueue.push_back(instructionConstructor[i]());
				break;
			}
		}
		inputfile.get();
	}
	inputfile.close();
	char	tape[TAPE_SIZE];
	char	*dataPtr = tape;
	std::deque<Instruction *>::iterator
		instructionPtr = instructionQueue.begin();
	while (instructionPtr != instructionQueue.end())
	{
		(*instructionPtr)->execute(&dataPtr);
		if (((*instructionPtr)->getName() == "[") && !(*dataPtr))
			CheckSkipLoop(instructionPtr);
		if (((*instructionPtr)->getName() == "]") && (*dataPtr))
			CheckRestartLoop(instructionPtr);
		++instructionPtr;
	}
	return (EXIT_SUCCESS);
}
