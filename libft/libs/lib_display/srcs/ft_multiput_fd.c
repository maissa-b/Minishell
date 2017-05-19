/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiput_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:22:59 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 20:23:00 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void	ft_multiput_fd(char *str1, char *str2, char *str3, int fd)
{
	(str1) ? ft_putstr_fd(str1, fd) : 0;
	(str2) ? ft_putstr_fd(str2, fd) : 0;
	(str3) ? ft_putstr_fd(str3, fd) : 0;
	write(1, "\n", 1);
}
