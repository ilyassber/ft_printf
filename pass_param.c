/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:24:33 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/14 20:23:43 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_l(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int		parse_param(t_param *param, int i)
{
	int	j;

	j = 0;
	if (is_flag(param->str[i]))
		param->flag[0] = param->str[i++];
	else if ((param->precis = is_precis(param->str[i]))
			&& param->precis == 1)
		i++;
	else if (param->str[i] != '*' && is_width(param->str[i]))
	{
		param->precis = atoi(str[i]);
		i = i + is_width(param->str[i]);
	}
	else if (param->str[i] == '*' && (param->scan = 2))
		param->star[0] = param->str[i++];
	else if (is_length(param->str[i]) || is_type(param->str[i]))
	{
		while (is_length(param->str[i]))
			param->length[j++] = param->str[i++];
		param->type[0] = param->str[i++];
	}
	return (i);
}

void	scan_param(t_param *param)
{
	int	i;
	int	n;

	i = 0;
	n = 1
	while (param->str[i] == '%')
		i++;
	if (i > 1)
	{
		while (n <= (i / 2))
			param->str[i - n++] = '\0';
		param->scan = 0;
	}
	else
	{
		while (param->str[i] != '\0')
			i = parse_param(param, i);
	}
}	

void	pass_param(t_param *param, char *data, int length)
{
	int	i;

	i = 0;
	param->str = (char *)malloc(sizeof(char) * (length + 1));
	while (i < length)
		param->str[i] = data[i++];
	param->str[i] = '\0';
	if (data[0] != '%')
		param->scan = 0;
	else
	{
		param->scan = 1;
		scan_param(param);
	}
}
