/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:48:30 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 17:27:16 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include "Instruction.hpp"
#include "IncrementAddress.hpp"
#include "IncrementValue.hpp"
#include "DecrementAddress.hpp"
#include "DecrementValue.hpp"
#include "OutputAddressValue.hpp"
#include "SkipLoopExp.hpp"
#include "RestartLoop.hpp"
#include "StoreValue.hpp"

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
	std::string	buff = "";
	inputfile.ignore(std::numeric_limits<std::streamsize>::max());//extracts max chars
	std::streamsize filelength = inputfile.gcount(); //Nº char last input operation
	inputfile.clear();   //Since ignore will have set eof.
	inputfile.seekg(0, std::ios_base::beg);//Next char extracted will be at beggining
	if (filelength > buff.max_size())
	{
		std::cerr << "MindOpen: Error. Maximum file size exceeded by ";
		std::cerr << filelength - buff.max_size() << " bytes." << std::endl;
		return (EXIT_FAILURE);
	}
	else
		while (inputfile.peek() != EOF)
			buff += static_cast<char>(inputfile.get());
// Cómo mover el ptr de instrucciones?
// Parseo?
// Cómo se va modificando la ristra de 0s?
// Descifrar instrucciones y guardarlas en la queue.
//	std::queue<Instruction> instructionQueue;
	inputfile.close();
// Ejecutar cada instrucción en la cola.
//	std::vector<char> tape(TAPE_SIZE, 0);

	return (EXIT_SUCCESS);
}
