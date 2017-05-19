/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:38:16 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/04 18:38:17 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

int			ft_export(t_env *e, char *cmd)
{
	t_elem	*elem;
	char	*name;

	name = NULL;
	if (e && cmd)
	{
		if (!ft_strchr(cmd, '='))
		{
			elem = find_addr_env(cmd, e->head);
			(elem) ? ft_strdel(&elem->content) : create_elem(e, cmd, NULL);
		}
		else
		{
			name = ft_cutstr(cmd, '=');
			if ((elem = find_addr_env(name, e->head)) == NULL)
				parse_link(e, cmd);
			else
				elem->content = ft_free_and_dup(elem->content, \
					(cmd + ft_strlen(name) + 1));
			ft_strdel(&name);
		}
		return (0);
	}
	return (1);
}

int			builtin_export(t_env *e, char **cmd)
{
	int		i;

	i = 0;
	if (cmd)
	{
		if (!cmd[1])
			return (print_env(e->head));
		while (cmd[++i])
		{
			if (!ft_isalpha(cmd[i][0]))
				ft_errors(cmd[i], 15);
			else
			{
				if ((ft_export(e, cmd[i])) == 1)
					return (1);
			}
		}
		return (0);
	}
	return (1);
}
