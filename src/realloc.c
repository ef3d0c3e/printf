/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "util.h"

void
	*printf_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size <= original_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr)
		printf_memcpy_aligned(new_ptr, ptr, original_size);
	free(ptr);
	return (new_ptr);
}
