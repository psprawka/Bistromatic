/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:19:05 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 01:53:24 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		addtrack(t_list **result, t_list *operand1, t_list *operand2, int max)
{
	printf("start addition\n");
	if (max == 1)
	{
		if (!operand1->isneg && operand2->isneg)
			return (runsub(result, operand1, operand2));
		if (operand1->isneg || (operand1->isneg && operand2->isneg))
			(*result)->isneg = 1;
		return (runadd(result, operand1, operand2));
	}
	else if (max == 2)
	{
		if (!operand2->isneg && operand1->isneg)
			return (runsub(result, operand2, operand1));
		if (operand2->isneg || (operand2->isneg && operand1->isneg))
			(*result)->isneg = 1;
		return (runadd(result, operand2, operand1));
	}
	return (0);
}

int		runadd(t_list **result, t_list *top, t_list *bottom)
{
	int	add;
	int	bottomsym;
	int	topsym;
	int	base;

	add = 0;
	base = (*result)->base;
	printf("runnadd\n");
	while ((*result)->remainder || top)
	{
		if (!listhookup(result, 1, 0))
			return (0);
		((*result)->isneg) ? (((*result)->prev)->isneg) = 1 : ((*result)->prev)->isneg;
		!bottom ? (bottomsym = 0) : (bottomsym = bottom->symbolindex);
		!top ? (topsym = 0) : (topsym = top->symbolindex);
	printf("add %d + (%d + %d)", bottomsym, topsym, (*result)->remainder);
		add = bottomsym + (topsym + (*result)->remainder);
		if (add >= base)
			addremainder(result, add, base);
		else
			(*result)->symbolindex = add;
		printf("result of add: %d\n", (*result)->symbolindex);
		!bottom ? bottom : (bottom = bottom->prev);
		!top ? top : (top = top->prev);
		(*result) = (*result)->prev;
	}
	printf("end of add\n");
	return (1);
}

void	addremainder(t_list **result, int add, int base)
{
	(*result)->symbolindex = add - base;
	add = ((add - (add - base)) / base);
	((*result)->prev)->remainder = ((base - (add - base)) / base);
}
