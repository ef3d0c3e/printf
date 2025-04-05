#include <stdio.h>
#include <errno.h>

int
printf_test(const char *fmt, ...);

int
test_errno(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 255; ++i)
	{
		errno = i;
		total += printf_test("%m");
		total += printf_test("%#m");
	}
	return (total);
}
