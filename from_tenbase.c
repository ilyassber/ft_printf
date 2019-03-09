/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_tenbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 22:08:05 by iberchid          #+#    #+#             */
/*   Updated: 2018/12/27 20:41:32 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*tobase_str(int n, int size)
{
	char	*str;
	int		i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / size;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	return (str);
}

void	from_tenbase(int n, char *str, int index, t_base *base)
{
	if (str[index + 1] != '\0')
		from_tenbase((n / t_base->size), str, (index + 1), base);
	str[index] = (base->base)[n % (base->size)];
}
