/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:06:15 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:06:15 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (treat_args(env, ac, av) == 0)
		launch_fractol(env);
	return (0);
}
