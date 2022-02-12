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

#ifndef ALLOCATE_HELPER_H
# define ALLOCATE_HELPER_H

# include <stddef.h>
# include <stdbool.h>

# include "allocate_helper_types.h"

t_allocate_helper	*new_allocate_helper(
						size_t capacity);
void				allocate_helper_init(
						t_allocate_helper *self,
						t_allocate_helper_item *array,
						size_t capacity);

bool				allocate_helper(
						t_allocate_helper *self,
						void **dest,
						void *resource,
						void (*cleaner)(void *resource));
void				*allocate_helper_free(
						t_allocate_helper *self,
						void *value);

#endif
