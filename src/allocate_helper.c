/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <ft/allocate_helper.h>

bool	allocate_helper(
	t_allocate_helper *self,
	void **dest,
	void *resource,
	void (*cleaner)(void *resource)
)
{
	size_t	i;

	if (self->length + 1 >= self->capacity || !resource)
	{
		if (resource)
			cleaner(resource);
		i = 0;
		while (i < self->length)
		{
			self->array[i].cleaner(self->array[i].resource);
			i++;
		}
		self->length = 0;
		return (true);
	}
	*dest = resource;
	self->array[self->length].resource = resource;
	self->array[self->length].cleaner = cleaner;
	self->length++;
	return (false);
}
