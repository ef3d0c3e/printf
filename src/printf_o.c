/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "util.h"

/** @brief Gets total length, with formatting applied */
static inline int
	ull_len(const t_args *args, unsigned long long int x)
{
	int	len;

	len = 1;
	len -= (x == 0) && (args->precision.value == 0 && !args->flags.alternate);
	while (x >= 8)
	{
		++len;
		x /= 8;
	}
	if (args->precision.value != -1 && len < args->precision.value)
		len = args->precision.value;
	return (len);
}

/** @brief Gets the length of integer value (no formatting) */
static inline int
	ull_len_abs(unsigned long long int x)
{
	int	len;

	len = 1;
	while (x >= 8)
	{
		++len;
		x /= 8;
	}
	return (len);
}

/** @brief Prints the integer value */
static inline void
	print_value(t_buffer *buf, unsigned long long int x)
{
	static const char	*set = "01234567";

	if (!x)
		printf_buffer_write(buf, set, 1);
	if (x >= 8)
		print_value(buf, x / 8);
	if (x)
		printf_buffer_write(buf, &set[(x % 8)], 1);
}

void
	printf_print_llo(
		t_buffer *buf,
		const t_args *args,
		unsigned long long int x)
{
	const int	len = ull_len(args, x);
	int			zeroes;

	zeroes = printf_max(0, args->precision.value);
	if (args->flags.adjust == ADJUST_ZERO && args->precision.value == -1)
		zeroes = printf_max(zeroes, args->width.value);
	if (args->flags.adjust == ADJUST_RIGHT)
		printf_pad(buf, ' ', args->width.value - len
			- (args->flags.alternate && x && zeroes - ull_len_abs(x) <= 0));
	if (args->flags.alternate && ((x && zeroes - ull_len_abs(x) <= 0)
			|| (!x && args->precision.value == 0)))
		printf_buffer_write(buf, "0", 1);
	printf_pad(buf, '0', zeroes - ull_len_abs(x));
	if (args->precision.value || x)
		print_value(buf, x);
	if (args->flags.adjust == ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len);
}
