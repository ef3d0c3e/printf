#include <limits.h>
#include <stdio.h>

int
printf_test(const char *fmt, ...);

static inline int
test_decimal_hhd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhhd", i);
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
			snprintf(buf, 255, "%%%c%dhhd", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dhhd", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dhhd", "#- +"[k], j, i);
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
test_decimal_hd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhd", i);
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
			snprintf(buf, 255, "%%%c%dhd", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dhd", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dhd", "#- +"[k], j, i);
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
test_decimal_d(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dd", i);
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
			snprintf(buf, 255, "%%%c%dd", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dd", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dd", "#- +"[k], j, i);
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
test_decimal_ld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dld", i);
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
			snprintf(buf, 255, "%%%c%dld", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dld", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dld", "#- +"[k], j, i);
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
test_decimal_lld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dlld", i);
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
			snprintf(buf, 255, "%%%c%dlld", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dlld", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dlld", "#- +"[k], j, i);
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
test_decimal_jd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%djd", i);
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
			snprintf(buf, 255, "%%%c%djd", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%djd", j, i);
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
				snprintf(buf, 255, "%%%c%d.%djd", "#- +"[k], j, i);
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
test_decimal_zd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dzd", i);
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
			snprintf(buf, 255, "%%%c%dzd", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dzd", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dzd", "#- +"[k], j, i);
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
test_decimal_hhu(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhhu", i);
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
			snprintf(buf, 255, "%%%c%dhhu", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dhhu", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dhhu", "#- +"[k], j, i);
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
test_decimal_hu(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhu", i);
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
			snprintf(buf, 255, "%%%c%dhu", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dhu", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dhu", "#- +"[k], j, i);
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
test_decimal_u(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%du", i);
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
			snprintf(buf, 255, "%%%c%du", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%du", j, i);
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
				snprintf(buf, 255, "%%%c%d.%du", "#- +"[k], j, i);
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
test_decimal_lu(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dlu", i);
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
			snprintf(buf, 255, "%%%c%dlu", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dlu", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dlu", "#- +"[k], j, i);
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
test_decimal_llu(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dllu", i);
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
			snprintf(buf, 255, "%%%c%dllu", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dllu", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dllu", "#- +"[k], j, i);
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
test_decimal_zu(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dzu", i);
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
			snprintf(buf, 255, "%%%c%dzu", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dzu", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dzu", "#- +"[k], j, i);
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
test_decimal_ju(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dju", i);
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
			snprintf(buf, 255, "%%%c%dju", "#0- +"[k], i);
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
			snprintf(buf, 255, "%%%d.%dju", j, i);
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
				snprintf(buf, 255, "%%%c%d.%dju", "#- +"[k], j, i);
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
test_decimal(void)
{
	return (
			test_decimal_hhd()
			+ test_decimal_hd()
			+ test_decimal_d()
			+ test_decimal_ld()
			+ test_decimal_lld()
			+ test_decimal_zd()
			+ test_decimal_jd()
			+ test_decimal_hhu()
			+ test_decimal_hu()
			+ test_decimal_u()
			+ test_decimal_lu()
			+ test_decimal_llu()
			+ test_decimal_zu()
			+ test_decimal_ju()
		   );
}
