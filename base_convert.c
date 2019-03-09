/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:49:32 by iberchid          #+#    #+#             */
/*   Updated: 2018/12/25 21:01:54 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_class(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

char	update_str(char *str, char c)
{
	int		i;
	char	new_str;

	i = 0;
	if (!(str))
	{
		str = (char	*)malloc(sizeof(char));
		str[0] = '\0';
	}
	while (str[i] != '\0')
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 2));
	new_str[i + 1] = '\0';
	new_str[i] = c;
	while (--i >= 0)
		new_str[i] = str[i];
	free(str);
	return (new_str);
}

char	base_convert(char *str, t_convert *convert)
{
	char	base1;
	char	base2;

	base1 = base_xx(convert->m1, convert->f1);
	base2 = base_xx(convert->m2, convert->f2);
}
