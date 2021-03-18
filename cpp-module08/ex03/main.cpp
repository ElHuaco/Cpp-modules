/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:48:30 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 19:04:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Instructions.hpp"
#include "InstructionConstArray.hpp"

# define TAPE_SIZE 30000

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
	typedef Instruction	*(&instructionConstArray)(void);
	instructionConstArray instructionConstructor[] = {
		&CreateIncAdd, &CreateIncVal, &CreateDecAdd, &CreateDecVal,
		&CreateOutput, &CreateSkipLoop, &CreateRestartLoop, &CreateStore};
	char instructionChar[] = {
		">", "+", "<", "-",
		".", "[", "]", ","};
	std::queue<Instruction> instructionQueue;
	while (inputfile.peek() != EOF)
	{
		for (unsigned int i = 0; i < 8; i++)
		{
			if (static_cast<char>(inputfile.peek()) == instructionChar[i])
			{
				instructionQueue.push(*instructionConstructor[i]());
				break;
			}
		}
		inputfile.get();
	}
	inputfile.close();
	std::vector<char> tape(TAPE_SIZE, 0);
	std::vector<char>::iterator dataPtr = tape.begin();
	std::queue<Instruction>::const_iterator instructionPtr = instructionQueue.begin();
	while (instructionPtr != instructionQueue.end())
	{
		instructionPtr->execute(ptr);
		if (dynamic_cast<SkipLoopExp *>(instructionPtr) != nullptr
			&& !(*dataPtr))
		{
			while (dynamic_cast<RestartLoop *>(instructionPtr) == nullptr)
				++instructionPtr;
		}
		if (dynamic_cast<RestartLoop *>(instructionPtr) != nullptr
			&& (*dataPtr))
		{
			while (dynamic_cast<SkipLoopExp *>(instructionPtr) == nullptr)
				--instructionPtr;
		}
		++instructionPtr;
	}
	return (EXIT_SUCCESS);
}
// Cómo mover el ptr de instrucciones?
//  -> Esto es simplemente avanzar en la queue
// Parseo?
//  -> Se ignoran chars no del lenguaje
// Descifrar instrucciones y guardarlas en la queue.

