/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:46:02 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/18 05:46:17 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	if (n)
	{
		while (n != 0 && n--)
			*s2++ = 0;
	}
}
