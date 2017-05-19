/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:00:14 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/03 21:01:01 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

static int		ft_tb_size(char *s, char c)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			size++;
			i++;
		}
	}
	return (size);
}

static int		ft_len(char *s, char c, int start)
{
	int		len;

	len = 0;
	while (s[start] != c && s[start])
	{
		len++;
		start++;
	}
	return (len);
}

static char		*ft_createstr(char *s1, char *s2, char c, int start)
{
	int		i;

	i = 0;
	while (s1[start] && s1[start] != c)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

static char		**ft_createtab(char **tab, char *s, char c, int start)
{
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (s[i])
	{
		len = ft_len(s, c, start);
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[j])
		{
			tab[j] = ft_createstr(s, tab[j], c, start);
			j++;
			i += ft_len(s, c, start);
			while (s[i] == c && s[i])
				i++;
			start = i;
		}
		else
			return (NULL);
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	tab = NULL;
	if (s)
	{
		size = ft_tb_size((char *)s, c);
		if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
			return (NULL);
		i = 0;
		while (s[i] == c && s[i])
			i++;
		tab = ft_createtab(tab, (char *)s, c, i);
		return (tab);
	}
	return (NULL);
}
