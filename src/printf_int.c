/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
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
	int_len(const t_args *args, int x)
{
	int	len;
	int	has_sign;

	len = 1;
	has_sign = x < 0 || args->flags.sign != SIGN_DEFAULT;
	while (x >= 10 || x <= -10)
	{
		++len;
		x /= 10;
	}
	if (len < args->precision.value)
		len = args->precision.value;
	return (len + has_sign);
}

/** @brief Gets the length of integer value (no formatting or sign) */
static inline int
	int_len_abs(int x)
{
	int	len;

	len = 1;
	while (x >= 10 || x <= -10)
	{
		++len;
		x /= 10;
	}
	return (len);
}

/** @brief Prints the integer value */
static inline void
	print_value(t_buffer *buf, int x)
{
	if (!x)
		printf_buffer_write(buf, "0", 1);
	if (x >= 10 || x <= -10)
		print_value(buf, x / 10);
	if (x > 0)
		printf_buffer_write(buf, &"0123456789"[(x % 10)], 1);
	if (x < 0)
		printf_buffer_write(buf, &"0123456789"[-(x % 10)], 1);
}

void
	printf_print_int(
		t_buffer *buf,
		const t_args *args,
		int x)
{
	const int	len = int_len(args, x);
	int			zeroes;

	if (args->flags.adjust == ADJUST_RIGHT)
		printf_pad(buf, ' ', args->width.value - len);
	printf_buffer_write(buf, &"- +"[(x >= 0) * args->flags.sign],
		(x < 0) || (args->flags.sign != SIGN_DEFAULT));
	zeroes = args->precision.value;
	if (args->flags.adjust == ADJUST_ZERO && !args->precision.value)
	{
		zeroes = printf_max(zeroes, args->width.value);
		zeroes -= (x < 0) || (args->flags.sign != SIGN_DEFAULT);
	}
	printf_pad(buf, '0', zeroes - int_len_abs(x));
	print_value(buf, x);
	if (args->flags.adjust == ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len);
}
