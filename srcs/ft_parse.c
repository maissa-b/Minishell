/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:59 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 15:15:14 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	char	*set_replacement(t_env *e, char *buff)
{
	t_elem	*elem;
	char	*ret;

	elem = NULL;
	ret = NULL;
	if (buff)
	{
		buff = ft_charreplace(buff, '\t', ' ');
		if ((elem = find_addr_env("HOME", e->head)) && elem->content)
			ret = ft_strreplace(buff, "~", elem->content);
		else
			ret = ft_strdup(buff);
		ret = ft_strtrim(ret);
		(buff) ? ft_strdel(&buff) : 0;
	}
	return (ret);
}

char			*get_cmd(t_env *e)
{
	char	*buff;
	ssize_t	rd;
	char	*ret;

	buff = NULL;
	ret = NULL;
	if ((buff = ft_strnew(1024)))
	{
		if (!(rd = read(0, buff, 1024)))
			exit(0);
		buff[rd] = '\0';
		ret = set_replacement(e, buff);
	}
	return (ret);
}
