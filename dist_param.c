/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 02:30:39 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/14 20:23:47 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dist_param(t_param *param, void *data)
{
	if (param->scan == 2)
	{
		param->width = (int)*data;
		param->scan = 1;
		return (0);
	}
	else if (param->scan == 1)
	{
		param->param = data;
		param->scan = 3;
	}
	return (1);
}
