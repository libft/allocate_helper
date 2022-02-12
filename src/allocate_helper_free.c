/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_helper_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:12:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/02/12 22:05:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft/allocate_helper.h>

void	*allocate_helper_free(t_allocate_helper *self, void *value)
{
	free(self);
	return (value);
}
