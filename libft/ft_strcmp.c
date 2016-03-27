/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:15:40 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:54:11 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-s2[0]);
	if (!s2)
		return (s1[0]);
	i = 0;
	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	while (s1b[i] == s2b[i])
	{
		if (!s1b[i])
			return (0);
		i++;
	}
	return (s1b[i] - s2b[i]);
}
