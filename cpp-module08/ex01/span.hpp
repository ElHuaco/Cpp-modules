/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:56:15 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/17 12:35:33 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <exception>
# include <vector>

class Span : public std::vector<int>
{
	public:
		Span(unsigned int N);
		~Span(void);

		void		addNumber(int const &number); 
		void		addNumber(unsigned int const &number);

		int			shortestSpan(void) const;
		int			longestSpan(void) const;

		class NoSpanToFindException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

	private:
		Span(void);
		Span(Span const &other);
		Span		&operator=(Span const &rhs);
		unsigned int	_nCalls;
		unsigned int	_nCallsMax;
};
#endif
