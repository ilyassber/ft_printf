/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:05:20 by iberchid          #+#    #+#             */
/*   Updated: 2019/01/11 11:40:11 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*effect_minus(char *str)
{
	int		n;
	int		i;
	int		j;
	char	*new_str;

	n = ft_strlen(str);
	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (n + 1));
	while (str[i] == ' ')
		i++;
	while (j < n)
	{
		if (str[i] != '\0')
			new_str[j++] = str[i++];
		else
			new_str[j++] = ' ';
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*effect_plus(char *str)
{
	int		n;
	int		i;
	char	new_str;

	if (str[0] != '+')
	{
		n = ft_strlen(str);
		i = 0;
		new_str = (char *)malloc(sizeof(char) * (n + 2));
		new_str[i++] = '+';
		while (str[i - 1] != '\0')
			new_str[i] = str[i++ - 1];
		new_str[i] = '\0';
		return (new_str);
	}
	else
		return (str);
}

char	*effect_space(char *str)
{
	int		n;
	int		i;
	char	new_str;

	if (str[0] != '-')
	{
		n = ft_strlen(str);
		i = 0;
		new_str = (char *)malloc(sizeof(char) * (n + 2));
		new_str[i++] = ' ';
		while (str[i - 1] != '\0')
			new_str[i] = str[i++ - 1];
		new_str[i] = '\0';
		return (new_str);
	}
	else
		return (str);
}

void	*effect_zero(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		str[i++] = '0';
	if (str[i] == '-' || str[i] == '+')
	{
		str[0] = str[i];
		str[i] = '0';
	}
}

char	*effect_hash(char *str, char flag)
{
	int		n;
	int		i;
	int		j;
	char	*new_str;

	n = ft_strlen(str);
	i = 0;
	if (flag == 'o')
		new_str = (char *)malloc(sizeof(char) * (n + 2));
	else
		new_str = (char *)malloc(sizeof(char) * (n + 3));
	new_str[i++] = 0;
	if (flag == 'x')
		new_str[i++] = 'x';
	if (flag == 'X')
		new_str[i++] = 'X';
	while (str[j] != '\0')
		new_str[i] = str[j];
	new_str[i] = '\0';
	return (new_str);
}
