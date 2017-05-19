/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:56:25 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/16 19:07:28 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char	**ft_tabnew(size_t size)
{
	char	**tab;
	size_t	len;

	tab = NULL;
	if (size != 0)
	{
		len = size + 1;
		tab = (char **)malloc(sizeof(char *) * len);
		while (len > 0)
		{
			len--;
			tab[len] = NULL;
		}
		tab[0] = NULL;
	}
	return (tab);
}
