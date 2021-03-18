/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:56:15 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 12:25:23 by alejandro        ###   ########.fr       */
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
		Span(Span const &other);
		virtual ~Span(void);

		Span		&operator=(Span const &rhs);

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
		unsigned int	_nCalls;
		unsigned int	_nCallsMax;
};
#endif
