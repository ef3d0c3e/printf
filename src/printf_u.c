/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

/** @brief Gets total length, with formatting applied */
static inline int
	ull_len(const t_args *args, unsigned long long int x)
{
	int	len;

	len = 1;
	len -= (x == 0) && (args->precision.value == 0);
	while (x >= 10)
	{
		++len;
		x /= 10;
	}
	if (args->precision.value != -1 && len < args->precision.value)
		len = args->precision.value;
	return (len);
}

/** @brief Gets the length of integer value (no formatting or sign) */
static inline int
	ull_len_abs(unsigned long long int x)
{
	int	len;

	len = 1;
	while (x >= 10)
	{
		++len;
		x /= 10;
	}
	return (len);
}

/** @brief Prints the integer value */
static inline void
	print_value(t_buffer *buf, unsigned long long x)
{
	if (!x)
		printf_buffer_write(buf, "0", 1);
	if (x >= 10)
		print_value(buf, x / 10);
	if (x)
		printf_buffer_write(buf, &"0123456789"[(x % 10)], 1);
}

void
	printf_print_ull(
		t_buffer *buf,
		const t_args *args,
		unsigned long long int x)
{
	const int	len = ull_len(args, x);
	int			zeroes;

	if (args->flags.adjust == ADJUST_RIGHT)
		printf_pad(buf, ' ', args->width.value - len);
	zeroes = printf_max(0, args->precision.value);
	if (args->flags.adjust == ADJUST_ZERO && args->precision.value == -1)
		zeroes = printf_max(zeroes, args->width.value);
	printf_pad(buf, '0', zeroes - ull_len_abs(x));
	if (args->precision.value || x)
		print_value(buf, x);
	if (args->flags.adjust == ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len);
}
