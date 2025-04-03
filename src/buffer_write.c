/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "buffer.h"

void
	printf_buffer_write(t_buffer *buf, const char *s, size_t len)
{
	size_t	written;

	if (buf->file)
		buf->written_bytes += fwrite(buf, 1, len, buf->file);
	else if (buf->fd != -1)
	{
		
	}
	else
	{

	}
}
