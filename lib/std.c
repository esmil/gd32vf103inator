/*
 * Copyright (c) 2019-2020, Emil Renner Berthing
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
#include <string.h>
#include <stdio.h>

/* define these for more functionality
#define PRINTF_ALT
#define PRINTF_O
#define PRINTF_LL
#define PRINTF_LLX
*/

FILE *stdout;
FILE *stderr;

int memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	if (s1 == s2)
		return 0;

	p1 = s1;
	p2 = s2;
	for (size_t i = 0; i < n; i++) {
		int a = p1[i];
		int b = p2[i];

		if (a != b)
			return a - b;
	}

	return 0;
}

void *memset(void *s, int c, size_t n)
{
	unsigned char *dest = s;
	unsigned char *end = dest + n;

	while (dest < end) {
		*dest = c;
		dest++;
	}

	return s;
}

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char *cdest = dest;
	const char *csrc = src;

	for (; n; n--)
		*cdest++ = *csrc++;

	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	char *cdest = dest;
	const char *csrc = src;

	if (cdest > csrc && cdest < csrc + n) {
		cdest += n;
		csrc += n;
		for (; n; n--)
			*--cdest = *--csrc;
	} else {
		for (; n; n--)
			*cdest++ = *csrc++;
	}

	return dest;
}

size_t strlen(const char *s)
{
	const char *e = s;

	while (*e != '\0')
		e++;

	return (uintptr_t)e - (uintptr_t)s;
}

int strcmp(const char *s1, const char *s2)
{
	int a;
	int b;

	do {
		a = *s1++;
		b = *s2++;
	} while (a == b && a != '\0');

	return a - b;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	int a;
	int b;

	if (n == 0)
		return 0;

	for (size_t i = 0; i < n; i++) {
		a = s1[i];
		b = s2[i];
		if (a != b || a == '\0')
			break;
	}

	return a - b;
}

char *strchr(const char *s, int c)
{
	while (1) {
		int b = *s;

		if (b == c)
			return (char *)s;
		if (b == '\0')
			return NULL;

		s++;
	}
}

char *strrchr(const char *s, int c)
{
	char *ret = NULL;

	while (1) {
		int b = *s;

		if (b == c)
			ret = (char *)s;
		if (b == '\0')
			return ret;

		s++;
	}
}

int fputc(int c, FILE *stream)
{
	stream->putc(stream, c);
	return stream->done(stream);
}

int fputs(const char *s, FILE *stream)
{
	char c;

	while ((c = *s++) != '\0')
		stream->putc(stream, c);

	stream->putc(stream, '\n');

	return stream->done(stream);
}

static void
printf_string(FILE *stream, const char *s)
{
	char c;

	while ((c = *s++) != '\0')
		stream->putc(stream, c);
}

#ifdef PRINTF_LL
static void
printf_llu(FILE *stream, int width, char pad, unsigned long long v)
{
	char buf[20];
	char *p = buf;

	do {
		*p++ = '0' + (v % 10);
		v /= 10;
		width--;
	} while (v);

	for (; width > 0; width--)
		stream->putc(stream, pad);

	do {
		stream->putc(stream, *--p);
	} while (p > buf);
}

static void
printf_lld(FILE *stream, int width, char pad, long long v)
{
	if (v < 0) {
		stream->putc(stream, '-');
		v = -v;
	}
	printf_llu(stream, width, pad, v);
}
#else
static void
printf_u(FILE *stream, int width, char pad, unsigned int v)
{
	char buf[10];
	char *p = buf;

	do {
		*p++ = '0' + (v % 10);
		v /= 10;
		width--;
	} while (v);

	for (; width > 0; width--)
		stream->putc(stream, pad);

	do {
		stream->putc(stream, *--p);
	} while (p > buf);
}

static void
printf_d(FILE *stream, int width, char pad, int v)
{
	if (v < 0) {
		stream->putc(stream, '-');
		v = -v;
	}
	printf_u(stream, width, pad, v);
}
#endif

#ifdef PRINTF_O
#ifdef PRINTF_LL
static void
printf_llo(FILE *stream, int width, char pad, unsigned long long v)
{
	char buf[22];
	char *p = buf;

	do {
		*p++ = '0' + (v & 0x7U);
		v >>= 3;
		width--;
	} while (v);

	for (; width > 0; width--)
		stream->putc(stream, pad);

	do {
		stream->putc(stream, *--p);
	} while (p > buf);
}
#else
static void
printf_o(FILE *stream, int width, char pad, unsigned int v)
{
	char buf[11];
	char *p = buf;

	do {
		*p++ = '0' + (v & 0x7U);
		v >>= 3;
		width--;
	} while (v);

	for (; width > 0; width--)
		stream->putc(stream, pad);

	do {
		stream->putc(stream, *--p);
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
printf_llx(FILE *stream, int width, char pad, const char *digits, unsigned long long v)
{
	char buf[16];
	char *p = buf;

	do {
		*p++ = digits[v & 0xfU];
		v >>= 4;
		width--;
	} while (v);

	for (; width > 0; width--)
		stream->putc(stream, pad);

	do {
		stream->putc(stream, *--p);
	} while (p > buf);
}
#else
static void
printf_x(FILE *stream, int width, char pad, const char *digits, unsigned int v)
{
	char buf[8];
	char *p = buf;

	do {
		*p++ = digits[v & 0xfU];
		v >>= 4;
		width--;
	} while (v);

	for (; width > 0; width--)
		stream->putc(stream, pad);

	do {
		stream->putc(stream, *--p);
	} while (p > buf);
}
#endif


int vfprintf(FILE *stream, const char *fmt, va_list ap)
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
		stream->putc(stream, c);
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
			stream->putc(stream, '%');
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
			stream->putc(stream, va_arg(ap, int));
			goto fmt;
		case 's':
			printf_string(stream, va_arg(ap, const char *));
			goto fmt;
		case 'u':
#ifdef PRINTF_LL
			printf_llu(stream, width, pad,
					(size > 3) ?
					va_arg(ap, unsigned long long) :
					va_arg(ap, unsigned int));
#else
			printf_u(stream, width, pad,
					va_arg(ap, unsigned int));
#endif
			goto fmt;
		case 'd':
		case 'i':
#ifdef PRINTF_LL
			printf_lld(stream, width, pad,
					(size > 3) ?
					va_arg(ap, long long) :
					va_arg(ap, int));
#else
			printf_d(stream, width, pad,
					va_arg(ap, int));
#endif
			goto fmt;
#ifdef PRINTF_O
		case 'o':
#ifdef PRINTF_LL
			printf_llo(stream, width, pad,
					(size > 3) ?
					va_arg(ap, unsigned long long) :
					va_arg(ap, unsigned int));
#else
			printf_o(stream, width, pad,
					va_arg(ap, unsigned int));
#endif
			goto fmt;
#endif
		case 'X':
			digits = Xdigits;
#ifdef PRINTF_ALT
			if (alt) {
				stream->putc(stream, '0');
				stream->putc(stream, 'X');
			}
#endif
			goto common_x;
		case 'x':
			digits = xdigits;
#ifdef PRINTF_ALT
			if (alt) {
				stream->putc(stream, '0');
				stream->putc(stream, 'x');
			}
#endif
		common_x:
#if defined(PRINTF_LL) || defined(PRINTF_LLX)
			printf_llx(stream, width, pad, digits,
					(size > 3) ?
					va_arg(ap, unsigned long long) :
					va_arg(ap, unsigned int));
#else
			printf_x(stream, width, pad, digits,
					va_arg(ap, unsigned int));
#endif
			goto fmt;
		default:
			goto fmt;
		}
	}
out:
	return stream->done(stream);
}

int fprintf(FILE *stream, const char *restrict fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = vfprintf(stream, fmt, ap);
	va_end(ap);
	return ret;
}

int putchar(int c)
{
	return fputc(c, stdout);
}

int puts(const char *s)
{
	return fputs(s, stdout);
}

int vprintf(const char *restrict fmt, va_list ap)
{
	return vfprintf(stdout, fmt, ap);
}

int printf(const char *restrict fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = vprintf(fmt, ap);
	va_end(ap);
	return ret;
}

struct snprintf {
	FILE stream;
	char *str;
	char *end;
};

static void snprintf_putc(FILE *stream, char c)
{
	struct snprintf *snp = (struct snprintf *)stream;

	if (snp->str < snp->end)
		*snp->str = c;
	snp->str++;
}

static int snprintf_done(FILE *stream)
{
	struct snprintf *snp = (struct snprintf *)stream;

	if (snp->str < snp->end)
		*snp->str = '\0';

	return 0;
}

int vsprintf(char *restrict str, const char *restrict fmt, va_list ap)
{
	struct snprintf snp = {
		.stream.putc = snprintf_putc,
		.stream.done = snprintf_done,
		.str = str,
		.end = (char *)~0UL,
	};

	vfprintf(&snp.stream, fmt, ap);
	return snp.str - str;
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
		.stream.putc = snprintf_putc,
		.stream.done = snprintf_done,
		.str = str,
		.end = str + size,
	};

	vfprintf(&snp.stream, fmt, ap);
	return snp.str - str;
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
