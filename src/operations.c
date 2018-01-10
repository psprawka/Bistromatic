/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/09 19:47:24 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		operandsplit(t_list **head, t_list **operand1, t_list **operand2)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (!(*head)->na)
	{
		temp = (*head);
		temp->prev = 0;
		if (temp->value == '-')
		{
			i = 1;
			temp = temp->next;
			ft_memdel((*head));
		}
		while (!(temp->na))
		{
			if (i)
				temp->isneg = 1;
			temp = temp->next;
		}
		if (temp->next)
			head = temp->next;
		temp->next = 0;
		(!operand1) ? (*operand1) = sym_lst(temp) : (*operand2) = sym_lst(temp);
	}
}

t_list	*sym_lst(t_list *temp)
{
	t_list *op_lo;

	op_lo = temp->prev;
	ft_memdel(temp);
	op_lo->next = 0;
	return (op_lo);
}

int		operandlen(t_list **operand1, t_list **operand2)
{
	t_list	*temp;
	int		i;

	temp = (*operand1);
	i = 0;
	while (temp->next)
		i++;
	(*operand1)->numlen = i;
	temp = (*operand2);
	i = 0;
	while (temp->next)
		i++;
	(*operand2)->numlen = i;
}

int		remaindercalc(int result, int base)
{
	int	i;

	i = 1;
	while (base < result)
		base = base * i++;
	return (base - result);
}
