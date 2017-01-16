/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:23:33 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 12:15:39 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_value		json_get(t_json *x, char *str)
{
	t_value	value;
	char	*split;

	while (x != NULL)
	{
		split = ft_strchr(str, '.');
		if (split == NULL && ft_strcmp(str, x->key) == 0)
			return (x->value);
		else if (split != NULL && ft_strncmp(str, x->key, split - str) == 0)
			return (json_get(x->value.data.obj, split + 1));
		x = x->next;
	}
	value.error = TYPE_ERROR;
	return (value);
}

void		json_foreach_obj(t_json *x, void (cb)(t_value, char *s, void*),
	void *a)
{
	while (x != NULL)
	{
		(cb)(x->value, x->key, a);
		x = x->next;
	}
}

void		json_foreach_arr(t_json_arr *x, void (cb)(t_value, int, void*),
	void *a)
{
	int i;

	i = 0;
	while (x != NULL)
	{
		(cb)(x->value, i, a);
		x = x->next;
		i++;
	}
}

int			json_arr_length(t_json_arr *x)
{
	int i;

	i = 0;
	while (x != NULL)
	{
		x = x->next;
		i++;
	}
	return (i);
}
