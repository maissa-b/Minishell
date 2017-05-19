/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:19:02 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/22 18:19:03 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	void	print_prompt(char *color, char *str1, char *str2, char *str3)
{
	if (color)
	{
		(str1) ? ft_putstr_color(color, str1) : 0;
		(str2) ? ft_putstr_color(color, str2) : 0;
		(str3) ? ft_putstr_color(color, str3) : 0;
	}
}

void			set_prompt(t_env *e)
{
	t_elem	*elem;
	char	*pwd;
	char	*tmp;

	pwd = NULL;
	elem = e->head;
	if ((pwd = getcwd(NULL, 1024)))
	{
		if ((elem = find_addr_env("HOME", e->head)) && \
			elem->content && ft_strstr(pwd, elem->content))
		{
			tmp = ft_strsub(pwd, ft_strlen(elem->content), \
				(ft_strlen(pwd) - ft_strlen(elem->content)));
			ft_strdel(&pwd);
			pwd = ft_strjoin("~", tmp);
			ft_strdel(&tmp);
		}
	}
	else
	{
		if ((elem = find_addr_env("PWD", e->head)))
			pwd = ft_strdup(elem->content);
	}
	print_prompt(GREEN, "[", pwd, "] > ");
	ft_strdel(&pwd);
}

int				shlvl(t_elem *elem, int code)
{
	t_elem	*travel;
	char	*lvl;

	if (elem)
	{
		travel = elem;
		if ((travel = find_addr_env("SHLVL", elem)))
		{
			if (code == 0)
			{
				lvl = (travel->content) ? \
				ft_itoa(ft_atoi(travel->content) + 1) : NULL;
				travel->content = ft_free_and_dup(travel->content, lvl);
			}
			else
			{
				lvl = (travel->content) ? \
				ft_itoa(ft_atoi(travel->content) - 1) : NULL;
				travel->content = ft_free_and_dup(travel->content, lvl);
			}
			ft_strdel(&lvl);
			return (0);
		}
	}
	return (1);
}

void			clear_sh(char **envp)
{
	int		fd;
	pid_t	clr;

	if (envp && *envp)
	{
		clr = fork();
		if ((fd = open("/dev/tty", O_WRONLY | O_CREAT)))
		{
			if (clr == 0)
				execve("/usr/bin/clear", NULL, envp);
			else
				wait(0);
		}
	}
}

t_elem			*find_addr_env(char *name, t_elem *e)
{
	t_elem	*elem;

	if (e)
	{
		elem = e;
		while (elem)
		{
			if (ft_strequ(elem->name, name))
				return (elem);
			elem = elem->next;
		}
	}
	return (NULL);
}
