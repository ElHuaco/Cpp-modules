/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:12:53 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 14:28:36 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <limits>

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "replace: Error. Wrong argument count." << std::endl;
		return (1);
	}
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (!s1.size() || !s2.size())
	{
		std::cerr << "replace: Error. Strings must not be empty." << std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	if (!filename.size())
	{
		std::cerr << "replace: Error. Filename must not be empty." << std::endl;
		return (1);
	}
	std::ifstream	inputfile(filename);
	if (inputfile.good() == false)
	{
		std::cerr << "replace: Error. I/O operation failed." << std::endl;
		return (1);
	}
	std::string	buff;
	inputfile.ignore(std::numeric_limits<std::streamsize>::max());//extracts max chars
	std::streamsize filelength = inputfile.gcount(); //Nº char last input operation
	inputfile.clear();   //Since ignore will have set eof.
	inputfile.seekg(0, std::ios_base::beg);//Next char extracted will be at beggining
	if (filelength > buff.max_size())
	{
		std::cerr << "replace: Error. Maximum file size exceeded by ";
		std::cerr << filelength - buff.max_size() << " bytes." << std::endl;
		return (1);
	}
	else
		inputfile >> buff;
	std::string::size_type pos = 0;
	//Qid del asunto
	while ((pos = buff.find(s1, pos)))
		buff.replace(buff.begin() + pos, buff.begin() + pos + s2.size(), s2);
	std::ofstream	outputfile(filename + ".replace");
	if (outputfile.good() == false)
	{
		std::cerr << "replace: Error. I/O operation failed." << std::endl;
		return (1);
	}
	outputfile << buff;
	return (0);
}
