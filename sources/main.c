/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:36:01 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/27 21:38:39 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	int		ret;

	ret = 0;
	if (argc == 2)
		ret = launch_it(argv[1]);
	if (!ret)
	{
		ft_putstr("Erreur Args. Veuillez passer en parametre une map valide\n");
	}
	return (0);
}
