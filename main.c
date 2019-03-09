/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:33:30 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/14 02:56:03 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	main()
{
	//double	d = 16516516516516;
	//int	n = 61516;
	//char c = ' ';
	//short int	i = 200;
	//long int	l = 10241024;
	//long long int ll = 10241024;
	//char str[50] = "werwe6546i5we%%qw;elq'%#.2c%%%%sdfsfd%c";
	//ft_putnbr(alpha_parser(str));
	const char	c[20] = "%.*s %.*s\n";
	printf(c, 2, "abc", 3, "abc");
	//ft_putnbr(is_special('%'));
	return (0);
}
