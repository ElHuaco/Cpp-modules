/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:48:30 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/19 11:38:22 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Instructions.hpp"

# define TAPE_SIZE 30000

static void	print(Instruction *inst)
{
	std::cout << inst->getName();
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
	std::cout << "Queue created..." << std::endl;
	for_each(instructionQueue.begin(), instructionQueue.end(), print);
	std::cout << std::endl;
	char	tape[TAPE_SIZE];
	char	*dataPtr = tape;
	std::deque<Instruction *>::iterator
		instructionPtr = instructionQueue.begin();
	std::cout << "Starting execution..." << std::endl;
	while (instructionPtr != instructionQueue.end())
	{
//		std::cout << "New iterarion" << std::endl;
		(*instructionPtr)->execute(&dataPtr);
		print(*instructionPtr);
		if ((dynamic_cast<SkipLoopExp *>(*instructionPtr) != nullptr)
			&& !(*dataPtr))
		{
//			std::cout << "Skipping loop..." << std::endl;
			while (dynamic_cast<RestartLoop *>(*instructionPtr) == nullptr)
				++instructionPtr;
			std::cout << std::endl;
		}
		if ((dynamic_cast<RestartLoop *>(*instructionPtr) != nullptr)
			&& (*dataPtr))
		{
//			std::cout << "Restarting loop..." << std::endl;
			while (dynamic_cast<SkipLoopExp *>(*instructionPtr) == nullptr)
				--instructionPtr;
			std::cout << std::endl;
		}
		++instructionPtr;
//		std::cout << "instructionPtr advanced and ready for next iteration." << std::endl;
	}
	return (EXIT_SUCCESS);
}
