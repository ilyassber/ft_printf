/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:01:32 by iberchid          #+#    #+#             */
/*   Updated: 2018/12/24 14:51:26 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*base_xx(int max, char c)
{
	char	*base;
	int		i;
	int		j;

	base = (char *)malloc(sizeof(char) * (max + 1));
	i = (int)c;
	j = -1;
	while (++j < max)
	{
		if (i == 58)
			i = 97;
		base[j] = (char)i++;
	}
	base[max] = '\0';
	return (base);
}
