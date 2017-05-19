/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:44:07 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/29 15:15:20 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char	*ft_free_and_dup(char *to_free, char *to_dup)
{
	char	*ret;

	ret = NULL;
	if (to_free)
	{
		ft_strdel(&to_free);
	}
	if (to_dup)
	{
		ret = ft_strdup(to_dup);
	}
	return (ret);
}
