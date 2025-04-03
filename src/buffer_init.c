/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "buffer.h"

void
	printf_buffer_init_fd(t_buffer *buf, int fd, size_t buf_size)
{
	buf->written_bytes = 0;
	buf->size = 0;
	buf->capacity = buf_size;
	buf->buffer = NULL;
	if (buf->capacity)
		buf->buffer = malloc(buf->capacity);
	buf->fd = fd;
	buf->file = NULL;
}
void
	printf_buffer_init_stdio(t_buffer *buf, FILE *file)
{
	buf->written_bytes = 0;
	buf->size = 0;
	buf->capacity = 0;
	buf->buffer = NULL;
	buf->fd = -1;
	buf->file = file;
}

void
	printf_buffer_init_malloc(t_buffer *buf, size_t initial_capacity)
{
	buf->written_bytes = 0;
	buf->size = 0;
	buf->capacity = initial_capacity;
	buf->buffer = NULL;
	if (buf->capacity)
		buf->buffer = malloc(buf->capacity);
	buf->fd = -1;
	buf->file = NULL;
}
