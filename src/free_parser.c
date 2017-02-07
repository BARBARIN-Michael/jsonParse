/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:22:34 by mbarbari          #+#    #+#             */
/*   Updated: 2017/02/07 14:50:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stream.h"
#include "libft.h"

void		json_free(t_value value)
{
	t_json		*obj;
	t_json_arr	*arr;
	void		*next;

	obj = value.data.obj;
	arr = value.data.arr;
	while (obj)
	{
		next = obj->next;
		free(obj);
		obj = next;
	}
	while (arr)
	{
		next = arr->next;
		free(arr);
		arr = next;
	}
}
