/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:30:08 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 17:32:41 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "Intern.hpp"
# include "OfficeBlock.hpp"

# define NUM_OBS 20

class	CentralBureaucracy
{
	public:
		CentralBureaucracy(void);
		~CentralBureaucracy(void);

		void		feedBureaucrat(Bureaucrat &bureaucrat);
		void		queueUp(std::string const &name);
		void		doBureaucracy(void) const;

	private:
		OfficeBlock		*_block[NUM_OBS];
		std::string		*_queue;
		int				_queueSize;
};
#endif
