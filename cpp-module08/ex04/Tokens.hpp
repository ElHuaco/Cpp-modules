/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tokens.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:30:31 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/20 11:52:42 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_HPP
# define TOKENS_HPP

#include <string>

class	Token
{
	private:
		std::string		_type;
		Token(void);
	public:
		Token(std::string const &type) : _type(type) {return;}
		Token(Token const &other) {*this = other; return;}
		virtual ~Token(void) {return;}
		Token	&operator=(Token const &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->_type = rhs._type;
			return (*this);
		}

		std::string		getType(void) const {return (this->_type);}
};

class	Operand : public Token
{
	private:
		int		_n;
		Operand(void);
	public:
		Operand(int number) : Token("Operand"), _n(number) {return;}
		Operand(Operand const &other) : Token("Operand") {*this = other; return;}
		virtual ~Operand(void) {return;}
		Operand	&operator=(Operand const &rhs)
		{
			if (this == &rhs)
				return(*this);
			this->_n = rhs._n;
			return(*this);
		}

		int		getNum(void) const {return (this->_n);}
};

class	Operator : public Token
{
	private:
		char	_subtype;
		int		_precedence;
		Operator(void);
	public:
		Operator(char c) : Token("Operator"), _subtype(c)
		{
			if ((c == '+') || (c == '-'))
				this->_precedence = 0;
			else
				this->_precedence = 1;
			return;
		}
		Operator(Operator const &other) : Token("Operator") {*this = other; return;}
		virtual ~Operator(void) {return;}
		Operator	&operator=(Operator const &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->_subtype = rhs._subtype;
			this->_precedence = rhs._precedence;
			return (*this);
		}

		char	getSubtype(void) const {return (this->_subtype);}
		int		getPrecedence(void) const {return (this->_precedence);}
};

class	ParOpen : public Token
{
	public:
		ParOpen(void) : Token("ParOpen") {return;}
		ParOpen(ParOpen const &other) : Token("ParOpen") {*this = other; return;}
		virtual ~ParOpen(void) {return;}
		ParOpen	&operator=(ParOpen const &rhs) {return (*this);}
};

class	ParClose : public Token
{
	public:
		ParClose(void) : Token("ParClose") {return;}
		ParClose(ParClose const &other) : Token("ParClose") {*this = other; return;}
		virtual ~ParClose(void) {return;}
		ParClose	&operator=(ParClose const &rhs) {return (*this);}
};

#endif
