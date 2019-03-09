/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 10:34:02 by iberchid          #+#    #+#             */
/*   Updated: 2019/03/09 10:52:34 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_bit_str(float f)
{
	int		i;
	int		n;
	char	*s;
	t_fdata	fdata;

	i = 0;
	n = 0;
	s = (char *)malloc(sizeof(char) * 33);
	s[32] = '\0';
	fdata.u_f = f;
	while (n < 4)
	{
		char_to_bit(fdata.u_lft[n], (s + i));
		i += 8;
		n++;
	}
	return (s);
}
