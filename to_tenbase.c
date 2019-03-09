/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_tenbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:30:27 by iberchid          #+#    #+#             */
/*   Updated: 2018/12/27 20:42:01 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		to_tenbase(char *str, char *base)
{
	int	sum;
	int	i;
	int	length;

	sum = 0;
	i = 0;
	length = ft_strlen(base);
	while (str[i] != '\0')
		sum = (sum * length) + get_class(base, str[i++]);
	return (sum);
}
