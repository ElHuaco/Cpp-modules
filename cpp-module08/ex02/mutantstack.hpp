/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:48:38 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/17 19:09:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <algorithm>
# include <iterator>

template <typename T> class	MutantStack : std::list<typename T>
{
	public:
			MutantStack(void);
			MutantStack(MutantStack const &other);
			~MutantStack(void);

			MutantStack		&operator=(MutantStack const &rhs);

			class	MutantIterator
				: public std::iterator<std::bidirectional_iterator_tag, typename T>
			{
				//Implementar aquí?
			};

			MutantIterator	&begin(void) const;
			MutantIterator	&end(void) const;
};
#endif
