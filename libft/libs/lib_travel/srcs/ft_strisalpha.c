/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:39:50 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/29 17:59:01 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int		ft_strisalpha(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (str[i] == '-')
			i++;
		while (str[i])
		{
			if (ft_isalpha(str[i]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}
