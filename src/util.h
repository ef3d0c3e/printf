/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTIL_H
# define UTIL_H

# include "buffer.h"

/******************************************************************************/
/* Memory utilities                                                           */
/******************************************************************************/

# ifdef __clang__

typedef char	t_char16 __attribute__((ext_vector_type(16), aligned(1)));
typedef char	t_char32 __attribute__((ext_vector_type(32), aligned(1)));
# else

typedef char	t_char16 __attribute__((vector_size(16), aligned(1)));
typedef char	t_char32 __attribute__((vector_size(32), aligned(1)));
# endif // __clang__

/**
 * @brief Memcpy function for aligned memory
 *
 * @note The bahaviour of this functyion is undefined if `[src, src+n]` overlaps
 * with `[dest, dest+n]` or if src and dest are not suitably aligned.
 *
 * @param dest Destination buffer
 * @param src Source buffer
 * @param n Number of bytes to copy from `src` into `dest`
 *
 * @returns `dest`
 */
void
*printf_memcpy_aligned(void *dest, const void *src, size_t n);
/**
 * @brief Memcpy function for unaligned pointers
 *
 * @note The bahaviour of this functyion is undefined if `[src, src+n]` overlaps
 * with `[dest, dest+n]`.
 *
 * @param dest Destination buffer
 * @param src Source buffer
 * @param n Number of bytes to copy from `src` into `dest`
 *
 * @returns `dest`
 */
void
*printf_memcpy_unaligned(void *dest, const void *src, size_t n);
/**
 * @brief Reallocates `ptr` for fit at least `new_size`
 *
 * @param ptr Buffer to reallocate
 * @param original_size Original size of the buffer
 * @param new_size Size wanted
 *
 * @returns `ptr` if `original_size` <= `new_size`, otherwise a newly allocated
 * buffer that can hold at least `new_size` while copying over the first
 * `original_size` bytes from `ptr`. If malloc fails, no copying happens and
 * a NULL pointer is returned.
 */
void
*printf_realloc(void *ptr, size_t original_size, size_t new_size);

/******************************************************************************/
/* String utilities                                                           */
/******************************************************************************/

/**
 * @brief Strchr function
 *
 * @param s String to search
 * @param c Character to search in `s`
 *
 * @returns The first substring of `s` starting with `c`. NULL if not found
 */
char
*printf_strchr(const char *s, int c);
/**
 * @brief Strlen function
 *
 * @param s String to get the length of
 *
 * @returns The length of s
 */
size_t
printf_strlen(const char *s);
/**
 * @brief Compare and advance utility
 *
 * Compares `p` with `s`, if `s` is contained at the start of `p`, `p` is
 * advanced by `strlen(s)`.
 *
 * @param p String to search and advance
 * @param s String to find
 *
 * @returns 1 If `p` starts with `s`.
 */
int
printf_compare(const char **p, const char *s);

/******************************************************************************/
/* Arithmetic utilities                                                       */
/******************************************************************************/

/**
 * @brief Gets the minimum of two integer values
 *
 * @param a First integer value
 * @param b Second integer value
 *
 * @returns `a` if `a <= b`, otherwise `b`
 */
int
printf_min(int a, int b);
/**
 * @brief Gets the minimum of two integer values
 *
 * @param a First integer value
 * @param b Second integer value
 *
 * @returns `a` if `a <= b`, otherwise `b`
 */
int
printf_max(int a, int b);

/******************************************************************************/
/* Printing utilities                                                         */
/******************************************************************************/

/**
 * @brief Prints a repeated character
 *
 * @param buf Buffer to print into
 * @param pad Character to print
 * @param len Number of times to print `pad` in `buf`. Nothing is printed when
 * `len <= 0`
 */
void
printf_pad(t_buffer *buf, char pad, int len);

#endif // UTIL_H
