/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:24:14 by alejandro         #+#    #+#             */
/*   Updated: 2021/02/26 12:15:48 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include "Fixed.hpp"
# include <string>

class	Tree
{
	public:
		typedef Tree	Node;

		Tree(void);
		Tree(Tree const &rhs);
		~Tree(void);

		Tree	&operator=(Tree const &rhs);

		static Node		*createNode(std::string key);
		void			destroyNode(void);
		void			insertNode(std::string key);
		Node			*findKey(std::string key) const;
		void			ratatösk(Tree &root);
		
		std::string		getKey(void) const;
		void			setKey(std::string key);
//		static Fixed	getResult(void) const;
	private:
		std::string		_key;
		Node			*_root
		Node			*_left;
		Node			*_right;
		int				_level;
		static Fixed	_result;
};
#endif
