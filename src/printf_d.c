/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
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
	ll_len(const t_args *args, long long int x)
{
	int	len;

	len = 1;
	len -= (x == 0 && args->precision.value == 0);
	while (x >= 10 || x <= -10)
	{
		++len;
		x /= 10;
	}
	return (len);
}

/** @brief Prints the integer value */
static inline void
	print_value(t_buffer *buf, long long x)
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
	printf_print_lld(
		t_buffer *buf,
		const t_args *args,
		long long int x)
{
	const int	len = ll_len(args, x);
	int			zeroes;
	const int	has_sign = x < 0 || args->flags.sign != SIGN_DEFAULT;

	zeroes = printf_max(0, args->precision.value - len);
	if (args->flags.adjust == ADJUST_ZERO)
	{
		if (args->precision.value != -1)
			zeroes *= (x || args->precision.value != 0);
		else
			zeroes = printf_max(0, args->width.value - has_sign - len);
	}
	if (args->flags.adjust != ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len - zeroes - has_sign);
	printf_buffer_write(buf, &"- +"[(x >= 0) * args->flags.sign],
		(x < 0) || (args->flags.sign != SIGN_DEFAULT));
	printf_pad(buf, '0', zeroes);
	if (args->precision.value || x)
		print_value(buf, x);
	if (args->flags.adjust == ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len - zeroes - has_sign);
}
