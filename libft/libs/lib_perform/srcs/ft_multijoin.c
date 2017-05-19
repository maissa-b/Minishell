/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:36:27 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/20 19:08:42 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_multijoin(char *ret, char *str1, char *str2, char *str3)
{
	if (!str1 || !str2 || !str3)
		return (NULL);
	ret = (ret) ? ft_free_and_join(ret, str1) : ft_strdup(str1);
	ret = ft_free_and_join(ret, str2);
	ret = ft_free_and_join(ret, str3);
	return (ret);
}
