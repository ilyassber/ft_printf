/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:34:18 by iberchid          #+#    #+#             */
/*   Updated: 2019/03/08 21:46:02 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float.h"

char	*ft_pow(int n)
{
	char	*s;

	if (n == 0)
		return ("1");
	if (n == 1)
		return ("2");
	if (n % 2 == 0)
	{
		if (n / 2 == 1)
			return (ft_mult("2", "2"));
		else
		{
			s = ft_pow(n / 2);
			return (ft_mult(s, s));
		}
	}
	else
	{
		if (n / 2 == 1)
			return (ft_mult(ft_mult("2", "2"), "2"));
		else
		{
			s = ft_pow((n - 1) / 2);
			return (ft_mult(ft_mult(s, s), "2"));
		}
	}
}
