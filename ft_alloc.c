/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:22:03 by iberchid          #+#    #+#             */
/*   Updated: 2019/02/12 22:57:37 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_num	new_digit(int n)
{
	t_num	*digit;

	digit = (t_num *)malloc(sizeof(t_num));
	digit->digit = (char)(48 + n);
	digit->back = NULL;
	digit->next = NULL;
	return (digit);
}
