/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:37:21 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 13:59:35 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	void	swap_link(t_env *e, t_elem **elem)
{
	if ((*elem)->prev && (*elem)->next)
	{
		(*elem)->next->prev = (*elem)->prev;
		(*elem)->prev->next = (*elem)->next;
	}
	else if ((*elem)->prev && !(*elem)->next)
	{
		e->foot = (*elem)->prev;
		(*elem)->prev->next = NULL;
	}
	else if (!(*elem)->prev && (*elem)->next)
	{
		e->head = (*elem)->next;
		(*elem)->next->prev = NULL;
	}
}

static	void	clear_elem(t_elem **elem)
{
	((*elem)->name) ? ft_strdel(&((*elem)->name)) : 0;
	((*elem)->content) ? ft_strdel(&((*elem)->content)) : 0;
	((*elem)->old_content) ? ft_strdel(&((*elem)->old_content)) : 0;
}

int				del_elem(t_env *e, t_elem *elem, int i)
{
	if (elem)
	{
		i -= 1;
		swap_link(e, &elem);
		clear_elem(&elem);
		free(elem);
		elem = NULL;
	}
	return (i);
}

int				clear_env(t_env **e)
{
	t_elem	*elem;

	elem = NULL;
	if (*e && (*e)->head)
	{
		elem = (*e)->head;
		while (elem)
		{
			(*e)->size = del_elem(*e, elem, (*e)->size);
			elem = elem->next;
		}
		free(*e);
		*e = NULL;
		return (0);
	}
	return (1);
}
