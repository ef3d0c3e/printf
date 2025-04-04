#include "printf.h"
#include "args.h"
#include <endian.h>
#include <stdio.h>
#include <stdlib.h>

char
	*ft_strchr(const char *s, int c)
{
	const unsigned char     *mem;

	mem = (const unsigned char *)s;
	while (*mem != (unsigned char)c)
	{
		if (!*mem)
			return (0);
		++mem;
	}
	return ((char *)mem);
}

size_t
	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

static inline int
int_cmp(const int *a, const int *b)
{
	if (*a == -1)
		return (1);
	if (*b == -1)
		return (-1);
	return (*a - *b);
}

static inline void
	dispatch(t_args *args, va_list ap)
{
	int	positionals[4];

	positionals[0] = args->conversion.positional;
	positionals[1] = -1;
	positionals[2] = -1;
	positionals[3] = -1;
	if (positionals[0] == -1) // Do not parse m-th
	{
		if (args->flags.adjust_width.kind  == INT_POSITIONAL)
			positionals[1] = args->flags.adjust_width.value;
		if (args->width.kind  == INT_POSITIONAL)
			positionals[2] = args->width.value;
		if (args->precision.kind  == INT_POSITIONAL)
			positionals[3] = args->precision.value;
	}
	else
	{
		if (args->flags.adjust_width.kind == INT_MTH)
			positionals[1] = args->flags.adjust_width.value;
		if (args->width.kind == INT_MTH)
			positionals[2] = args->width.value;
		if (args->precision.kind == INT_MTH)
			positionals[3] = args->precision.value;
	}
	qsort(positionals, 4, sizeof(int), (int (*)(const void *, const void *))int_cmp);
	printf("Sorted: %d %d %d %d\n", positionals[0], positionals[1], positionals[2], positionals[3]);
	
	size_t i = 1;
	size_t j = 0;
	while (positionals[j] != -1)
	{
		if ((size_t)positionals[j] == i)
		{
			positionals[j] = va_arg(ap, int);
			++j;
		}
		else
			va_arg(ap, int);
		++i;
	}
	va_end(ap);
	printf("Sorted: %d %d %d %d\n", positionals[0], positionals[1], positionals[2], positionals[3]);
}

static inline void
	parse_args(const char **s, va_list list)
{
	t_args		args;
	va_list		cpy;

	printf_parse_positional_conversion(s, &args);
	printf_parse_flags(s, &args);
	args.width = printf_int_parser(s, &args);
	if (**s == '.')
	{
		++(*s);
		args.precision = printf_int_parser(s, &args);
	}
	else
		args.precision = (t_int_value){.kind = INT_LITERAL, .value = 0};
	va_copy(cpy, list);
	dispatch(&args, cpy);
}

ssize_t
	printf_internal(t_buffer *buf, const char *fmt, va_list pa)
{
	const char	*p;
	const char	*s;

	p = fmt;
	while (*p)
	{
		s = ft_strchr(p, '%');
		if (!s)
			break ;
		if (s[1] == '%')
		{
			printf_buffer_write(buf, p, s - p + 1);
			p = s + 2;
		}
		else
		{
			printf_buffer_write(buf, p, s - p);
			p = s + 1;
			parse_args(&p, pa);
			asm("int $3");
		}
	}
	printf_buffer_write(buf, p, ft_strlen(p));
	printf_buffer_flush(buf);
	return (buf->written_bytes);
}
