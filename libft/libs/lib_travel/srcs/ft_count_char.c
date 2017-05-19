/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:52:25 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/28 18:54:07 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int		ft_count_char(char c, char *str)
{
	int	n;
	int	i;

	n = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			n++;
	}
	return (n);
}