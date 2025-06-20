/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFFER_H
# define BUFFER_H

# include <stdio.h>
# include <stdlib.h>

/** @brief Backend buffer for printf */
typedef struct s_buffer
{
	/** @brief Total number of written bytes */
	ssize_t	written_bytes;
	/** @brief The buffer */
	char	*buffer;
	/** @brief Maximum capacity for the buffer (for snprintf) */
	size_t	max_capacity;
	/** @brief Total byte capacity of the buffer */
	size_t	capacity;
	/** @brief Used up space in the buffer */
	size_t	size;
	/** @brief Backing file descriptor, may be -1 */
	int		fd;
}	t_buffer;

/**
 * @brief Initializes the buffer in file descriptor mode
 *
 * @param fd The file descriptor, must be valid
 * @param buf_size Internal buffer size for the file descriptor mode
 * (0 for unbuffered)
 */
void
printf_buffer_init_fd(t_buffer *buf, int fd, size_t buf_size);
/**
 * @brief Initializes the buffer with an external buffer
 *
 * @param buffer The buffer to use
 * @param max_capacity The buffer's maximum capacity (-1 for unlimited)
 */
void
printf_buffer_init_buffer(t_buffer *buf, char *buffer, size_t max_capacity);
/**
 * @brief Initializes the buffer in malloc modee
 *
 * @param initial_capacity Buffer's initial capacity
 */
void
printf_buffer_init_malloc(t_buffer *buf, size_t initial_capacity);
/**
 * @brief Writes to buffer
 *
 * @param buf Buffer to write to
 * @param s String to write in `buf`
 * @param len Length in bytes of `s`
 *
 * @returns The number of written bytes, -1 on error
 */
void
printf_buffer_write(t_buffer *buf, const void *s, size_t len);
/**
 * @brief Flushes the buffer
 *
 * In case file descriptors are not used, this function only returns the total
 * number of bytes written. For stdio's FILE*, the internal buffering of FILE*
 * is used. When used in buffer mode (e.g asprintf/sprintf), the trailing `\0`
 * is appended by this function.
 *
 * @param buf The buffer to flush
 *
 * @returns The number of written bytes
 */
ssize_t
printf_buffer_flush(t_buffer *buf);

#endif // printf_BUFFER_H
