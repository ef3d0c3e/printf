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
#include "util.h"
#include <stddef.h>
#include <unistd.h>

/** @brief Buffered write to file descriptor */
static inline void
	write_fd_buffered(t_buffer *buf, const char *s, size_t len)
{
	ssize_t	ret;
	size_t	written;
	size_t	to_write;

	written = 0;
	while (written != len)
	{
		to_write = len - written;
		if (to_write + buf->size >= buf->capacity)
			to_write = buf->capacity - buf->size;
		printf_memcpy_unaligned(buf->buffer + buf->size, s + written, to_write);
		written += to_write;
		buf->size += to_write;
		if (buf->size == buf->capacity)
		{
			ret = write(buf->fd, buf->buffer, buf->capacity);
			if (ret != -1)
				buf->written_bytes += ret;
			buf->size = 0;
		}
	}
	buf->written_bytes += written;
}


void
	printf_buffer_write(t_buffer *buf, const char *s, size_t len)
{
	size_t	new_capacity;
	ssize_t	ret;

	if (buf->file)
		buf->written_bytes += fwrite(buf, 1, len, buf->file);
	else if (buf->fd != -1)
	{
		if (buf->buffer)
			write_fd_buffered(buf, s, len);
		else
		{
			ret = write(buf->fd, s, len);
			if (ret != -1)
				buf->written_bytes += ret;
		}
	}
	else
	{
		new_capacity = buf->capacity + 256 * !buf->capacity;
		while (new_capacity < buf->size + len)
			new_capacity <<= 2;
		buf->buffer = printf_realloc(buf->buffer, buf->capacity, new_capacity);
		printf_memcpy_unaligned(buf->buffer + buf->size, s, len);
		buf->size += len;
		buf->written_bytes += len;
		buf->capacity = new_capacity;
	}
}

ssize_t
	printf_buffer_flush(t_buffer *buf)
{
	ssize_t	ret;

	if (buf->fd != -1 && buf->size)
	{
		ret = write(buf->fd, buf->buffer, buf->size);
		if (ret != -1)
			buf->written_bytes += ret;
	}
	return (buf->written_bytes);
}
