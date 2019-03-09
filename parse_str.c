/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:09:44 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/14 20:23:38 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_prc(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '%')
		i++;
	return (i);
}

int	get_next(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] != '%')
		j = 1;
	while (str[i] != '\0')
	{
		if (j == 1 && str[i] == '%')
			return (i);
		else if (j == 0 && ((str[i] != 'l' && str[i] != 'L' && is_type(str[i]))
				|| count_prc(str + i) > 1))
		{
			if (count_prc(str + i) % 2 == 0 && count_prc(str + i) >= 2)
				return (i + count_prc(str + i));
			if (count_prc(str + i) > 2)
				return (i + count_prc(str + i) - 1);
			else
				return (i + 1);
		}
		i++;
	}
	return (i);
}

t_param	new_param()
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	param->next = (t_param *)malloc(sizeof(t_param));
	param->next = (t_param *)malloc(sizeof(t_param));
	param->next = NULL;
	param->back = NULL;
	return (param);
}

t_param	alpha_parser(char *str)
{
	int		n;
	int		i;
	t_param	*param;
	t_param	*back;
	t_param	*first;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (n > 0)
		{
			param->next = new_param();
			param = param->next;
			param->back = back;
		}
		else
			param = new_param();
		back = param;
		if (n == 0)
			first = param;
		pass_param(param, (str + i), get_next(str + i));
		i = i + get_next(str + i);
		n++;
	}
	return(first);
}
