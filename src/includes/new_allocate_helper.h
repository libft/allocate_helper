/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_allocate_helper.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:12:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/02/12 21:52:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_ALLOCATE_HELPER_H
# define NEW_ALLOCATE_HELPER_H

# include <ft/allocate_helper_types.h>

typedef struct s_allocate_helper_new {
	t_allocate_helper		original;
	t_allocate_helper_item	array[];
}	t_allocate_helper_new;

#endif
