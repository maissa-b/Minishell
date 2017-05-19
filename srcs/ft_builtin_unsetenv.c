/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:17:26 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/22 18:17:27 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	int	ft_unsetenv(t_env *e, char *var)
{
	t_elem	*elem;

	if (e && e->head)
	{
		elem = e->head;
		if (var)
		{
			if ((elem = find_addr_env(var, e->head)))
				e->size = del_elem(e, elem, e->size);
			return (0);
		}
		else
		{
			return (ft_errors(var, 8));
		}
	}
	return (1);
}

int			builtin_unseting(t_env *e, char **cmd)
{
	int		i;

	i = 0;
	if (e && cmd)
	{
		while (cmd[++i])
		{
			ft_unsetenv(e, cmd[i]);
		}
		return (0);
	}
	return (1);
}
