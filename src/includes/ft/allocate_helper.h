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

/**
 * @brief create new allocate_helper instance
 *
 * @param capacity maximum number of calls to a function in scope
 * @return allocate_helper instance - must be manually freed
 */
t_allocate_helper	*new_allocate_helper(
						size_t capacity);

/**
 * @brief initialize allocate_helper from already items
 *
 * @param self allocate_helper instance to initialize
 * @param array used to initialize self
 * @param capacity length of array
 */
void				allocate_helper_init(
						t_allocate_helper *self,
						t_allocate_helper_item *array,
						size_t capacity);

/**
 * @brief main - helper
 *
 * @param self allocate_helper instance to initialize
 * @param dest address to store resource
 * @param resource resource to store, NULL if failed
 * @param cleaner function to clean resource,usually &free
 * @return true on error, false otherwise
 */
bool				allocate_helper(
						t_allocate_helper *self,
						void **dest,
						void *resource,
						void (*cleaner)(void *resource));

#endif
