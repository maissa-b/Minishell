/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:21:33 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/14 18:37:14 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

int			check_builtin(char *str)
{
	if (ft_strequ(str, "cd") || ft_strequ(str, "chdir"))
		return (1);
	if (ft_strequ(str, "unsetenv") || ft_strequ(str, "unset"))
		return (1);
	if (ft_strequ(str, "setenv"))
		return (1);
	if (ft_strequ(str, "exit"))
		return (1);
	if (ft_strequ(str, "export"))
		return (1);
	if (ft_strequ(str, "env"))
		return (1);
	return (0);
}

void		exec_builtin(t_env *e, char **cmd)
{
	if (ft_strequ(cmd[0], "cd") || ft_strequ(cmd[0], "chdir"))
		builtin_cd(e, cmd);
	if (ft_strequ(cmd[0], "unsetenv") || ft_strequ(cmd[0], "unset"))
		builtin_unseting(e, cmd);
	if (ft_strequ(cmd[0], "setenv"))
		ft_setenv(e, cmd);
	if (ft_strequ(cmd[0], "exit"))
		ft_exit(e, cmd);
	if (ft_strequ(cmd[0], "export"))
		builtin_export(e, cmd);
	if (ft_strequ(cmd[0], "env"))
		builtin_env(e, cmd);
}

int			parse_builtin(t_env *e, char **cmd)
{
	if (check_builtin(cmd[0]))
	{
		exec_builtin(e, cmd);
		return (1);
	}
	return (0);
}
