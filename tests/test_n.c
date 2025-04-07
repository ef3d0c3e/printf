#include "../includes/ft_printf.h"
#include "../src/util.h"
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/mman.h>


int
check_error(int fd0, int fd1, const char *msg);

static inline int
do_test(int *val, const char *fmt, ...)
{
	va_list	list0;
	va_list	list1;
	int		fd0;
	int		fd1;

	fd0 = memfd_create("glibc printf", 0);
	fd1 = memfd_create("custom printf", 0);

	va_start(list0, fmt);
	va_copy(list1, list0);
	*val = 0;
	vdprintf(fd0, fmt, list0);
	int val0 = *val;
	*val = 0;
	ft_vdprintf(fd1, fmt, list1);
	int val1 = *val;
	va_end(list0);
	va_end(list1);
	lseek64(fd0, SEEK_SET, 0);
	lseek64(fd1, SEEK_SET, 0);
	int err = check_error(fd0, fd1, fmt);
	if (val0 != val1)
	{
		dprintf(2, " -- [ Failure ] --\nWHAT: %s\n", fmt);
		dprintf(2, "Mismatching pointers: %d != %d\n", val0, val1);
		err = 1;
	}
	close(fd1);
	close(fd0);
	return (err);
}

int
test_n(void)
{
	char	buf[255];
	int		total = 0;
	int		val;

	total += do_test(&val, "%n", &val);
	for (int i = 0; i < 254; ++i)
	{
		buf[i] = "0123456789"[i];
		buf[i + 1] = 0;
		total += do_test(&val, "%.*s%n%.*s", i, buf, &val, i/2, buf);
		total += do_test(&val, "%2$*3$s%1$n%4$*5$s", &val, buf, i / 2, buf, i / 4);
	}
	return (total);
}
