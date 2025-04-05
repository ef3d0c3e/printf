#include "../includes/ft_printf.h"
#include "../src/util.h"
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/mman.h>


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

int
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
	ft_vdprintf(fd1, fmt, list1);
	va_end(list0);
	va_end(list1);
	lseek64(fd0, SEEK_SET, 0);
	lseek64(fd1, SEEK_SET, 0);
	int err = check_error(fd0, fd1, fmt);
	close(fd1);
	close(fd0);
	return (err);
}

int
test_ext_buffer(void);
int
test_internal_buffer(void);
int
test_str(void);
int
test_decimal(void);
int
test_hex(void);
int
test_octal(void);
int
test_errno(void);

int main(void)
{
	int	total = 0;

	total += test_ext_buffer();
	total += test_internal_buffer();
	total += test_str();
	total += test_decimal();
	total += test_hex();
	total += test_octal();
	total += test_errno();
	dprintf(2, "Failed %d/711648 tests\n", total);
	return 0;
}
