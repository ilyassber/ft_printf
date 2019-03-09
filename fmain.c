/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:14:45 by iberchid          #+#    #+#             */
/*   Updated: 2019/03/09 11:32:20 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_printf.h"

int main()
{
	int		i;
	int		n;
	char	*s;
	t_fdata	fdata;

	i = 0;
	n = 0;
	s = (char*)malloc(sizeof(char) * 33);
	s[32] = '\0';
	fdata.u_f = 28;
	while (n < 4)
	{
		char_to_bit(fdata.u_flt[n], (s + i));
		i += 8;
		n++;
	}
	//printf("%f\n%s\n%s\n", fdata.u_f, fdata.u_flt, s);
	//printf("%s\n", bit_to_mant(s, 22));
	//printf("%s\n", ft_mult("888000", "5"));
	//printf("----------\n%s\n", ft_pow(16383));//16383
	//printf("%d\n", get_exp((s + 23), 8, 255));
	printf("%o\n", fdata.u_f);
	return (0);
}
