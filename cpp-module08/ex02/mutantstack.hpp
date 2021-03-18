/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:13:17 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 12:34:31 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <algorithm>

template <typename T> class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack(void) : std::stack<T>() {return;}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {return;}
		virtual ~MutantStack(void) {return;}

		MutantStack		&operator=(MutantStack &rhs)
		{
			MutantStack temp(rhs);
			std::swap(*this, temp);
			return (*this);
		}

		iterator		begin(void) {return (std::stack<T>::c.begin());}
		iterator		end(void) {return (std::stack<T>::c.end());}
};
#endif
