#include <limits.h>
#include <stdio.h>

int
printf_test(const char *fmt, ...);

static inline int
test_hex_hhd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhhx", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dhhx", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dhhx", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dhhx", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_hd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhx", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dhx", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dhx", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dhx", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_d(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dx", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dx", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dx", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dx", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_ld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dlx", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dlx", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dlx", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dlx", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_lld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dllx", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dllx", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dllx", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dllx", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_zd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dzx", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dzx", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dzx", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dzx", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_jd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%djx", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%djx", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%djx", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%djx", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_capital_hhd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhhX", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dhhX", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dhhX", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dhhX", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_capital_hd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhX", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dhX", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dhX", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dhX", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_capital_d(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dX", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dX", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dX", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dX", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_capital_ld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dlX", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dlX", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dlX", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dlX", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_capital_lld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dllX", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dllX", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dllX", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dllX", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_capital_zd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dzX", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dzX", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dzX", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dzX", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

static inline int
test_hex_capital_jd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%djX", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%djX", "#0- +"[k], i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%djX", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%djX", "#- +"[k], j, i);
				total += printf_test(buf, 0);
				total += printf_test(buf, 1);
				total += printf_test(buf, -1);
				total += printf_test(buf, 10);
				total += printf_test(buf, -10);
				total += printf_test(buf, 100);
				total += printf_test(buf, -100);
				total += printf_test(buf, 123456);
				total += printf_test(buf, -123456);
				total += printf_test(buf, SCHAR_MIN);
				total += printf_test(buf, SCHAR_MAX);
				total += printf_test(buf, UCHAR_MAX);
				total += printf_test(buf, SHRT_MIN);
				total += printf_test(buf, SHRT_MAX);
				total += printf_test(buf, INT_MIN);
				total += printf_test(buf, INT_MAX);
				total += printf_test(buf, UINT_MAX);
				total += printf_test(buf, LONG_MIN);
				total += printf_test(buf, ULONG_MAX);
				total += printf_test(buf, LONG_LONG_MIN);
				total += printf_test(buf, LONG_LONG_MAX);
				total += printf_test(buf, ULONG_LONG_MAX);
			}
		}
	}
	return (total);
}

int
test_hex(void)
{
	return (
			test_hex_hhd()
			+ test_hex_hd()
			+ test_hex_d()
			+ test_hex_ld()
			+ test_hex_lld()
			+ test_hex_zd()
			+ test_hex_jd()
			+ test_hex_capital_hhd()
			+ test_hex_capital_hd()
			+ test_hex_capital_d()
			+ test_hex_capital_ld()
			+ test_hex_capital_lld()
			+ test_hex_capital_zd()
			+ test_hex_capital_jd()
		   );
}
