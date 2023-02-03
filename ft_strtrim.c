/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:22:58 by mjina             #+#    #+#             */
/*   Updated: 2023/01/17 16:23:00 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lasttrim(char const *s1, char const *set)
{
	int	cstr;
	int	ctrim;

	cstr = ft_strlen(s1);
	ctrim = ft_strlen(set);
	while (ctrim != -1)
	{
		if (set[ctrim] == s1[cstr])
		{
			cstr--;
			ctrim = ft_strlen(set);
		}
		ctrim--;
	}
	return (cstr);
}

static int	firsttrim(char const *s1, char const *set)
{
	int	cstr;
	int	ctrim;

	cstr = 0;
	ctrim = ft_strlen(set);
	while (ctrim != -1)
	{
		if (set[ctrim] == s1[cstr])
		{
			cstr++;
			ctrim = ft_strlen(set);
		}
		ctrim--;
	}
	return (cstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		first;
	int		last;
	int		num;

	first = firsttrim(s1, set);
	last = ft_strlen(s1) - lasttrim(s1, set) - 1;
	num = first + last;
	if (first >= ft_strlen(s1))
	{
		str = malloc(sizeof(char));
		return (str);
	}
	if (ft_strlen(s1) <= num)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) - num + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + first, (size_t)ft_strlen(s1) - num + 1);
	return (str);
}
