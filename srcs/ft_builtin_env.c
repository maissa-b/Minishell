/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:17:06 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/22 18:17:07 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	t_env	*get_tmp_envcpy(t_env *tmp, t_env *e, char **cmd)
{
	if (cmd[0][0] == '-' && cmd[0][1] && cmd[0][1] == 'i')
	{
		tmp = init_list();
		get_backup_envcpy(tmp);
	}
	else
	{
		tmp = env_cpy(e);
	}
	return (tmp);
}

static	int		ft_env(t_env *e, char **cmd)
{
	t_env	*tmp;
	t_opt	*opt;
	int		i;

	i = 1;
	tmp = NULL;
	tmp = get_tmp_envcpy(tmp, e, cmd);
	opt = init_opt();
	if ((i = check_opt(opt, i, "i", cmd)) != -1)
	{
		(opt->e_i && cmd[i]) ? clear_env(&tmp) : 0;
		(!tmp && cmd[i]) ? tmp = init_list() : 0;
		while (cmd[i])
		{
			if (!ft_strchr(cmd[i], '='))
				break ;
			ft_export(tmp, cmd[i]);
			i++;
		}
		(cmd[i] && !check_builtin(cmd[i])) ? exec_binary(tmp, &(cmd[i])) : 0;
		(!opt->e_i && !cmd[i] && tmp->head) ? print_env(tmp->head) : 0;
	}
	(tmp) ? clear_env(&tmp) : free(tmp);
	opt = del_opt(opt);
	return (0);
}

int				builtin_env(t_env *e, char **cmd)
{
	if (e && e->head && cmd)
	{
		if (e->size > 0 && cmd[0] && !cmd[1])
		{
			print_env(e->head);
		}
		else if (cmd[0] && cmd[1])
		{
			return (ft_env(e, cmd));
		}
		return (0);
	}
	return (1);
}
