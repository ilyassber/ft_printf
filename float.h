/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:57:38 by iberchid          #+#    #+#             */
/*   Updated: 2019/03/08 21:31:02 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_H
# define FLOAT_H

#include <stdio.h>
#include <stdlib.h>

typedef	union	u_fdata
{
	float			u_f;
	unsigned char	u_flt[4];
}				t_fdata;

typedef	union	u_ddata
{
	double			u_d;
	unsigned char	u_dbl[8];
}				t_ddata;

typedef	union	u_lddata
{
	long double		u_ld;
	unsigned char	u_ldbl[16];
}				t_lddata;

void			char_to_bit(unsigned char c, char *s);
char			*ft_mult(char *p1, char *p2);
char			*ft_add(char *p1, char *p2);
char			*bit_to_int(char *s, int n);
void			cut_zero(char *s);
char			*bit_to_mant(char *s, int n);
char			*ft_pow(int n);

#endif
