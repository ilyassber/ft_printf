/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:10:16 by iberchid          #+#    #+#             */
/*   Updated: 2019/03/08 21:58:20 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_param
{
	int		scan;
	char	*str;
	char	flag[2];
	char	star[1];
	int		width;
	int		precis;
	char	length[2];
	char	type[1];
	void	*param;
	struct s_param *next;
	struct s_param *back;
}				t_param;

typedef struct	s_base
{
	char		*base;
	int			size;
}				t_base;

typedef struct	s_convert
{
	char	f1;
	char	f2;
	int		m1;
	int		m2;
}				t_convert;

typedef	struct	s_num
{
	char			digit;
	struct	s_num	*back;
	struct	s_num	*next;
}				t_num;

//int				alpha_parser(char *str);
int				is_special(char c);
int				is_many(char *str);
int				is_type(char c);
char			*base_xx(int max);
int				get_class(char *str, char c);
void			pass_param(t_param *param, char *data, int length);
//t_param			alpha_parser(char *str);
int				dist_param(t_param *param, void *data);
char			*ft_rev(char *str);
int				get_exp(char *str, int l, int max);

#endif
