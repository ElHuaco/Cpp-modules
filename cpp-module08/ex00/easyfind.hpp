/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:30:11 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/17 10:08:49 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
	typename T::const_iterator easyfind(T const &container, int needle)
{
	typename T::const_iterator first = container.begin();
	typename T::const_iterator last = container.end();

	return (find(first, last, needle));
}
