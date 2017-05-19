/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:17:37 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/22 18:17:38 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

int		ft_exit(t_env *e, char **cmd)
{
	if (cmd && ft_strequ(cmd[0], "exit"))
	{
		if ((cmd[1] && !cmd[2]) || !cmd[1])
		{
			if (ft_strisdigit(cmd[1]))
			{
				shlvl(e->head, 1);
				ft_putendl("exit");
				(e) ? clear_env(&e) : 0;
				if (!cmd[1])
					exit(0);
				else
					exit(ft_atoi(cmd[1]));
			}
			return (ft_errors(cmd[0], 6));
		}
		return (ft_errors(cmd[0], 5));
	}
	return (1);
}
