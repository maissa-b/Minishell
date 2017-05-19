/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_setenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:17:11 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/22 18:17:14 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

int	ft_setenv(t_env *e, char **cmd)
{
	t_elem	*elem;

	if (e && cmd)
	{
		if (!cmd[1])
			return (print_env(e->head));
		if (ft_strisalnum(cmd[1]) == 0 && cmd[1][0] != '_')
			return (ft_errors(cmd[0], 9));
		if (ft_isdigit(cmd[1][0]) == 1 && cmd[1][0] != '_')
			return (ft_errors(cmd[0], 10));
		if ((elem = find_addr_env(cmd[1], e->head)) != NULL)
			elem->content = (elem->content) ? \
		ft_free_and_dup(elem->content, cmd[2]) : ft_strdup(cmd[2]);
		else
			create_elem(e, cmd[1], cmd[2]);
		return (0);
	}
	return (1);
}
