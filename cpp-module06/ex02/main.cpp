/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:37:48 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/12 19:08:41 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

class	Base
{
	public:
		Base() {return;};
		virtual ~Base() {return;};
};

class	A : public Base
{
	public:
		A() {return;};
		virtual ~A() {return;};
};
class	B : public Base
{
	public:
		B() {return;};
		virtual ~B() {return;};
};

class	C : public Base
{
	public:
		C() {return;};
		virtual ~C() {return;};
};

static Base	*CreateA(void)
{
	return (new A);
}

static Base	*CreateB(void)
{
	return (new B);
}

static Base	*CreateC(void)
{
	return (new C);
}

static Base	*generate(void)
{
	typedef Base	*(*constructor_arr)(void);

	int random_num = rand() % 3;
	constructor_arr	constructor[] = {&CreateA, &CreateB, &CreateC};
	for (int i = -1; i < 3; ++i)
		if (random_num == i)
			return (constructor[i]());
	return (nullptr);
}

static void	identify_from_pointer(Base *p)
{
	if ((dynamic_cast<A *>(p)) != nullptr)
		std::cout << "A" << std::endl;
	else if ((dynamic_cast<B *>(p)) != nullptr)
		std::cout << "B" << std::endl;
	else if ((dynamic_cast<C *>(p)) != nullptr)
		std::cout << "C" << std::endl;
	return;
}

static void	identify_from_reference(Base &p)
{
	return (identify_from_pointer(&p));
}

int		main(void)
{
	srand(time(NULL));

	Base	*ptr1 = generate();
	Base	*ptr2 = generate();
	Base	*ptr3 = generate();

	std::cout << "=====From pointer======" << std::endl;
	identify_from_pointer(ptr1);
	identify_from_pointer(ptr2);
	identify_from_pointer(ptr3);
	
	std::cout << "====From reference====" << std::endl;
	identify_from_reference(*ptr1);
	identify_from_reference(*ptr2);
	identify_from_reference(*ptr3);

	return (0);
}
