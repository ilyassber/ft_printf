/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:06:12 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/14 20:23:51 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_param	*param;
	t_param	*next;
	void	*data;

	va_start(args, format);
	param = alpha_parser((char*)format);
	next = param->next;
	while (next != NULL || param->scan == 1)
	{
		data = va_arg(args, void*);
		if (dist_param(param, data))
			param = param->next;
		next = param->next;
	}
	va_end(args);
	return (0);
}

int	main()
{
	long int	x;
	short int	i;
	float	x_float;
	double i_float;
	long double	j_float;
	int	n;
	int	m;

	x_float = 52.3165;
	i_float = 11111111112233445566778899565454946.654646599;
	j_float = 11111111112233445566778899565454946.654646599;
	i = 32767;
	x = 65456465;
	n = -3123;
	m = 4654;
	printf("% *d\n", 9, n);
	printf("% d\n", 556);
	printf("%*d\n", 10, m);
	printf("%d\n", m);
	printf("%.*s\n", 3, "abcdef");
	printf("%hd\n", i);
	printf("%f\n", x_float);
	printf("%lf\n", i_float);
	printf("%Lf\n", j_float);
	return (0);
}
