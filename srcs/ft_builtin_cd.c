/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:22:22 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/22 18:17:01 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	int		change_cwd(t_env *e, char *path)
{
	t_elem	*tmp;
	char	*pwd;
	char	*old;
	int		ret;

	ret = 0;
	if (!e->head || !path)
		return (ft_errors(path, 3));
	if ((ret = access_dir(path)) != 0)
		return (ft_errors(path, ret));
	if (!(old = getcwd(NULL, 1024)))
		if ((tmp = find_addr_env("PWD", e->head)))
			old = ft_strdup(tmp->content);
	chdir(path);
	pwd = getcwd(NULL, 1024);
	if ((tmp = find_addr_env("PWD", e->head)))
		tmp->content = ft_free_and_dup(tmp->content, pwd);
	else
		create_elem(e, "PWD", pwd);
	if ((tmp = find_addr_env("OLDPWD", e->head)))
		tmp->content = ft_free_and_dup(tmp->content, old);
	else
		create_elem(e, "OLDPWD", old);
	ft_multifruee(&pwd, &old, NULL);
	return (0);
}

static	char	*change_path(t_env *e, char **cmd, char *path)
{
	t_elem	*elem;
	char	*pwd;

	pwd = NULL;
	elem = NULL;
	if ((pwd = getcwd(NULL, 1024)))
	{
		if (!ft_strstr(pwd, cmd[1]))
			ft_errors(path, 16);
		ft_strdel(&path);
		if (ft_strstr(pwd, cmd[1]))
			path = ft_strreplace(pwd, cmd[1], cmd[2]);
		ft_strdel(&pwd);
		return (path);
	}
	if ((elem = find_addr_env("PWD", e->head)))
		path = ft_free_and_dup(path, elem->content);
	else
	{
		ft_errors(cmd[0], 17);
		ft_strdel(&path);
	}
	return (path);
}

static	char	*get_path(t_env *e, char **cmd)
{
	t_elem	*elem;
	char	*path;

	elem = NULL;
	path = NULL;
	if (cmd[1] && cmd[2] && cmd[3])
	{
		ft_errors(cmd[0], 4);
		return (NULL);
	}
	if ((!cmd[1]) || (cmd[1] && ft_strequ(cmd[1], "--") && !cmd[2]))
		elem = find_addr_env("HOME", e->head);
	if (ft_strequ(cmd[1], "-") && !ft_strequ(cmd[2], "-"))
		elem = find_addr_env("OLDPWD", e->head);
	(elem && ft_strequ(elem->name, "OLDPWD") && \
	(access_dir(elem->content)) == 0) ? ft_putendl(elem->content) : 0;
	path = (elem != NULL) ? ft_strdup(elem->content) : ft_strdup(cmd[1]);
	if ((cmd[1] && cmd[2] && !cmd[3]))
	{
		if ((path = change_path(e, cmd, path)) == NULL)
			return (NULL);
	}
	return (path);
}

int				builtin_cd(t_env *e, char **cmd)
{
	char	*path;

	if (e && e->head && cmd[0])
	{
		if (!(path = get_path(e, cmd)))
		{
			(access_dir(cmd[1]) == 0) ? 0 : ft_errors(cmd[0], 17);
			return (1);
		}
		change_cwd(e, path);
		ft_strdel(&path);
		return (0);
	}
	return (1);
}
