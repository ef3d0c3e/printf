#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static inline int
do_test(size_t size, const char *fmt, ...)
{
	va_list	list0;
	va_list	list1;
	char *buf0 = malloc(size + 1);
	char *buf1 = malloc(size + 1);
	
	va_start(list0, fmt);
	va_copy(list1, list0);
	ssize_t pos0 = vsnprintf(buf0, size, fmt, list0);
	size_t sz0 = strnlen(buf0, size);
	ssize_t pos1 = ft_vsnprintf(buf1, size, fmt, list1);
	size_t sz1 = strnlen(buf1, size);
	va_end(list0);
	va_end(list1);

	int err = 0;
	if (pos1 != pos0)
	{
		dprintf(2, " -- [ Failure ] --\nWHAT: %s\n", fmt);
		dprintf(2, "Mismatching return values: %zu != %zu\n", pos0, pos1);
		write(2, "glibc =`", 8);
		write(2, buf0, sz0);
		write(2, "`\n", 2);
		write(2, "custom=`", 8);
		write(2, buf1, sz1);
		write(2, "`\n", 2);
		err = 1;
	}
	if (sz1 != sz0)
	{
		dprintf(2, " -- [ Failure ] --\nWHAT: %s\n", fmt);
		dprintf(2, "Mismatching sizes: %zu != %zu\n", pos0, pos1);
		write(2, "glibc =`", 8);
		write(2, buf0, sz0);
		write(2, "`\n", 2);
		write(2, "custom=`", 8);
		write(2, buf1, sz1);
		write(2, "`\n", 2);
		err = 1;
	}
	if (memcmp(buf0, buf1, sz0))
	{
		dprintf(2, " -- [ Failure ] --\nWHAT: %s\n", fmt);
		dprintf(2, "Mismatching content:\n");
		write(2, "glibc `", 8);
		write(2, buf0, sz0);
		write(2, "`\n", 2);
		write(2, "custom=`", 8);
		write(2, buf1, sz1);
		write(2, "`\n", 2);
		err = 1;
	}
	if (sz1 && buf1[sz1])
	{
		dprintf(2, " -- [ Failure ] --\nWHAT: %s\n", fmt);
		dprintf(2, "Missing `\\0` %zd:\n", pos1);
		write(2, "glibc `", 8);
		write(2, buf0, sz0);
		write(2, "`\n", 2);
		write(2, "custom=`", 8);
		write(2, buf1, sz1);
		write(2, "`\n", 2);
		err = 1;
	}
	free(buf0);
	free(buf1);
	return (!err);
}

int
test_ext_buffer(void)
{
	int		total = 0;
	char	buf[255];
	for (int i = 0; i < 255; ++i)
	{
		total += do_test(i, "Hello %s", "World");
		total += do_test(i, "%s%s%s", "World", "Lorem ipsum dolor sit amet", "0123456789");
		total += do_test(i, "%3$s%2$s%3$s", "World", "Lorem ipsum dolor sit amet", "0123456789");
		for (int j = 1; j <= 5; ++j)
		{
			sprintf(buf, "%%%d$s", j);
			total += do_test(i, buf, NULL, "", "foo", "bar", "baz");
		}
	}
	return (total);
}
