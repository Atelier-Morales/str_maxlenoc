/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 16:16:29 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/19 06:59:53 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int				ft_strlen(char *s)
{
	int			i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int				print_error(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return (0);
}

char			*ft_strnstr(char *str, char *to_find, int len)
{
	int			i;
	int			j;
	char		*res;
	int			found;

	i = -1;
	res = NULL;
	found = 0;
	while (!found && str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && j < len)
			++j;
		if (j >= len)
		{
			res = &str[i]; /* returns a pointer to the first occurence of to_find in str */
			found = 1;
		}
	}
	return (res);
}

char			*ft_strndup(char *src, int n)
{
	int			i;
	char		*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * n + 1);
	while (i < n && src[i])
	{
		res[i] = src[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

void			str_maxlenoc(int ac, char **av)
{
	static int	i;
	static int	nb;
	int			j;
	int			found;
	char		*res;

	res = NULL;
	while (av[0][i])
	{
		j = -1;
		found = 1;
		while (++j < ac && av[j])
			found = !ft_strnstr(av[j], &av[0][i], nb + 1) ? 0 : found;
		if (found)
		{
			res = ft_strndup(&av[0][i], nb + 1);
			++nb;
			if (!av[0][i + nb])
				i += nb;
		}
		else
			++i;
	}
	if (res)
		write(1, res, ft_strlen(res));
}

int				main(int ac, char **av)
{
	if (ac == 1)
		return (print_error(NULL));
	if (ac == 2)
		return (print_error(av[1]));
	str_maxlenoc(ac - 1, av + 1);
	write(1, "\n", 1);
	return (0);
}
