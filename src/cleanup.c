/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:26:19 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 03:40:29 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		lstdel(t_list **start)
{
	t_list *temp;

//	if (*((*start)->basekey))
//		free((void *)((*start)->basekey));
//printf("DELETING\n");
	if ((*start)->next)
	{
		while ((*start))
		{
			temp = (*start)->next;
			free(*start);
			(*start) = temp;
		}
	}
	else
	{
		while ((*start))
		{
			temp = (*start)->prev;
			free(*start);
			(*start) = temp;
		}
	}
	return (1);
}

void	free_one_node(t_list *prev, t_list *curr, t_list *next)
{
	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	printf("FREEING\n");
	free(curr->basekey);
	free(curr);
	curr = next;
}
