/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:59:00 by alejandro         #+#    #+#             */
/*   Updated: 2021/02/26 12:21:34 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tree.hpp"

Tree::Tree(void) : _key(nullptr), _root(nullptr), _left(nullptr),
	_right(nullptr), _level(-1)
{
	return;
}

Tree::Tree(Tree const &rhs) : _key(rhs._key), _root(rhs._root), _left(rhs._left),
	_right(rhs._right), _level(rhs._level)

{
	return;
}

Tree::~Tree(void)
{
	return;
}

Tree		&Tree::operator=(Tree const &rhs)
{
	this->_key = rhs._key
	this->_root = rhs._root
	this->_left = rhs._left
	this->_right = rhs._right
	this->_level = rhs._level
	return (*this);
}

std::string		Tree::getKey(void) const
{
	return (this->_key);
}

void			Tree::setKey(std::string key)
{
	this->_key = key;
	return;
}

Node			*Tree::createNode(std::string key)
{
	Node	*node = new Node;
	node->_key = key;
	node->_left = node->_right = nullptr;
	return (node);
}

void			Tree::destroyNode(void)
{
	this->_root = this->_left = this->_right = nullptr;
	delete this;
	return;
}

void			Tree::insertNode(std::string key)
{
	Node	*node = createNode(key);
	
}
