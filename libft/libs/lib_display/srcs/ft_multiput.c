/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:22:45 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 20:22:46 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void	ft_multiput(char *str1, char *str2, char *str3, char *str4)
{
	(str1) ? ft_putstr(str1) : 0;
	(str2) ? ft_putstr(str2) : 0;
	(str3) ? ft_putstr(str3) : 0;
	(str4) ? ft_putstr(str4) : 0;
	write(1, "\n", 1);
}
