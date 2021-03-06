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
	if (s1 != s2 && n > 0) {
		const char *p1 = s1;
		const char *p2 = s2;
		const char *p1end = p1 + n;

		do {
			int a = *p1++;
			int b = *p2++;

			if (a != b)
				return a - b;
		} while (p1 < p1end);
	}

	return 0;
}

void *memset(void *s, int c, size_t n)
{
	if (n > 0) {
		char *p = s;
		char *end = p + n;

		do {
			*p++ = c;
		} while (p < end);
	}

	return s;
}

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	if (n > 0) {
		char *cdest = dest;
		const char *csrc = src;
		const char *cend = csrc + n;

		do {
			*cdest++ = *csrc++;
		} while (csrc < cend);
	}

	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	if (n > 0) {
		char *cdest = dest;
		const char *csrc = src;
		const char *cend = csrc + n;

		if (cdest > csrc && cdest < cend) {
			cdest += n;
			do {
				*--cdest = *--cend;
			} while (csrc < cend);
		} else {
			do {
				*cdest++ = *csrc++;
			} while (csrc < cend);
		}
	}

	return dest;
}

void *memchr(const void *s, int c, size_t n)
{
	if (n > 0) {
		const char *p = s;
		const char *end = p + n;

		do {
			if (*p == c)
				return (void *)p;
			p++;
		} while (p < end);
	}

	return NULL;
}

void *memrchr(const void *s, int c, size_t n)
{
	if (n > 0) {
		const char *start = s;
		const char *p = start + n;

		do {
			p--;
			if (*p == c)
				return (void *)p;
		} while (p > start);
	}

	return NULL;
}

void *rawmemchr(const void *s, int c)
{
	const char *p = s;

	while (*p != c)
		p++;

	return (void *)p;
}

size_t strlen(const char *s)
{
	const char *p = s;
	char c;

	do {
		c = *p++;
	} while (c != '\0');

	return (uintptr_t)p - (uintptr_t)s - 1;
}

size_t strnlen(const char *s, size_t maxlen)
{
	const char *p = s;
	const char *end = s + maxlen;
	char c;

	do {
		c = *p++;
	} while (c != '\0' && p < end);

	return (uintptr_t)p - (uintptr_t)s - 1;
}

int strcmp(const char *s1, const char *s2)
{
	int a, b;

	do {
		a = *s1++;
		b = *s2++;
	} while (a == b && a != '\0');

	return a - b;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > 0) {
		const char *s1end = s1 + n;
		int a, b;

		do {
			a = *s1++;
			b = *s2++;
			if (a != b)
				return a - b;
		} while (a != '\0' && s1 < s1end);
	}

	return 0;
}

char *strcpy(char *restrict dest, const char *restrict src)
{
	char *p = dest;
	char c;

	do {
		c = *src++;
		*p++ = c;
	} while (c != '\0');

	return dest;
}

char *strncpy(char *restrict dest, const char *restrict src, size_t n)
{
	if (n > 0) {
		const char *end = src + n;
		char *p = dest;
		char c;

		do {
			c = *src++;
			*p++ = c;
		} while (c != '\0' && src < end);
	}

	return dest;
}

char *stpcpy(char *restrict dest, const char *restrict src)
{
	char c;

	do {
		c = *src++;
		*dest++ = c;
	} while (c != '\0');

	return dest;
}

char *stpncpy(char *restrict dest, const char *restrict src, size_t n)
{
	if (n > 0) {
		const char *end = src + n;
		char c;

		do {
			c = *src++;
			*dest++ = c;
		} while (c != '\0' && src < end);
	}

	return dest;
}

char *strcat(char *restrict dest, const char *restrict src)
{
	char *p = dest;
	char c;

	while (*p != '\0')
		p++;

	do {
		c = *src++;
		*p++ = c;
	} while (c != '\0');

	return dest;
}

char *strncat(char *restrict dest, const char *restrict src, size_t n)
{
	if (n > 0) {
		const char *end = src + n;
		char *p = dest;
		char c;

		while (*p != '\0')
			p++;

		do {
			c = *src++;
			*p++ = c;
			if (c == '\0')
				goto out;
		} while (src < end);

		*p = '\0';
	}

out:
	return dest;
}

char *strchr(const char *s, int c)
{
	int b;

	do {
		b = *s;
		if (b == c)
			return (char *)s;
		s++;
	} while (b != '\0');

	return NULL;
}

char *strrchr(const char *s, int c)
{
	char *ret = NULL;
	int b;

	do {
		b = *s;
		if (b == c)
			ret = (char *)s;
		s++;
	} while (b != '\0');

	return ret;
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
