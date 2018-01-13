/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:07:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 01:53:25 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		subtrack(t_list **result, t_list *operand1, t_list *operand2, int max)
{
	if (max == 1)
	{
		if ((operand1->isneg && !operand2->isneg)
			|| (operand1->isneg && operand2->isneg))
			(*result)->isneg = 1;
		if ((!operand1->isneg && !operand2->isneg)
			|| (operand1->isneg && operand2->isneg))
			return (runsub(result, operand1, operand2));
		else
			return (runadd(result, operand1, operand2));
	}
	else if (max == 2)
	{
		if ((!operand2->isneg && !operand1->isneg)
			|| (!operand2->isneg && operand1->isneg)
			|| (operand2->isneg && !operand1->isneg))
			(*result)->isneg = 1;
		if ((!operand2->isneg && !operand1->isneg)
			|| (operand2->isneg && !operand1->isneg))
			return (runsub(result, operand2, operand1));
		else
			return (runadd(result, operand2, operand1));
	}
	return (0);
}

int		runsub(t_list **result, t_list *top, t_list *bottom)
{
	int	sub;
	int	bottomsym;
	int	topsym;
	int	base;

	sub = 0;
	base = (*result)->base;
	printf("runnsub\n");
	while ((*result)->remainder || top)
	{
		if (!listhookup(result, 1, 0))
			return (0);
		((*result)->isneg) ? ((*result)->prev)->isneg = 1 : ((*result)->prev)->isneg;
		!bottom ? (bottomsym = 0) : (bottomsym = bottom->symbolindex);
		printf("subtrack 1\n");
		!top ? (topsym = 0) : (topsym = top->symbolindex);			//segfault here when -2-4
		printf("subtrack 2\n");
		printf("sub %d - (%d + %d)\n", topsym, bottomsym, (*result)->remainder);
		sub = topsym - (bottomsym + (*result)->remainder);
		if (sub < 0)
		{
			(*result)->symbolindex = base + sub;
			((*result)->prev)->remainder = 1;
		}
		else
			(*result)->symbolindex = sub;
		!bottom ? bottom : (bottom = bottom->prev);
		!top ? top : (top = top->prev);
		(*result) = (*result)->prev;
		
	}
	printf("END OF SUB\n");
	return (1);
}
