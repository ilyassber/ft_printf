/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:41:09 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/12 15:00:56 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '-' || c = '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	else
		return (0);
}

int	is_precis(char c)
{
	if (c == '.')
		return (1);
	else
		return (0);
}

int	is_width(char *s)
{
	int	n;

	n = 0;
	while (ft_isdigit(s[n]))
		n++;
	return (n);
}

int	is_length(char *s)
{
	int	n;

	n = 0;
	while (s[n] == 'h' || s[n] == 'l' || s[n] == 'L')
		n++;
	return (n);
}

int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}
