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

#include <stdlib.h>
#include <ft/allocate_helper.h>

#include "new_allocate_helper.h"

t_allocate_helper	*new_allocate_helper(size_t capacity)
{
	t_allocate_helper_new	*result;

	result = (t_allocate_helper_new *)malloc(0
			+ sizeof(t_allocate_helper_new)
			+ sizeof(t_allocate_helper_item) * capacity);
	if (!result)
		return (NULL);
	allocate_helper_init(&result->original, result->array, capacity);
	return ((t_allocate_helper *)result);
}
