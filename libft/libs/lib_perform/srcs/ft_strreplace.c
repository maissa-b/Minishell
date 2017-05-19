/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 18:01:53 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/20 16:04:45 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_strreplace(char *replaced, char *search, char *replace)
{
	char	*res;
	char	*endstr;
	char	*tmp;
	char	*second_tmp;

	if (!replaced || !search || !replace)
		return (NULL);
	if (ft_strstr(replace, search))
		return (NULL);
	while ((res = ft_strstr(replaced, search)))
	{
		replaced = ft_strsub(replaced, 0, (res - replaced));
		second_tmp = ft_strdup(replaced);
		replaced = ft_free_and_join(replaced, replace);
		endstr = ft_strdup(res + ft_strlen(search));
		tmp = ft_strjoin(replaced, endstr);
		replaced = ft_free_and_dup(replaced, tmp);
		ft_strdel(&tmp);
		ft_strdel(&endstr);
		ft_strdel(&second_tmp);
	}
	return (replaced);
}
