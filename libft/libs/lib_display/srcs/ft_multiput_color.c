/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiput_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:23:05 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 20:23:06 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void	ft_multiput_color(char *color, char *str1, char *str2, char *str3)
{
	if (color)
	{
		(str1) ? ft_putstr_color(color, str1) : 0;
		(str2) ? ft_putstr_color(color, str2) : 0;
		(str3) ? ft_putstr_color(color, str3) : 0;
		write(1, "\n", 1);
	}
}
