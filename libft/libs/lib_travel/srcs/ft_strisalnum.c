/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:40:55 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/29 20:30:09 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int		ft_strisalnum(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (str[i] == '-')
			i++;
		while (str[i])
		{
			if (ft_isalnum(str[i]) == 0)
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}
