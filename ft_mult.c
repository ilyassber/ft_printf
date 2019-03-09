/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:25:14 by iberchid          #+#    #+#             */
/*   Updated: 2019/02/27 21:19:22 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float.h"

char	*mult(char *p1, int n, int i)
{
	int		x;
	int		keep;
	int		mul;
	char	*sum;

	x = 0;
	keep = 0;
	while (p1[x])
		x++;
	sum = (char *)malloc(sizeof(char) * (x + 2 + i));
	x = 0;
	while (x < i)
		sum[x++] = '0';
	while (p1[x - i])
	{
		mul = (((int)p1[x - i] - '0') * n) + keep;
		keep = mul / 10;
		sum[x++] = (char)((mul % 10) + '0');
	}
	sum[x] = (char)(keep + '0');
	sum[x + 1] = '\0';
	return (sum);
}

char	*ft_mult(char *p1, char *p2)
{
	int		i;
	char	*sum;
	char	*total;

	i = 0;
	total = ft_add("0", "0");
	while (p2[i])
	{
		sum = mult(p1, ((int)p2[i] - '0'), i);
		total = ft_add(total, sum);
		free(sum);
		i++;
	}
	//i = ft_strlen(total);
	//i--;
	//while (total[i] == '0' && i > 0)
	//	total[i] = '\0';
	return (total);
}
