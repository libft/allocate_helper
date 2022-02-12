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

#ifndef ALLOCATE_HELPER_TYPES_H
# define ALLOCATE_HELPER_TYPES_H

# include <stddef.h>

typedef struct s_allocate_helper_item {
	void	*resource;
	void	(*cleaner)(void *resource);
}	t_allocate_helper_item;

/**
 * @brief allocate_helper instance
 */
typedef struct s_allocate_helper {
	size_t					length;
	size_t					capacity;
	t_allocate_helper_item	*array;
}	t_allocate_helper;

#endif
