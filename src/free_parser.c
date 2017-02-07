/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:22:34 by mbarbari          #+#    #+#             */
/*   Updated: 2017/02/07 15:20:49 by mbarbari         ###   ########.fr       */
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
		dprintf(1, "Liberation de la cle : %s\n", obj->key);
		if (obj->value.type == TYPE_OBJECT)
			json_free(obj->value);
		next = obj->next;
		free(obj);
 		obj = next;
	}
}
