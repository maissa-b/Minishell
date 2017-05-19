/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:27:41 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/29 13:27:42 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	char	**list_to_tab(t_env *e)
{
	char	**tab;
	t_elem	*elem;
	int		i;

	tab = NULL;
	elem = NULL;
	if (e && e->head)
	{
		i = 0;
		tab = ft_tabnew(e->size);
		elem = e->head;
		while (elem)
		{
			if (elem->content)
				tab[i] = ft_multijoin(tab[i], elem->name, "=", elem->content);
			else
				tab[i] = ft_strjoin(elem->name, "=");
			i++;
			elem = elem->next;
		}
		tab[i] = NULL;
	}
	else
		return (NULL);
	return (tab);
}

int				exec_path(t_env *e, char *way, char **cmd)
{
	pid_t		minishell;
	char		**env;

	minishell = 0;
	env = NULL;
	if (way && cmd)
	{
		env = (e) ? list_to_tab(e) : NULL;
		minishell = fork();
		if (minishell == 0)
		{
			if ((execve(way, cmd, env)) == -1)
			{
				ft_errors(way, 3);
			}
			exit(1);
		}
		else
			waitpid(minishell, NULL, 0);
		(way) ? ft_strdel(&way) : 0;
		(env) ? ft_tabclr(env) : 0;
		return (0);
	}
	return (1);
}

char			*is_bin(t_env *e, char **cmd)
{
	t_elem	*elem;
	char	**path;
	int		i;
	char	*way;

	elem = NULL;
	if (!cmd[0])
		return (NULL);
	if (!(elem = find_addr_env("PATH", e->head)) || !elem->content)
		return (NULL);
	i = -1;
	way = NULL;
	path = NULL;
	path = ft_strsplit(elem->content, ':');
	while (path[++i])
	{
		way = ft_multijoin(way, path[i], "/", cmd[0]);
		if (access(way, F_OK) == 0 && !ft_strstr(cmd[0], "./"))
			break ;
		ft_strdel(&way);
	}
	ft_tabclr(path);
	if (ft_strstr(cmd[0], "./"))
		way = ft_strdup(cmd[0]);
	return (way);
}

int				exec_binary(t_env *e, char **cmd)
{
	char		*way;

	way = NULL;
	if (cmd)
	{
		way = is_bin(e, cmd);
		if (way)
		{
			return (exec_path(e, way, cmd));
		}
		else if (!way && access(cmd[0], F_OK) == 0)
		{
			way = ft_strdup(cmd[0]);
			return (exec_path(e, way, cmd));
		}
		else
		{
			(way) ? ft_strdel(&way) : 0;
			return (ft_errors(cmd[0], 7));
		}
	}
	return (ft_errors(cmd[0], 7));
}
