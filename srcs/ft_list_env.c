/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:00:25 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 14:26:31 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

t_env	*init_list(void)
{
	t_env	*e;

	e = NULL;
	if ((e = malloc(sizeof(t_env))))
	{
		ft_bzero(e, sizeof(t_env));
	}
	return (e);
}

void	add_elem(t_env *e, t_elem *elem)
{
	if (elem)
	{
		if (!e->head)
		{
			e->head = elem;
		}
		else
		{
			e->foot->next = elem;
			elem->prev = e->foot;
		}
		e->foot = elem;
	}
}

void	create_elem(t_env *e, char *name, char *content)
{
	t_elem	*elem;

	elem = NULL;
	if ((elem = malloc(sizeof(t_elem))))
	{
		e->size += 1;
		elem->next = NULL;
		elem->prev = NULL;
		elem->name = (name) ? ft_strdup(name) : NULL;
		elem->content = (content) ? ft_strdup(content) : NULL;
		elem->old_content = (content) ? ft_strdup(elem->content) : NULL;
		add_elem(e, elem);
	}
}
