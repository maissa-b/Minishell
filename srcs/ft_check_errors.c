/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:40:29 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/29 13:40:31 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

int		illegal_option(char *str, char c)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ", 2);
	ft_multiput_fd("[", "i", "]", 2);
	return (-1);
}

int		is_error(char *buff)
{
	if (ft_strstr(buff, ";;"))
		return (14);
	return (0);
}

int		ft_errors(char *cmd, int i)
{
	(i == 1) ? ft_multiput_fd(cmd, ": No such file or directory.", NULL, 2) : 0;
	(i == 2) ? ft_multiput_fd(cmd, ": Not a directory.", NULL, 2) : 0;
	(i == 3) ? ft_multiput_fd(cmd, ": Permision denied.", NULL, 2) : 0;
	(i == 4) ? ft_multiput_fd(cmd, ": Too many arguments.", NULL, 2) : 0;
	(i == 5) ? ft_multiput_fd(cmd, ": Expression Syntax.", NULL, 2) : 0;
	(i == 6) ? ft_multiput_fd(cmd, ": Badly formed number.", NULL, 2) : 0;
	(i == 7) ? ft_multiput_fd("minishell: ", "command not found: ", cmd, 2) : 0;
	(i == 8) ? ft_multiput_fd(cmd, ": Too few arguments.", NULL, 2) : 0;
	(i == 9) ? ft_multiput_fd(cmd, \
		": Variable name must contain alphanumeric characters.", NULL, 2) : 0;
	(i == 10) ? ft_multiput_fd(cmd, \
		": Variable name must begin with a letter.", NULL, 2) : 0;
	(i == 11) ? ft_multiput_fd("minishell: invalid env.", NULL, NULL, 2) : 0;
	(i == 12) ? ft_multiput_fd(cmd, ": HOME not set.", NULL, 2) : 0;
	(i == 13) ? ft_multiput_fd(cmd, ": OLDPWD not set.", NULL, 2) : 0;
	(i == 14) ? ft_multiput_fd("sh: ", "parse error near `;;'", NULL, 2) : 0;
	(i == 15) ? ft_multiput_fd("export: ", "not an identifier: ", cmd, 2) : 0;
	(i == 16) ? ft_multiput_fd("cd: ", "string not in pwd: ", cmd, 2) : 0;
	(i == 17) ? ft_multiput_fd(cmd, ": path unavailable.", NULL, 2) : 0;
	return (1);
}

int		access_dir(char *dir)
{
	struct stat	stats;
	DIR			*fd;

	if ((lstat(dir, &stats)) == 0)
	{
		if (!(S_ISREG(stats.st_mode)))
		{
			if ((fd = opendir(dir)))
			{
				closedir(fd);
				if ((access(dir, F_OK)) == 0)
				{
					return (0);
				}
			}
			return (3);
		}
		return (2);
	}
	return (1);
}
