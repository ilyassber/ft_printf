/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:49:46 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/24 12:17:23 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_list	*new_list(char *str, size_t fd)
{
	t_file	*file;
	t_list	*list;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	file->index = 0;
	file->str = str;
	list->content = file;
	list->content_size = fd;
	list->next = NULL;
	return (list);
}

static t_file	*get_file(t_list *list, size_t fd)
{
	t_file	*file;
	t_list	*data;

	data = list;
	while ((data->content_size != fd) && (data->next != NULL))
		data = data->next;
	if (data->content_size == fd)
		file = (t_file *)data->content;
	else
		file = NULL;
	return (file);
}

static char		*generate(char *line, char c)
{
	int		i;
	int		j;
	char	*string;

	if (line != NULL)
		i = ft_strlen(line);
	else
		i = 0;
	j = 0;
	if (!(string = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	while ((j < i) && (i > 0))
	{
		string[j] = line[j];
		j++;
	}
	string[j++] = c;
	string[j] = '\0';
	free(line);
	return (string);
}

static int		get_str(char **line, t_file *file, int fd, int error)
{
	if (file->str[file->index] == '\0' && ft_strlen(*line) == 0)
		return (0);
	if ((file->str)[file->index] == '\n' || (file->str)[file->index] == '\0')
	{
		if ((file->str)[file->index] == '\n')
			(file->index)++;
		if ((file->str)[file->index] == '\0')
		{
			ft_memset((file->str), '\0', BUFF_SIZE);
			error = read(fd, (file->str), BUFF_SIZE);
			(file->index) = 0;
		}
		return (1);
	}
	if ((file->index) < BUFF_SIZE)
		*line = generate(*line, (file->str)[(file->index)++]);
	if ((file->index) == BUFF_SIZE)
	{
		ft_memset((file->str), '\0', BUFF_SIZE);
		error = read(fd, (file->str), BUFF_SIZE);
		file->index = 0;
	}
	error = get_str(line, file, fd, error);
	return (error);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*data;
	char			*str;
	int				n;

	n = 1;
	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	*line = ft_strdup("");
	if (!(str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (data == NULL)
	{
		if (read(fd, str, BUFF_SIZE) == (-1))
			return (-1);
		data = new_list(str, (size_t)fd);
	}
	if (!(get_file(data, fd)))
	{
		if (read(fd, str, BUFF_SIZE) == (-1))
			return (-1);
		ft_lstadd(&data, new_list(str, fd));
	}
	return (get_str(line, get_file(data, fd), fd, n));
}
