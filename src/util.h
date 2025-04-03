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

# include <stdlib.h>
# include <stdint.h>

# ifdef __clang__

typedef char	t_char32 __attribute__((ext_vector_type(32), aligned(1)));
# else

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
 * `original_size` bytes from `ptr`
 */
void
*printf_realloc(void *ptr, size_t original_size, size_t new_size);

#endif // UTIL_H
