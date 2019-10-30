/*
 * Copyright (c) 2019, Emil Renner Berthing
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef putc
#undef putc
#endif

#include "lib/xprintf.h"

/* define these for more functionality
#define PRINTF_ALT
#define PRINTF_O
#define PRINTF_LL
#define PRINTF_LLX
*/

void
xo_putc(const struct xo *xo, char c)
{
	xo->putc(xo, c);
	xo->done(xo);
}

static void
xo__string(const struct xo *xo, const char *s)
{
	char c;

	while ((c = *s++) != '\0')
		xo->putc(xo, c);
}

void
xo_puts(const struct xo *xo, const char *s)
{
	xo__string(xo, s);
	xo->putc(xo, '\n');
	xo->done(xo);
}

#ifdef PRINTF_LL
static void
xo__llu(const struct xo *xo, int width, char pad, unsigned long long v)
{
	char buf[20];
	char *p = buf;

	do {
		*p++ = '0' + (v % 10);
		v /= 10;
		width--;
	} while (v);

	for (; width > 0; width--)
		xo->putc(xo, pad);

	do {
		xo->putc(xo, *--p);
	} while (p > buf);
}

static void
xo__lld(const struct xo *xo, int width, char pad, long long v)
{
	if (v < 0) {
		xo->putc(xo, '-');
		v = -v;
	}
	xo__llu(xo, width, pad, v);
}
#else
static void
xo__u(const struct xo *xo, int width, char pad, unsigned int v)
{
	char buf[10];
	char *p = buf;

	do {
		*p++ = '0' + (v % 10);
		v /= 10;
		width--;
	} while (v);

	for (; width > 0; width--)
		xo->putc(xo, pad);

	do {
		xo->putc(xo, *--p);
	} while (p > buf);
}

static void
xo__d(const struct xo *xo, int width, char pad, int v)
{
	if (v < 0) {
		xo->putc(xo, '-');
		v = -v;
	}
	xo__u(xo, width, pad, v);
}
#endif

#ifdef PRINTF_O
#ifdef PRINTF_LL
static void
xo__llo(const struct xo *xo, int width, char pad, unsigned long long v)
{
	char buf[22];
	char *p = buf;

	do {
		*p++ = '0' + (v & 0x7U);
		v >>= 3;
		width--;
	} while (v);

	for (; width > 0; width--)
		xo->putc(xo, pad);

	do {
		xo->putc(xo, *--p);
	} while (p > buf);
}
#else
static void
xo__o(const struct xo *xo, int width, char pad, unsigned int v)
{
	char buf[11];
	char *p = buf;

	do {
		*p++ = '0' + (v & 0x7U);
		v >>= 3;
		width--;
	} while (v);

	for (; width > 0; width--)
		xo->putc(xo, pad);

	do {
		xo->putc(xo, *--p);
	} while (p > buf);
}
#endif
#endif

static const char Xdigits[] = {
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
};

static const char xdigits[] = {
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
};

#if defined(PRINTF_LL) || defined(PRINTF_LLX)
static void
xo__llx(const struct xo *xo, int width, char pad, const char *digits, unsigned long long v)
{
	char buf[16];
	char *p = buf;

	do {
		*p++ = digits[v & 0xfU];
		v >>= 4;
		width--;
	} while (v);

	for (; width > 0; width--)
		xo->putc(xo, pad);

	do {
		xo->putc(xo, *--p);
	} while (p > buf);
}
#else
static void
xo__x(const struct xo *xo, int width, char pad, const char *digits, unsigned int v)
{
	char buf[8];
	char *p = buf;

	do {
		*p++ = digits[v & 0xfU];
		v >>= 4;
		width--;
	} while (v);

	for (; width > 0; width--)
		xo->putc(xo, pad);

	do {
		xo->putc(xo, *--p);
	} while (p > buf);
}
#endif


void
xo_vprintf(const struct xo *xo, const char *fmt, va_list ap)
{
	unsigned int size;
	int width;
	char pad;
	const char *digits;
#ifdef PRINTF_ALT
	bool alt;
#endif

fmt:
	while (1) {
		char c = *fmt++;

		switch (c) {
		case '\0':
			goto out;
		case '%':
			goto arg;
		}
		xo->putc(xo, c);
	}

arg:
	size = 2;
	width = 0;
	pad = ' ';
#ifdef PRINTF_ALT
	alt = false;
#endif
	while (1) {
		char c = *fmt++;

		switch (c) {
		case '\0':
			goto out;
		case '%':
			xo->putc(xo, '%');
			goto fmt;
#ifdef PRINTF_ALT
		case '#':
			alt = true;
			break;
#endif
		case '0':
			if (width == 0) {
				pad = '0';
				break;
			}
			/* fallthrough */
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			width *= 10;
			width += c - '0';
			break;
		case '*':
			width = va_arg(ap, int);
			break;
		case 'h':
			size -= 1;
			break;
		case 'l':
			size += 1;
			break;
		case 'c':
			xo->putc(xo, va_arg(ap, int));
			goto fmt;
		case 's':
			xo__string(xo, va_arg(ap, const char *));
			goto fmt;
		case 'u':
#ifdef PRINTF_LL
			xo__llu(xo, width, pad,
					(size > 3) ?
					va_arg(ap, unsigned long long) :
					va_arg(ap, unsigned int));
#else
			xo__u(xo, width, pad,
					va_arg(ap, unsigned int));
#endif
			goto fmt;
		case 'd':
		case 'i':
#ifdef PRINTF_LL
			xo__lld(xo, width, pad,
					(size > 3) ?
					va_arg(ap, long long) :
					va_arg(ap, int));
#else
			xo__d(xo, width, pad,
					va_arg(ap, int));
#endif
			goto fmt;
#ifdef PRINTF_O
		case 'o':
#ifdef PRINTF_LL
			xo__llo(xo, width, pad,
					(size > 3) ?
					va_arg(ap, unsigned long long) :
					va_arg(ap, unsigned int));
#else
			xo__o(xo, width, pad,
					va_arg(ap, unsigned int));
#endif
			goto fmt;
#endif
		case 'X':
			digits = Xdigits;
#ifdef PRINTF_ALT
			if (alt) {
				xo->putc(xo, '0');
				xo->putc(xo, 'X');
			}
#endif
			goto common_x;
		case 'x':
			digits = xdigits;
#ifdef PRINTF_ALT
			if (alt) {
				xo->putc(xo, '0');
				xo->putc(xo, 'x');
			}
#endif
		common_x:
#if defined(PRINTF_LL) || defined(PRINTF_LLX)
			xo__llx(xo, width, pad, digits,
					(size > 3) ?
					va_arg(ap, unsigned long long) :
					va_arg(ap, unsigned int));
#else
			xo__x(xo, width, pad, digits,
					va_arg(ap, unsigned int));
#endif
			goto fmt;
		default:
			goto fmt;
		}
	}
out:
	xo->done(xo);
}

struct snprintf {
	struct xo xo;
	char *str;
	char *end;
};

static void snprintf__putc(const struct xo *xo, char c)
{
	struct snprintf *snp = (struct snprintf *)xo;

	if (snp->str < snp->end)
		*snp->str = c;
	snp->str++;
}

static void snprintf__done(const struct xo *xo)
{
	struct snprintf *snp = (struct snprintf *)xo;

	if (snp->str < snp->end)
		*snp->str = '\0';
}

int vsprintf(char *restrict str, const char *restrict fmt, va_list ap)
{
	struct snprintf snp = {
		.xo.putc = snprintf__putc,
		.xo.done = snprintf__done,
		.str = str,
		.end = (char *)~0UL,
	};

	xo_vprintf(&snp.xo, fmt, ap);
	return (uintptr_t)snp.str - (uintptr_t)str;
}

int sprintf(char *restrict str, const char *restrict fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = vsprintf(str, fmt, ap);
	va_end(ap);
	return ret;
}

int vsnprintf(char *restrict str, size_t size, const char *restrict fmt, va_list ap)
{
	struct snprintf snp = {
		.xo.putc = snprintf__putc,
		.xo.done = snprintf__done,
		.str = str,
		.end = str + size,
	};

	xo_vprintf(&snp.xo, fmt, ap);
	return (uintptr_t)snp.str - (uintptr_t)str;
}

int snprintf(char *restrict str, size_t size, const char *restrict fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return ret;
}
