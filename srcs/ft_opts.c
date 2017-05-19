/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:45:44 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/13 16:45:45 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	void	set_opt(t_opt *opt, char c)
{
	(c == 'i') ? opt->e_i = 1 : 0;
}

static	int		is_opt(char *opts, char c)
{
	return ((ft_strchr(opts, c)) ? 1 : 0);
}

t_opt			*init_opt(void)
{
	t_opt	*opt;

	opt = NULL;
	if ((opt = malloc(sizeof(t_opt))))
	{
		ft_bzero(opt, sizeof(t_opt));
		opt->e_i = 0;
	}
	return (opt);
}

t_opt			*del_opt(t_opt *opt)
{
	opt->e_i = 0;
	ft_bzero(opt, sizeof(*opt));
	free(opt);
	return (opt);
}

int				check_opt(t_opt *opt, int i, char *str, char **cmd)
{
	int			j;

	if (ft_strequ(cmd[i], "--"))
		return (i + 1);
	if (!cmd)
		return (-1);
	if (cmd[i][0] == '-' && cmd[i][1] && cmd[i][1] != '-')
	{
		while (cmd[i] && cmd[i][0] == '-' && cmd[i][1] && cmd[i][1] != '-')
		{
			j = 1;
			if ((is_opt(str, cmd[i][j])) == 1)
			{
				set_opt(opt, cmd[i][j]);
				while (cmd[i][j] && is_opt(str, cmd[i][j]))
					j++;
				if (cmd[i][j] && !is_opt(str, cmd[i][j]))
					return (illegal_option(cmd[0], cmd[i][j]));
			}
			else
				return (illegal_option(cmd[0], cmd[i][j]));
			i++;
		}
	}
	return (i);
}
