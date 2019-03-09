/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:01:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/03/09 10:22:08 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_printf.h"

void	char_to_bit(unsigned char c, char *s)
{
	int	i;
	int	n;
	int	x;

	i = 128;
	n = 7;
	x = (int)c;
	while (n >= 0)
	{
		if (x / i == 1)
			s[n] = '1';
		else
			s[n] = '0';
		x = x % i;
		i = i / 2;
		n--;
	}
}

char	*bit_to_int(char *s, int n)
{
	int		i;
	char	*sum;
	char	*coef;

	i = 0;
	sum = ft_add("0", "0");
	coef = ft_add("1", "0");
	while (i < n)
	{
		if (s[i] == '1')
			sum = ft_add(sum, coef);
		coef = ft_mult(coef, "2");
		i++;
	}
	return (sum);
}

char	*bit_to_mant(char *s, int n)
{
	char	*sum;
	char	*coef;

	sum = ft_add("01", "0");
	coef = ft_add("5", "0");
	while (n >= 0)
	{
		if (s[n] == '1')
			sum = ft_add(coef, sum);
		coef = ft_mult(coef, "5");
		sum = ft_mult(sum, "01");
		n--;
	}
	return (sum);
}

int		get_exp(char *str, int l, int max)
{
	char	*exp;
	char	*rev;
	int		n;

	exp = bit_to_int(str, l);
	rev = ft_rev(exp);
	n = ft_atoi(rev);
	free(exp);
	return (n - ((max - 1) / 2));
}
