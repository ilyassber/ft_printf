/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 05:28:39 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/14 05:51:01 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	print_ints(const char *str, ...)
{
	char	*num;
	const char	*value;
	const char	*data;
	int		n;
	va_list args;

	num = (char	*)malloc(sizeof(char) * 2);
	num[0] = '0';
	num[1] = 'b';
	//num[2] = 'c';
	//num[3] = 'd';
	printf("%d\n", *num);
	value = str;
	n = 0;
	va_start(args, (int)str);
	while (n < (int)*str)
	{
		data = va_arg(args, const char*);
		printf("%d: %s\n", n, data);
		n++;
	}
	va_end(args);
}

int		main()
{
	print_ints("asd", "sad");
	print_ints("asa", "qwq");
	return (0);
}
