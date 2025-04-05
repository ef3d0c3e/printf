/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

/******************************************************************************/
/* Printf file descriptor                                                     */
/******************************************************************************/

/**
 * @brief Printf function using unistd's `write` to stdout's file descriptor
 *
 * @param format The format string
 * @param ... Parameters to format
 *
 * @returns The number of written bytes
 */
ssize_t
ft_printf(
	const char *restrict format,
	...);
/**
 * @brief Printf function using unistd's `write` to stdout's file descriptor
 *
 * @param format The format string
 * @param ap Parameters to format
 *
 * @returns The number of written bytes
 */
ssize_t
ft_vprintf(
	const char *restrict format,
	va_list ap);
/**
 * @brief Printf function using unistd's `write`
 *
 * @param fd File descriptor to write to
 * @param format The format string
 * @param ... Parameters to format
 *
 * @returns The number of written bytes
 */
ssize_t
ft_dprintf(
	int fd,
	const char *restrict format,
	...);
/**
 * @brief Printf function using unistd's `write`
 *
 * @param fd File descriptor to write to
 * @param format The format string
 * @param ap Parameters to format
 *
 * @returns The number of written bytes
 */
ssize_t
ft_vdprintf(
	int fd,
	const char *restrict format,
	va_list ap);

/******************************************************************************/
/* Printf external buffer                                                     */
/******************************************************************************/

/**
 * @brief Writes formatted output to a given buffer
 *
 * This function will write a terminating `\0` at the end of the output buffer.
 *
 * @note This function does not perform bounds checking, you need to be sure
 * that the `str` is sufficiently large to hold the formatted output.
 * Usage of this function is discouraged, instead use the `ft_snprintf`
 * (fixed size) or `ft_asprintf` (dynamically allocated string) variants.
 *
 * @param str The buffer to write to (needs to be large enough)
 * @param format The format string
 * @param ... Parameters to format
 *
 * @returns The number of written bytes
 */
ssize_t
ft_sprintf(
	char *restrict str,
	const char *restrict format,
	...);
/**
 * @brief Writes formatted output to a given buffer
 *
 * This function will write a terminating `\0` at the end of the output buffer.
 *
 * @note This function does not perform bounds checking, you need to be sure
 * that the `str` is sufficiently large to hold the formatted output.
 * Usage of this function is discouraged, instead use the `ft_snprintf`
 * (fixed size) or `ft_asprintf` (dynamically allocated string) variants.
 *
 * @param str The buffer to write to (needs to be large enough)
 * @param format The format string
 * @param ap Parameters to format
 *
 * @returns The number of written bytes
 */
ssize_t
ft_vsprintf(
	char *restrict str,
	const char *restrict format,
	va_list ap);
/**
 * @brief Writes formatted output to a given sized buffer
 *
 * This function will write a most `size - 1` bytes, leaving 1 byte for the
 * terminating `\0`.
 *
 * @note In case the buffer is not large enough to hold the formatted output,
 * it will be truncated to `size - 1` bytes (leaving 1 byte for the `\0`).
 * The returned value will be the required length to hold the entire formatted
 * output.
 *
 * @param str The buffer to write to
 * @param size Size of the output buffer `str`
 * @param format The format string
 * @param ... Parameters to format
 *
 * @returns The number of bytes required to entirely write the output stream
 */
ssize_t
ft_snprintf(
	char *restrict str,
	size_t size,
	const char *restrict format,
	...);
/**
 * @brief Writes formatted output to a given sized buffer
 *
 * This function will write a most `size - 1` bytes, leaving 1 byte for the
 * terminating `\0`.
 *
 * @note In case the buffer is not large enough to hold the formatted output,
 * it will be truncated to `size - 1` bytes (leaving 1 byte for the `\0`).
 * The returned value will be the required length to hold the entire formatted
 * output.
 *
 * @param str The buffer to write to
 * @param size Size of the output buffer `str`
 * @param format The format string
 * @param ap Parameters to format
 *
 * @returns The number of bytes required to entirely write the output stream
 */
ssize_t
ft_vsnprintf(
	char *restrict str,
	size_t size,
	const char *restrict format,
	va_list ap);

/******************************************************************************/
/* Printf internal buffer                                                     */
/******************************************************************************/

/**
 * @brief Writes formatted output to a dynamically resizeable array
 *
 * This function will write a most `size - 1` bytes, leaving 1 byte for the
 * terminating `\0`.
 *
 * @param strp Will contain the output stream
 * @param format The format string
 * @param ... Parameters to format
 *
 * @returns The number of bytes written. This corresponds to the size of `strp`,
 * including the terminating `\0`.
 */
ssize_t
ft_asprintf(
	char **restrict strp,
	const char *restrict fmt,
	...);
/**
 * @brief Writes formatted output to a dynamically resizeable array
 *
 * This function will write a most `size - 1` bytes, leaving 1 byte for the
 * terminating `\0`.
 *
 * @param strp Will contain the output stream
 * @param format The format string
 * @param ap Parameters to format
 *
 * @returns The number of bytes written. This corresponds to the size of `strp`,
 * including the terminating `\0`.
 */
ssize_t
ft_vasprintf(
	char **restrict strp,
	const char *restrict fmt,
	va_list ap);

/******************************************************************************/
/* Printf stdio                                                               */
/******************************************************************************/

# ifdef FT_PRINTF_USE_STDIO

/**
 * @brief Writes formatted output to stdio's FILE pointer.
 *
 * @param stream FILE pointer to write to
 * @param format The format string
 * @param ... Parameters to format
 *
 * @returns The number of written bytes to `stream`
 */
ssize_t
ft_fprintf(
	FILE *restrict stream,
	const char *restrict format,
	...);
/**
 * @brief Writes formatted output to stdio's FILE pointer.
 *
 * @param stream FILE pointer to write to
 * @param format The format string
 * @param ap Parameters to format
 *
 * @returns The number of written bytes to `stream`
 */
ssize_t
ft_vfprintf(
	FILE *restrict stream,
	const char *restrict format,
	va_list ap);
# endif // FT_PRINTF_USE_STDIO

#endif // FT_PRINTF_H
