/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:56:03 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 19:03:46 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP

# include <vector>
# include <algorithm>

class Instruction
{
	public:
		virtual void	execute(std::vector<char>::iterator &dataPtr) const = 0;
}

class IncrementAddress : public Instruction
{
	private:
		IncrementAddress(IncrementAddress const &other);
		IncrementAddress	&operator=(IncrementAddress const &rhs);

	public:
		IncrementAddress(void) {return;}
		virtual ~IncrementAddress(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			++dataPtr;
			return;
		}
};

class IncrementValue : public Instruction
{
	private:
		IncrementValue(IncrementValue const &other);
		IncrementValue	&operator=(IncrementValue const &rhs);

	public:
		IncrementValue(void) {return;}
		virtual ~IncrementValue(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			++(*dataPtr);
			return;
		}
};

class DecrementAddress : public Instruction
{
	private:
		DecrementAddress(DecrementAddress const &other);
		DecrementAddress	&operator=(DecrementAddress const &rhs);

	public:
		DecrementAddress(void) {return;}
		virtual ~DecrementAddress(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			--dataPtr;
			return;
		}
};

class DecrementValue : public Instruction
{
	private:
		DecrementValue(DecrementValue const &other);
		DecrementValue	&operator=(DecrementValue const &rhs);

	public:
		DecrementValue(void) {return;}
		virtual ~DecrementValue(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			--(*dataPtr);
			return;
		}
};

class OutputAddressValue : public Instruction
{
	private:
		OutputAddressValue(OutputAddressValue const &other);
		OutputAddressValue	&operator=(OutputAddressValue const &rhs);

	public:
		OutputAddressValue(void) {return;}
		virtual ~OutputAddressValue(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			std::cout << static_cast<char>(*dataPtr) << std::endl;
			return;
		}
};

class SkipLoopExp : public Instruction
{
	private:
		SkipLoopExp(SkipLoopExp const &other);
		SkipLoopExp	&operator=(SkipLoopExp const &rhs);

	public:
		SkipLoopExp(void) {return;}
		virtual ~SkipLoopExp(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			return;
		}
};

class RestartLoop : public Instruction
{
	private:
		RestartLoop(RestartLoop const &other);
		RestartLoop	&operator=(RestartLoop const &rhs);

	public:
		RestartLoop(void) {return;}
		virtual ~RestartLoop(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			return;
		}
};

class StoreValue : public Instruction
{
	private:
		StoreValue(StoreValue const &other);
		StoreValue	&operator=(StoreValue const &rhs);

	public:
		StoreValue(void) {return;}
		virtual ~StoreValue(void) {return;}

		virtual void	execute(std::vector<char>::iterator &dataPtr) const
		{
			return;
		}
};
#endif
