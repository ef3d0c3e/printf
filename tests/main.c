#include "../src/printf.h"
#include "buffer.h"
#include "util.h"
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/mman.h>

void call(t_buffer *buf, const char *s, ...)
{
	va_list list;
	va_start(list, s);
	printf_internal(buf, s, list);
	va_end(list);
}

ssize_t ft_vdprintf(int fd, const char *fmt, va_list list)
{
	t_buffer	buf;

	printf_buffer_init_fd(&buf, fd, 0);
	printf_internal(&buf, fmt, list);
	printf_buffer_flush(&buf);
	return (buf.written_bytes);
}

static inline int
check_error(int fd0, int fd1, const char *msg)
{
	char	*buf0 = malloc(1024);
	char	*buf1 = malloc(1024);
	size_t	pos0 = 0;
	size_t	pos1 = 0;
	ssize_t	s;

	while (1)
	{
		s = read(fd0, buf0 + pos0, 1024);
		if (s <= 0)
			break ;
		pos0 += s;
		buf0 = printf_realloc(buf0, pos0, pos0 + 1024);
		s = read(fd0, buf0 + pos0, 1024);
	}
	while (1)
	{
		s = read(fd1, buf1 + pos1, 1024);
		if (s <= 0)
			break ;
		pos1 += s;
		buf1 = printf_realloc(buf1, pos1, pos1 + 1024);
		s = read(fd1, buf1 + pos1, 1024);
	}

	int err = 0;
	if (pos1 != pos0)
	{
		dprintf(2, " -- [ Failure ] --\nWHAT: %s\n", msg);
		dprintf(2, "Mismatching sizes: %zu != %zu\n", pos0, pos1);
		write(2, "FD0=`", 5);
		write(2, buf0, pos0);
		write(2, "`\n", 2);
		write(2, "FD1=`", 5);
		write(2, buf1, pos1);
		write(2, "`\n", 2);
		err = 1;
	}
	else if (memcmp(buf0, buf1, pos0))
	{
		dprintf(2, " -- [ Failure ] --\nWHAT: %s\n", msg);
		dprintf(2, "Mismatching content:\n");
		write(2, "FD0=`", 5);
		write(2, buf0, pos0);
		write(2, "`\n", 2);
		write(2, "FD1=`", 5);
		write(2, buf1, pos1);
		write(2, "`\n", 2);
		err = 1;
	}
	free(buf0);
	free(buf1);
	return (err);
}

static inline int
printf_test(const char *fmt, ...)
{
	va_list	list0;
	va_list	list1;
	int		fd0;
	int		fd1;

	fd0 = memfd_create("glibc printf", 0);
	fd1 = memfd_create("custom printf", 0);

	va_start(list0, fmt);
	va_copy(list1, list0);
	vdprintf(fd0, fmt, list0);
	va_end(list0);
	ft_vdprintf(fd1, fmt, list1);
	va_end(list1);
	lseek64(fd0, SEEK_SET, 0);
	lseek64(fd1, SEEK_SET, 0);
	int err = check_error(fd0, fd1, fmt);
	close(fd1);
	close(fd0);
	return (err);
}

int main()
{
	char	buf[255];
	int		total = 0;

	// %d tests
	for (int i = 1; i < 15; ++i)
	{
		for (int k = 0; k < 4; ++k)
		{

			snprintf(buf, 255, "%%%c%dd", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
		}
	}

	for (int i = 1; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dd", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
			}
		}
	}
	dprintf(2, "Failed %d tests\n", total);
	return 0;
}
