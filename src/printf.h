/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H

# include "buffer.h"
# include "args.h"
# include "util.h"

/**
 * @brief Internal printf function
 *
 * @param buf Write buffer
 * @param format Format string
 * @param args Arguments
 *
 * @returns The number of written bytes
 */
ssize_t
printf_internal(t_buffer *buf, const char *format, va_list args);

/** @brief `int` printing: `d` or `i` */
void
printf_print_int(t_buffer *buf, const t_args *args, int value);

#endif // PRINTF_H
