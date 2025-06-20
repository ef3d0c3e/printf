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
			buf->written_bytes += ret * (ret != -1);
			buf->size = 0;
		}
	}
	buf->written_bytes += written;
}

/** @brief Write and truncate */
static inline void
	write_truncated(t_buffer *buf, const char *s, size_t len)
{
	const size_t	total = len + buf->size;
	size_t			to_write;

	if (!buf->max_capacity)
	{
		buf->written_bytes += len;
		return ;
	}
	if (total + 1 >= buf->max_capacity)
	{
		to_write = len - (total - buf->max_capacity);
		if (to_write)
			printf_memcpy_unaligned(buf->buffer + buf->size, s, to_write);
		buf->written_bytes += len;
		buf->size = buf->max_capacity - 1;
	}
	else
	{
		printf_memcpy_unaligned(buf->buffer + buf->size, s, len);
		buf->written_bytes += len;
		buf->size += len;
	}
}

/** @brief Write to dynamiocally resizeable array */
static inline void
	write_dynamic(t_buffer *buf, const char *s, size_t len)
{
	size_t	new_capacity;

	new_capacity = buf->capacity + 256 * !buf->capacity;
	while (new_capacity < buf->size + len + 1)
		new_capacity <<= 1;
	buf->buffer = printf_realloc(buf->buffer, buf->capacity, new_capacity);
	if (buf->buffer)
		printf_memcpy_unaligned(buf->buffer + buf->size, s, len);
	buf->size += len;
	buf->written_bytes += len;
	buf->capacity = new_capacity;
}

void
	printf_buffer_write(t_buffer *buf, const void *s, size_t len)
{
	ssize_t	ret;

	if (buf->fd != -1 && buf->buffer)
		write_fd_buffered(buf, s, len);
	else if (buf->fd != -1)
	{
		ret = write(buf->fd, s, len);
		buf->written_bytes += ret * (ret != -1);
	}
	else if (!buf->max_capacity || buf->max_capacity != (size_t) - 1)
		write_truncated(buf, s, len);
	else
		write_dynamic(buf, s, len);
}

ssize_t
	printf_buffer_flush(t_buffer *buf)
{
	ssize_t	ret;

	if (buf->fd != -1 && buf->buffer && buf->size)
	{
		ret = write(buf->fd, buf->buffer, buf->size);
		buf->written_bytes += ret * (ret != -1);
	}
	else if (buf->fd == -1)
		buf->buffer[buf->size] = 0;
	if (buf->capacity)
		free(buf->buffer);
	return (buf->written_bytes);
}
