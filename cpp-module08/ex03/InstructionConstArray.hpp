/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionConstArray.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:48:21 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 17:51:13 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.hpp"
#include "IncrementAddress.hpp"
#include "IncrementValue.hpp"
#include "DecrementAddress.hpp"
#include "DecrementValue.hpp"
#include "OutputAddressValue.hpp"
#include "SkipLoopExp.hpp"
#include "RestartLoop.hpp"
#include "StoreValue.hpp"

Instruction		*CreateIncVal(void)
{
	return (new IncrementValue);
}

Instruction		*CreateDecVal(void)
{
	return (new DecrementValue);
}

Instruction		*CreateIncAdd(void)
{
	return (new IncrementAddress);
}
Instruction		*CreateDecAdd(void)
{
	return (new DecrementAddress);
}
Instruction		*CreateOutput(void)
{
	return (new OutputAddressValue);
}
Instruction		*SkipLoopExp(void)
{
	return (new SkipLoopExp);
}
Instruction		*RestartLoop(void)
{
	return (new RestartLoop);
}
Instruction		*StoreValue(void)
{
	return (new StoreValue);
}
