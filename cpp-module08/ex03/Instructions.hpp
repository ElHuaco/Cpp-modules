/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:56:03 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/19 11:04:17 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP

# include <vector>
# include <algorithm>
# include <string>
# include <iostream>

class Instruction
{
	private:
		std::string		_name;
	public:
		std::string		getName(void) const {return (this->_name);}
		void			setName(std::string const &name) {this->_name = name; return;}
		virtual ~Instruction(void) {return;}
		virtual void	execute(char **dataPtr) const = 0;
};

class IncrementAddress : public Instruction
{
	private:
		IncrementAddress(IncrementAddress const &other);
		IncrementAddress	&operator=(IncrementAddress const &rhs);

	public:
		IncrementAddress(void) {this->setName(">"); return; }
		virtual ~IncrementAddress(void) {return;}

		virtual void	execute(char **dataPtr) const
		{
			++(*dataPtr);
			return;
		}
};

class IncrementValue : public Instruction
{
	private:
		IncrementValue(IncrementValue const &other);
		IncrementValue	&operator=(IncrementValue const &rhs);

	public:
		IncrementValue(void) {this->setName("+"); return; }
		virtual ~IncrementValue(void) {return;}

		virtual void	execute(char **dataPtr) const
		{
			++(**dataPtr);
			return;
		}
};

class DecrementAddress : public Instruction
{
	private:
		DecrementAddress(DecrementAddress const &other);
		DecrementAddress	&operator=(DecrementAddress const &rhs);

	public:
		DecrementAddress(void) {this->setName("<"); return; }
		virtual ~DecrementAddress(void) {return;}

		virtual void	execute(char **dataPtr) const
		{
			--(*dataPtr);
			return;
		}
};

class DecrementValue : public Instruction
{
	private:
		DecrementValue(DecrementValue const &other);
		DecrementValue	&operator=(DecrementValue const &rhs);

	public:
		DecrementValue(void) {this->setName("-"); return; }
		virtual ~DecrementValue(void) {return;}

		virtual void	execute(char **dataPtr) const
		{
			--(**dataPtr);
			return;
		}
};

class OutputAddressValue : public Instruction
{
	private:
		OutputAddressValue(OutputAddressValue const &other);
		OutputAddressValue	&operator=(OutputAddressValue const &rhs);

	public:
		OutputAddressValue(void) {this->setName("."); return; }
		virtual ~OutputAddressValue(void) {return;}

		virtual void	execute(char **dataPtr) const
		{
			std::cout << **dataPtr;
			return;
		}
};

class SkipLoopExp : public Instruction
{
	private:
		SkipLoopExp(SkipLoopExp const &other);
		SkipLoopExp	&operator=(SkipLoopExp const &rhs);

	public:
		SkipLoopExp(void) {this->setName("["); return; }
		virtual ~SkipLoopExp(void) {return;}

		virtual void	execute(char **dataPtr) const
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
		RestartLoop(void) {this->setName("]"); return; }
		virtual ~RestartLoop(void) {return;}

		virtual void	execute(char **dataPtr) const
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
		StoreValue(void) {this->setName(","); return; }
		virtual ~StoreValue(void) {return;}

		virtual void	execute(char **dataPtr) const
		{
			std::cin >> **dataPtr;
			return;
		}
};

Instruction		*CreateIncVal(void)
{
	return (new class IncrementValue);
}

Instruction		*CreateDecVal(void)
{
	return (new class DecrementValue);
}

Instruction		*CreateIncAdd(void)
{
	return (new class IncrementAddress);
}

Instruction		*CreateDecAdd(void)
{
	return (new class DecrementAddress);
}

Instruction		*CreateOutput(void)
{
	return (new class OutputAddressValue);
}

Instruction		*CreateSkipLoop(void)
{
	return (new class SkipLoopExp);
}

Instruction		*CreateRestartLoop(void)
{
	return (new class RestartLoop);
}

Instruction		*CreateStore(void)
{
	return (new class StoreValue);
}
#endif
