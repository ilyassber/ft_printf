/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:15:06 by iberchid          #+#    #+#             */
/*   Updated: 2019/02/27 21:19:58 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float.h"

char	*sum_str(char *p1, char *p2)
{
	char	*sum;
	int		n;
	int		i;

	i = 0;
	if (ft_strlen(p1) > ft_strlen(p2))
		n = ft_strlen(p1) + 2;
	else
		n = ft_strlen(p2) + 2;
	sum = (char *)malloc(sizeof(char) * n);
	sum[n - 1] = '\0';
	while (p1[i] != '\0')
	{
		sum[i] = p1[i];
		i++;
	}
	while (i < (n - 1))
		sum[i++] = '0';
	return (sum);
}

char	*ft_add(char *p1, char *p2)
{
	char	*sum;
	int		keep;
	int		rest;
	int		n;

	sum = sum_str(p1, p2);
	keep = 0;
	n = 0;
	while (p2[n] != '\0')
	{
		rest = ((int)sum[n] + (int)p2[n] - 96 + keep) % 10;
		keep = ((int)sum[n] + (int)p2[n] - 96 + keep) / 10;
		sum[n] = (char)(rest + 48);
		n++;
	}
	if (keep > 0)
		sum[n++] = (char)(keep + 48);
	sum[n] = '\0';
	while (sum[n - 1] == '0' && n > 1)
		sum[n-- - 1] = '\0';
	return (sum);
}
