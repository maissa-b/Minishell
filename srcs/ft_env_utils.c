/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:37:30 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 14:24:29 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

t_env	*env_cpy(t_env *e)
{
	t_env	*cpy;
	t_elem	*tmp;

	cpy = NULL;
	cpy = init_list();
	if (e && e->head)
	{
		tmp = e->head;
		while (tmp)
		{
			create_elem(cpy, tmp->name, tmp->content);
			tmp = tmp->next;
		}
	}
	return (cpy);
}

t_env	*parse_link(t_env *e, char *var)
{
	char	*name;
	char	*content;

	if (var)
	{
		name = NULL;
		content = NULL;
		name = (ft_strchr(var, '=')) ? ft_cutstr(var, '=') : ft_strdup(var);
		content = (name) ? ft_strdup(var + ft_strlen(name) + 1) : NULL;
		create_elem(e, name, content);
		ft_multifruee(&name, &content, NULL);
	}
	return (e);
}

int		print_env(t_elem *head)
{
	t_elem	*elem;

	if (head)
	{
		elem = head;
		while (elem)
		{
			if (!elem->content)
				(elem->name) ? ft_multiput(elem->name, "=", NULL, NULL) : 0;
			else
				ft_multiput(elem->name, "=", elem->content, NULL);
			elem = elem->next;
		}
		return (0);
	}
	return (1);
}

void	get_backup_envcpy(t_env *e)
{
	char	*pwd;

	if ((pwd = getcwd(NULL, 1024)))
	{
		create_elem(e, "PWD", pwd);
		ft_strdel(&pwd);
	}
	create_elem(e, "SHLVL", "0");
}

void	get_envcpy(t_env *e, char **env)
{
	int		i;

	if (env)
	{
		i = -1;
		while (env[++i])
		{
			e = parse_link(e, env[i]);
		}
	}
}
