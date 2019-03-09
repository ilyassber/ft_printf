/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:06:46 by iberchid          #+#    #+#             */
/*   Updated: 2019/03/09 11:16:25 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_printf.h"

void	cut_zero(char *s)
{
	size_t	n;
	size_t	i;

	n = ft_strlen(s);
	i = 0;
	while (n > 1 && s[n - 1] == '0')
	{
		s[n - 1] = '\0';
		n--;
	}
}

char	*ft_rev(char *str)
{
	int		i;
	int		n;
	char	*s;

	n = 0;
	if (str)
	{
		i = ft_strlen(str);
		if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while (i > 0)
			s[n++] = str[(i--) - 1];
		s[n] = '\0';
		return (s);
	}
	return (NULL);
}

char	*one_in_right(char *s)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (n + 2));
	str[n + 1] = '\0';
	while (i < n)
		str[i] = s[i++];
	str[n] = '1';
	return (str);
}
